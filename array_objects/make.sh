#!/bin/zsh

if [[ ! -d "boost_includes" ]]; then
    ln -s "$HOME/Desktop/Files/research/code/boost_1_79_0/" boost_includes
fi

cmake -H. -Bbuild \
&& cmake --build build

exit 0
