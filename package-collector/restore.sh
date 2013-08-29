#!/bin/bash
## v.0.9

## cat history.log.1 | grep "apt-get install" | awk '{print $4}' >> ~/log.txt
## @ /var/log/aptitude
## cat dpkg.log | grep installed | grep -v "half-installed" | awk '{print $5}' >> ~/log.txt

## loop to test out the given parameter
while [ 1 ]; do
	if [[ "$1" = "--source-file" || "$1" = "-sf" ]]; then
		shift 
		SOURCE_FILE="$1"
		SOURCE_DIR="${1/.tar.gz/}"
	elif [ -z "$1" ]; then
		break # exit loop when parameters are over 
	fi
	shift
done

		
## Update system to the newest software
echo "Updating system... "
#sudo apt-get update -qq && sudo apt-get -y upgrade 

## Starting recovery  
mkdir -p $SOURCE_DIR
echo -n "Extracting global archieve... " ## ... to $SOURCE_DIR
tar -xzf $SOURCE_FILE -C $SOURCE_DIR/
echo "Done"

cd $SOURCE_DIR/

echo "Extracting repo archieve... " 
tar -xzf $SOURCE_DIR\.repolist_dir.tar.gz 
echo "Passwd required."
sudo cp repo_dir/*.list ~/temp/ #/etc/apt/sources.list.d/
echo "Done"
 
echo -n "Replacing sources.list... "
sudo cp $SOURCE_DIR.repolist ~/temp/sources.list #/etc/apt/sources.list
echo "Done"

echo "Restoring list of packages... "
sudo dpkg --set-selections < $SOURCE_DIR.packlist  && sudo apt-get -u dselect-upgrade
echo "Done"

## Recovery done, cleaning up
cd .. && rm -rf $SOURCE_DIR/
