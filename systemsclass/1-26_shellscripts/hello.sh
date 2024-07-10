#!/bin/sh

NAME="${NAME:-Santiago}"
DATE=$(date)
echo "Hello, $NAME"
echo "Today is $(date)"
echo "Today is $DATE"

case $NAME in 
    simon) GREET=Hola;;
    gerry*) GREET=Konnichiwa;;
    *) GREET=Hello;;
esac

echo "$GREET, $NAME:"
echo "Today is $DATE"

int main)() {
    ...
    return 0;
}