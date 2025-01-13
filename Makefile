build:
	cmake -DCMAKE_BUILD_TYPE=Release -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram -G Ninja -B cmake-build
	ninja -C cmake-build
	cmake --build cmake-build --target install
