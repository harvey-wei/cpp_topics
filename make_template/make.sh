#!/bin/zsh

cmake -H. -B_builds \
&& cmake --build _builds

exit 0
