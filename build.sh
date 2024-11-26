cd build

cmake .. -DCMAKE_INSTALL_PREFIX=/opt/Qt/6.7.3/gcc_64/lib/cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cmake --build .
