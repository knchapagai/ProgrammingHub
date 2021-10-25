#!/usr/bin/env bash
# Author: Baibhav Anand Jha | Twitter: @spongebhav

echo "
███╗   ██╗██████╗    ██████╗  █████╗ ████████╗███████╗
████╗  ██║██╔══██╗   ██╔══██╗██╔══██╗╚══██╔══╝██╔════╝
██╔██╗ ██║██████╔╝   ██║  ██║███████║   ██║   █████╗  
██║╚██╗██║██╔═══╝    ██║  ██║██╔══██║   ██║   ██╔══╝  
██║ ╚████║██║███████╗██████╔╝██║  ██║   ██║   ███████╗
╚═╝  ╚═══╝╚═╝╚══════╝╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚══════╝
                                                      
                                                   
---Made With Love By - Baibhav | Twitter : @spongebhav---


      "


while getopts i:n: flag
do
	case "${flag}" in
		n) idate=${OPTARG};;
		i) ndate=${OPTARG};;
	esac
done 


function convertnepali(){
	outputnep=`curl -s -XPOST -d "actionName=dconverter&datefield=$idate&convert_option=eng_to_nep" 'https://www.hamropatro.com/getMethod.php'`
	propnepdate=`echo "$outputnep" | sed "s/.*<span>//;s/<\/span>.*//"`
	if [[ $propnepdate == *"Oops"* ]]; then
  echo "An error Occured. Make sure the date is in YYYY/MM/DD format.
  "
else
	echo "The Nepali date for $idate is : $propnepdate
	"
fi
}

function convertinternational(){
	outputint=`curl -s -XPOST -d "actionName=dconverter&datefield=$ndate&convert_option=nep_to_eng" 'https://www.hamropatro.com/getMethod.php'`
	propengdate=`echo "$outputint" | sed "s/.*<\/strong>//;s/|.*//"`
	propnepdate=`echo "$outputint" | sed "s/.*<span>//;s/<\/span>.*//"`
	if [[ $propengdate == *"Oops"* ]]; then
  		echo "An error Occured. Make sure the date is in YYYY/MM/DD format.
  		"
	else
		echo "The International date for $propnepdate is : $propengdate
		"
	fi
}


function normal(){
	output=`curl -s -XPOST -d "actionName=dconverter&datefield=$(date +%F)&convert_option=eng_to_nep" 'https://www.hamropatro.com/getMethod.php'`
	engdate=`echo "$output" | sed "s/.*<\/strong>//;s/|.*//"`
	nepdate=`echo "$output" | sed "s/.*<span>//;s/<\/span>.*//"`
	echo "Nepali Date : $nepdate"
	echo "International Date : $engdate
	"
}

if [ "$ndate" != "" ];
then
convertinternational
fi

if [ "$idate" != "" ];
then
convertnepali
fi

if [ "$ndate" == "" ] && [ "$idate" == "" ];
then
normal
fi
