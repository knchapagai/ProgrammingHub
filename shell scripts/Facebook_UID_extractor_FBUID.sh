#!/usr/bin/env bash
# Authors: Baibhav Anand Jha
# Documentation: github.com/baibhavanand/Fbuid

echo "
		  _         ___  _  
		 |_ |_  | |  |  | \ 
		 |  |_) |_| _|_ |_/ 
					                    
"
echo " 
   -Extract UserIDs From Public Facebook Accounts-
      
---Made With Love By - Baibhav | Twitter : @spongebhav---"
                                                     
while getopts u:f:g:h: flag
do
	case "${flag}" in
		u) username=${OPTARG};;
		g) groupusername=${OPTARG};;
		f) filename=${OPTARG};;
		h) help=${OPTARG};
	esac
done

function getuserpageid() {
	usernamecurl=`curl -s "https://mbasic.facebook.com/$username"`
	usernamestore=`echo "$usernamecurl" | sed "s/.*rid=//;s/&amp.*//" | sed "1 d"`
	echo "FbUID for username $username is: $usernamestore
	"
}

function getgroupid() {
	groupcurl=`curl -s "https://mbasic.facebook.com/groups/$groupusername"`
	groupnamestore=`echo "$groupcurl" | sed "s/.*groups\///;s/?view.*//" | sed "2 d" | sed "1 d" | sed "1 d"`
	echo "Group id for $groupusername is: $groupnamestore
	"
}

if [ "$username" != "" ];
then
echo "
"
getuserpageid
fi

if [ "$groupusername" != "" ];
then
echo "
"
getgroupid
fi

if [ "$filename" != "" ];
then
echo "
"
	while read line; do
	linenamecurl=`curl -s "https://mbasic.facebook.com/$line"`
	linenamestore=`echo "$linenamecurl" | sed "s/.*rid=//;s/&amp.*//" | sed "1 d"`
	echo "FbUID for username $line is: $linenamestore"
done < $filename
fi

if [ "$1" == "" ];
then
echo "
"
echo -n "Enter Username: "; read username
echo "
"
getuserpageid
fi

if [ "$username" == "" ] && [ "$groupusername" == "" ] && [ "$filename" == "" ] && [ "$1" != "" ]; then
	echo "
Note : FbUID will only work for public Facebook accounts. 
Usage:
fbuid (without any arguments)      will present you with a prompt to enter username.
-u  To specify username of pages and people
-g  To specify group username"
echo "
"
fi
