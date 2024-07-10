#!/bin/sh

# globals

N=1
SHOUT=0

# functions
usage() {
    cat 1>&2 
    exit $1
}

#parse command line arguments

while [ $# -gt 0 ]; do
    case $1 in 
        -n) N=$2; shift;;
        -s) SHOUT=1;;
        -h) usage 0;;
        -*) usage 1;;
         *) break;;
    esac
    shift
done


MESSAGE=$@

# main execution
for i in $(seq $N) ; do   
    if [ $SHOUT -eq 0 ]; then
        echo $MESSAGE
    else
        echo MESSAGE: $MESSAGE | tr a-z A-Z
    fi
done