#!/bin/zsh

cmake -H. -Bbuild \
&& cmake --build build

exit 0
