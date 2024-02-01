#!/bin/zsh

# clangd will find the compile_commands.json in build
cmake -H. -Bbuild \
&& cmake --build build --target install

exit 0

# The alternative way
# mkdir build    under the same parent directory of the src
# cd build
# cmake ..      .. means going one level above to see CMakeLists.txt (configure and generating)
# make          still in the build directory (build the target (compile and link to lib))


# Build but not install
# cmake -S . -B build \
# && cmake --build build

