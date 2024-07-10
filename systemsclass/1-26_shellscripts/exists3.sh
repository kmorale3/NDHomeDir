#!/bin/sh

EXITCODE=0

check_file() {
if [ -e "$1" ]; then 
    echo "we haz file: $1"
else 
    echo "Nope, don't have file: $1"
    EXITCODE=$(($EXITCODE+1))
fi 
}
<<COMMENT
for argument in "$@"; do 
    echo $argument
    check_file $argument
done
COMMENT

#./exists3.sh alpha beta gamma
# $0            $1   $2   $3
#               $0   $1   $2    (shift)
#                    $0   $1     (shift)
echo BEFORE: $@
while [ $# -gt 0 ]; do
    check_file "$1"
    shift
done
echo AFTER: $@

exit $EXITCODE