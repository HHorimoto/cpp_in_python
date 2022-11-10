#!/bin/bash

ng () {
	echo NG at Line $1
	res=1
}

res = 0

## FIRST TEST ##
NUM11=4
NUM12=2
result=`./test/test_script.py ${NUM1} ${NUM2}`
TRUE=$(( $NUM11-$NUM12 ))
[ ${result}=${TRUE} ] || ng $LINENO


## SECOND TEST ##
NUM11=5
NUM12=10
result=`./test/test_script.py ${NUM1} ${NUM2}`
TRUE=$(( $NUM11-$NUM12 ))
[ ${result}=${TRUE} ] || ng $LINENO

exit $res