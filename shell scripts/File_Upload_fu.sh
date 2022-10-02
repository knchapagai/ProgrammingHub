#!/usr/bin/env bash
grn=$'\e[1;32m'
echo "$grn
		_______     _    _ 
		|   ___|   | |  | |
		|  |_      | |  | |
		|   _|     | |  | |
		|  |       | |__| |
		 \_|        \____/ 
		                 
		File        Upload

--- </> With <3 By - Baibhav | Twitter : @spongebhav ---

"

while getopts f:e:t: flag
do
	case "${flag}" in
		f) filepath=${OPTARG};;
		e) expiry=${OPTARG};;
		t) text=${OPTARG};;
	esac
done

function renderresult(){
if [[ "$check" == *"expiry"* ]]; then

echo 'File Uploaded Successfully';
	link=`echo "$check" | jq '.link'`
	echo "Link = $link";
	expirydate=`echo "$check" | jq '.expiry'`
	echo "Expiry Date = $expirydate";
else
echo 'Your file could not be uploaded';	
	success=`echo "$check" | jq '.success'`
	echo "Success = $success";
	error=`echo "$check" | jq '.error'`
	echo "Error = $error";
	message=`echo "$check" | jq '.message'`
	echo "Message = $message";
fi
}

function filepath(){
	check=`curl -s -F "file=@$filepath" https://file.io/?expires=$expiry`
	renderresult
}

function textfile(){
	check=`curl -s --data "text=$text" https://file.io/?expires=$expiry`
	renderresult
}

if [ "$filepath" != "" ];
then
	filepath
fi

if [ "$text" != "" ];
then
	textfile
fi

if [ "$filepath" == "" ] && [ "$text" == "" ];
then
	echo "
	Usage:


	To simply upload your file with 14 days expiry time

	fu -f your_file_path
	Ex: fu -f test.jpeg
	Ex: fu -f Desktop/test.jpeg


	To set custom expiry time:

	fu -f your file path -e no. of days, weeks, months, year
	Ex: fu -f test.jpeg -e 1d (expires in 1 day)
	Ex: fu -f test.jpeg -e 1w (expires in 1 week)
	Ex: fu -f test.jpeg -e 1m (expires in 1 month)
	Ex: fu -f test.jpeg -e 1y (expires in 1 year)
	Ex: fu -f test.jpeg -r 1y1m1w1d (expires in 1Year 1month 1 week and 1 day)


	To directly upload a text file by writing content:

	fu -t 'your text here'
	Ex: fu -t 'Star this project. Link : git.io/fileupload'
	"
fi
