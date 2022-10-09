#!/bin/bash

transport=('car' 'train' 'bike' 'bus')

transport[1]=trainride

transport[4]=flight

echo "${transport[@]}"

# Output: car trainride bike bus flight
