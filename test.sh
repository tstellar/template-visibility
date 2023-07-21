cmake -G Ninja -B gcc-build -S . -DCMAKE_CXX_COMPILER=g++
cmake -G Ninja -B clang-build -S . -DCMAKE_CXX_COMPILER=clang++

echo "******** GCC"
g++ --version
ninja -v -C gcc-build && echo "******** GCC SUCCESS"
nm -CD gcc-build/libtemplate-visibility.so
echo "******** CLANG"
clang++ --version
ninja -v -C clang-build  && echo "******** CLANG SUCCESS"
nm -CD gcc-build/libtemplate-visibility.so
