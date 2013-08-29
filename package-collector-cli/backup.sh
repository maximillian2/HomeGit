#!/bin/bash

## -- VARS -- ##
PROG_FLNAME="`lsb_release -i | awk '{print $3}'`_`uname -m`_`date +%Y%m%d%H%M%S`"
PROG_OUTPUT=$PROG_FLNAME.packlist
REPO_OUTPUT=$PROG_FLNAME.repolist
REPO_DIR_OUTPUT=$REPO_OUTPUT\_dir.tar.gz
ARCHIEVE=$PROG_FLNAME.tar.gz
OBS_DEBS_DIR=$PROG_FLNAME\_obs_debs
OBS_DEBS_ARCHIEVE=$OBS_DEBS_DIR.tar.gz

## -- FUNCS -- ##
function opts {
	echo "
OPTIONS:	 
-sd DIR, --source-dir DIR  
	absolute path to archieve destination
-h, --help
	print help and exit
-v, --verbose
	verbose mode
-mod, --make-obsolete-debs
    make debs from .deb installed packages"
}
function usage {
	echo "USAGE: $0 [OPTIONS]"
}
function description {
	echo -e "
DESCRIPTION

This program backs up local repos and packages to archieve
which you can easily transfer to another machine and restoref
it with another script called restore.sh. It should be included
into folder with backup.sh. 
			"
##In future restore.sh and backup.sh will be one script. 
}
function 

## if no parameters given, exit.
if [[ "$#" -eq "0" ]]; then
	usage; opts
	exit 1
fi

## loop to test out all the given parameters
while [ 1 ]; do
	if [[ "$1" = "--source-dir" || "$1" = "-sd" ]]; then
		shift
		if [ ! -d "$1" ]; then 		## if $1 is not a directory
			if [ -f "$1" ]; then 	    ## but file
				rm $1			    	## remove file
			fi
		else
			if [ -w "$1" ]; then  	    ## whether destination directory is writable
				mkdir -p $1		    	## create it 
			else 
				echo "Permission denied." 1>&2
				exit 1
			fi	
		fi 
	SOURCE="$1/$ARCHIEVE" ## final path			
	elif [[ "$1" = "--help" || "$1" = "-h" ]]; then 
		usage; opts; description
		exit 1
	elif [[ "$1" = "--verbose" || "$1" = "-v" ]]; then
		verboseYes=1
	elif [[ "$1" = "--make-obsolete-debs" || "$1" = "-mod" ]]; then
		mkdir -p "$OBS_DEBS_DIR"
		cd $OBS_DEBS_DIR &&
		aptitude search '~i~o' | awk '{print $2}' | sudo xargs dpkg-repack &&
		cd ../
		make_debs=1
	elif [ -z "$1" ]; then
		break # exit loop when parameters are over 
	else 
		echo -e "Error: unknown key. \nSee --help for available options." 1>&2
		exit 1
	fi
	shift
done

echo "Backing up:"

## [dpkg --get-selections]
echo "-> list of packages... "
dpkg --get-selections > $PROG_OUTPUT

## [/etc/apt/sources.list]
echo "-> list of repositories... "
if [ "$verboseYes" = "1" ]; then
	echo " --> /etc/apt/sources.list"
fi	
cat /etc/apt/sources.list > $REPO_OUTPUT

## [/etc/apt/sources.list.d/]
echo "-> sources list directory... "
LIST=`find /etc/apt/sources.list.d | grep 'list$' `
for ONE in $LIST; do
	LOCAL=`basename $ONE`
	touch $LOCAL
	cat $ONE > $LOCAL
	
	if [ "$verboseYes" = "1" ]; then
	echo " --> $LOCAL"
	fi

done

# Backed up repos w/o passwd. LOL
mkdir repo_dir
mv *.list repo_dir/
tar -czf $REPO_DIR_OUTPUT repo_dir/  
rm -r repo_dir

## [OBSOLETE DEB PACKAGES] if make_debs = 1
if [[ "$make_debs" -eq "1" ]]; then
	tar -czf $OBS_DEBS_ARCHIEVE $OBS_DEBS_DIR 
fi
## [$SOURCE]
echo "-> global archieve... "

if [ "$verboseYes" = "1" ]; then
	echo " --> $PROG_OUTPUT"
	echo " --> $REPO_OUTPUT"
	echo " --> $REPO_DIR_OUTPUT"
	if [[ "$make_debs" -eq "1" ]]; then
		echo " --> $OBS_DEBS_ARCHIEVE"
	fi
fi

tar -czf $SOURCE $PROG_OUTPUT $REPO_OUTPUT $REPO_DIR_OUTPUT
echo "Grab `echo $SOURCE | sed 's/\/\//\//g'`."
if [[ "$make_debs" -eq "1" ]]; then
	echo "Also grab $OBS_DEBS_ARCHIEVE."
fi

## [CLEAN UP]
rm -rf $PROG_OUTPUT $REPO_OUTPUT $REPO_DIR_OUTPUT $OBS_DEBS_DIR
