#!/bin/sh

if stat shs.sh &> /dev/null ; then 
    echo "we haz file"
else 
    echo "Nope, don't have file"
fi 