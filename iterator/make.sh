#!/bin/zsh

cmake -H. -Bbuilds \
&& cmake --build builds

exit 0
