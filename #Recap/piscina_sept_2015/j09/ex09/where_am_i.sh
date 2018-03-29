#!/bin/sh

zama=$(ifconfig | grep "inet" | cut -d' ' -f2)
if test - z "$zama"
then 
	echo "Je suis perdu!"
else
	echo &zama | tr ' ' '\n'
fi
