ifeq ($(OS),Windows_NT)
	target = build-default
else
	target = build-ninja
endif

build: $(target)

build-ninja:
	cmake -DCMAKE_BUILD_TYPE=Release -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram -G Ninja -B cmake-build
	ninja -C cmake-build
	cmake --build cmake-build --target install
build-default:
	cmake -DCMAKE_BUILD_TYPE=Release -DIXWEBSOCKET_INSTALL:BOOL=OFF -DCMAKE_INSTALL_PREFIX=foxogram -B cmake-build
	cmake --build cmake-build --target install
