build:
	cmake -DCMAKE_BUILD_TYPE=Release -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram_install -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ -G Ninja -B cmake-build
	ninja -C cmake-build
	cmake --build cmake-build --target install