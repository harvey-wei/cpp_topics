#!/bin/zsh

# clangd will find the compile_commands.json in build
cmake -H. -Bbuild \
&& cmake --build build

exit 0
