#!/bin/bash

function expect_eq() {
    if [[ $1 -eq $2 ]]; then
        echo "SUCCESS";
    else
        echo "FAILURE";
        exit 1;
    fi
}

function expect_ne() {
    if [[ $1 -ne $2 ]]; then
        echo "SUCCESS";
    else
        echo "FAILURE";
        exit 1;
    fi
}

if [ $# -ne 1 ]; then
    echo "Usage: test.sh <prog_name>";
    exit 1;
fi

echo "TEST invalid num of arguments"
$1 > /dev/null
expect_eq $? 1

$1 1 > /dev/null
expect_eq $? 1

$1 1 2 > /dev/null
expect_eq $? 1

$1 1 2 3 > /dev/null
expect_eq $? 1

$1 1 2 3 4 > /dev/null
expect_ne $? 1

$1 1 2 3 4 5 > /dev/null
expect_ne $? 1

$1 1 2 3 4 5 6 > /dev/null
expect_eq $? 1

echo "TEST: input is correct"
$1 1 1 1 1 1 > /dev/null
expect_ne $? 2

$1 1 1 -1 1 1 > /dev/null
expect_eq $? 2

$1 1 -1 1 1 1 > /dev/null
expect_eq $? 2

$1 1 abc 1 1 1 > /dev/null
expect_eq $? 2

$1 1 1 abc 1 1 > /dev/null
expect_eq $? 2

$1 1 1 1 abc 1 > /dev/null
expect_eq $? 2

$1 1 1 1 -1 1 > /dev/null
expect_eq $? 2

$1 1 1 1 5 1 > /dev/null
expect_eq $? 2

echo "TEST: good file"
