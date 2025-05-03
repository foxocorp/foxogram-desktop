build-main:
	cmake -DCMAKE_BUILD_TYPE=Release -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram_install -DCMAKE_C_COMPILER_LAUNCHER=sccache -DCMAKE_CXX_COMPILER_LAUNCHER=sccache -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -B cmake-build
	ninja -C cmake-build
	cmake --build cmake-build --target install
build-dev:
	cmake -DCMAKE_BUILD_TYPE=Debug -DDEV:BOOL=ON -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram_install -DCMAKE_C_COMPILER_LAUNCHER=sccache -DCMAKE_CXX_COMPILER_LAUNCHER=sccache -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -G Ninja -B cmake-build
	ninja -C cmake-build
	cmake --build cmake-build --target install
