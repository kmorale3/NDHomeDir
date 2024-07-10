#!/bin/bash

WORKSPACE=/tmp/translations.$(id -u)
FAILURES=0

error() {
    echo "$@"
    echo
    [ -r $WORKSPACE/test ] && cat $WORKSPACE/test
    echo
    FAILURES=$((FAILURES + 1))
}

cleanup() {
    STATUS=${1:-$FAILURES}
    rm -fr $WORKSPACE
    exit $STATUS
}

mkdir $WORKSPACE

trap "cleanup" EXIT
trap "cleanup 1" INT TERM

echo "Checking Exam 02 translations ..."

printf " %-40s ... " "translate1.py"
./translate1.py | diff -y - <(cat /etc/passwd | cut -d : -f 4 | sort | uniq -c | sort -rns | head -n 1 | awk '{print $2}') > $WORKSPACE/test
if [ $? -ne 0 ] || grep -Eq '(popen\(|system\()' translate1.py; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "translate2.py"
./translate2.py | diff -y - <(curl -sL https://yld.me/raw/fDIO | sort -t , -k 2 | cut -d , -f 3 | tr a-z A-Z) > $WORKSPACE/test
if [ $? -ne 0 ] || grep -Eq '(popen\(|system\()' translate2.py; then
    error "Failure"
else
    echo "Success"
fi

printf " %-40s ... " "translateX.py"
./translateX.py | diff -y - <(env | cut -d = -f 1 | grep '^[a-zA-Z]' | env LC_ALL=C sort) > $WORKSPACE/test
if [ $? -ne 0 ] || grep -Eq '(popen\(|system\()' translateX.py; then
    EXTRA=0
    echo "Nope"
else
    EXTRA=1
    echo "Yeah"
fi

TESTS=$(($(grep -c Success $0) - 2))
echo
printf "   Score $(echo "scale=4; ($TESTS - $FAILURES) / $TESTS.0 * 10.0" | bc | awk '{printf "%0.2f\n", $1}') / 10.00"
if [ $EXTRA -eq 1 ]; then
    echo " + 1.00 Extra Credit"
else
    echo
fi
printf "  Status "
if [ $FAILURES -eq 0 ]; then
    echo "Success"
else
    echo "Failure"
fi
echo
