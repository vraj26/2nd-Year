#!/bin/bash

out=`(./Lab4)`
echo $out
if [[ $out == *"!!!FAILURES!!!"* ]]; then
  exit 1;
fi


