#!/usr/bin/env bash
#Coded by: Baibhav Anand Jha | Twitter: @spongebhav
#Project link: https://github.com/baibhavanand/dac

echo "	
	 ____       __        ___ 
	(  _ \     /__\      / __)
	 )(_) )   /(__)\    ( (__ 
	(____/   (__)(__)    \___)
	Domain Availibility Checker

--- </> With <3 By - Baibhav | Twitter : @spongebhav ---


"
while getopts d:l:t:o: flag
do
	case "${flag}" in
		d) domain=${OPTARG};;
		l) list=${OPTARG};;
		t) tld=${OPTARG};;
		o) output=${OPTARG};;
	esac
done

function available() {
		if [ "$tld" != "" ]; then
			sed1=$(echo "$domain" | sed "s/$/$tld/g")
			sed2=$(echo "$sed1" | sed "s/$tld$tld/$tld/g")
	else
			sed1=$(echo "$domain" | sed "s/$/.com/g")
			sed2=$(echo "$sed1" | sed "s/.com.com/.com/g")
		fi	
	
	check=`curl -s https://domains.revved.com/v1/domainStatus?domains=$sed2`
			if [ "$check" == "" ]; then
			echo "
Something went Wrong.
Possible reasons:
	1. Network error.
	2. TLD isn't supported."
				exit;
			fi
    if [[ "${check}" =~ "true" ]]; then
		  echo -e "${sed2} is available."
		else
		  echo -e "${sed2} is taken."
		fi
}

function availablelist(){
	if [ "$tld" != "" ]; then
		sed -i "s/$/$tld/g" "$list"
		sed -i "s/$tld$tld/$tld/g" "$list"
	else
			sed -i "s/$/.com/g" "$list"
			sed -i "s/.com.com/.com/g" "$list"
	fi		
	echo
	while read line; do
		check=`curl -s https://domains.revved.com/v1/domainStatus?domains=$line`
		if [ "$check" == "" ]; then
			echo "
Something went Wrong.
Possible reasons:
	1. Network error.
	2. TLD isn't supported."
				exit;
			fi
		if [[ "${check}" =~ "true" ]]; then
		  if [ "$output" != "" ]; then
		  	echo -e "${line} is available."
		  	echo -e "${line}" >> $output
		  	else
		  		echo -e "${line} is available."
		  	fi
		else
		  echo -e "${line} is taken."
		fi
done < $list
}

if [[ "$tld" != "."* ]] && [ "$tld" != "" ]; then
  fullstop="."
  tld="$fullstop$tld"
fi

if [ "$domain" != "" ];
then
	available
fi

if [ "$list" != "" ]; then
	availablelist

	if [ "$tld" != "" ] && [ "$list" != "" ] && [ "$domain" == "" ]; then
		sed -i "s/$tld//g" "$list"
	else
		sed -i "s/.com//g" "$list"
	fi
fi


if [ "$domain" == "" ] && [ "$list" == "" ]; then
echo "Usage:
	-d : To specify domain name.
	-l : To specify the text file containing the list of domain names.
	-o : To specify file name to output the list of available domains.
	-t : To specify a TLD. (ex: .com .org .net, etc)
	"
fi
