#!/bin/bash
## v.0.9

## MAY NEED DPKG-REPACK IN CASE OF BACKING UP INSTALLED DEBS	
## aptitude search '~i~o' | awk '{print $2}' | sudo xargs dpkg-repack

## -- VARS -- ##
PROG_FLNAME="`lsb_release -i | awk '{print $3}'`_`uname -m`_`date +%Y%m%d%H%M%S`"
PROG_OUTPUT=$PROG_FLNAME.packlist
REPO_OUTPUT=$PROG_FLNAME.repolist
REPO_DIR_OUTPUT=$REPO_OUTPUT\_dir.tar.gz
ARCHIEVE=$PROG_FLNAME.tar.gz

## loop to test out the given parameter
while [ 1 ]; do
	if [[ "$1" = "--source-dir" || "$1" = "-sd" ]]; then
		shift; 
		SOURCE="$1/$ARCHIEVE"
	elif [ -z "$1" ]; then
		break # exit loop when parameters are over 
	fi
	shift
done

echo "Backing up:"

## [dpkg --get-selections]
echo "-> list of packages... "
dpkg --get-selections > $PROG_OUTPUT

## [/etc/apt/sources.list]
echo "-> list of repositories... "
cat /etc/apt/sources.list > $REPO_OUTPUT

## [/etc/apt/sources.list.d/]
echo "-> sources list directory... "
LIST=`find /etc/apt/sources.list.d | grep 'list$' `
for ONE in $LIST; do
	LOCAL=`basename $ONE`
	touch $LOCAL
	cat $ONE > $LOCAL
done

# Backed up repos w/o passwd. LOL
mkdir repo_dir
mv *.list repo_dir/
tar -czf $REPO_DIR_OUTPUT repo_dir/  
rm -r repo_dir

## sudo tar -czPf $REPO_DIR_OUTPUT /etc/apt/sources.list.d

## [$SOURCE]
echo "-> global archieve... "
tar -czf $SOURCE $PROG_OUTPUT $REPO_OUTPUT $REPO_DIR_OUTPUT
echo "Grab $SOURCE."

## [CLEAN UP]
rm -f $PROG_OUTPUT $REPO_OUTPUT $REPO_DIR_OUTPUT
