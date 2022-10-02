#!/bin/bash

#=======================================

# Password generator with login option

#=======================================

# Ask user for the string length

clear

printf "\n"

read -p "How many characters you would like the password to have? " pass_length

printf "\n"

# This is where the magic happens!

# Generate a list of 5 strings and cut it to the desired value provided from the user

for i in {1..5}; do (tr -cd '[:alnum:]' < /dev/urandom | fold -w${pass_lenght} | head -n 1); done

# Print the strings

printf "$pass_output\n"

printf "Goodbye, ${USER}\n"
