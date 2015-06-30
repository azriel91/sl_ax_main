## sl\_ax\_main

This block provides the main executable for the Autexousious engine.

## Development

This is implemented as a [CppMicroServices](https://github.com/saschazelzer/CppMicroServices) module, and is built using
[biicode](https://www.biicode.com/).

### Requirements

* [biicode](https://www.biicode.com/downloads)
* [CMake](http://www.cmake.org/install/)
* [g++ 4.8](https://gcc.gnu.org/)

### Building

After cloning, in the repository directory run the following to initialize this as a biicode block:

	bii init -l

Depending on whether you wish to build the blocks as static or dynamic CppMicroServices modules, run configure with the `BUILD_SHARED_LIBS` flag set to `OFF` or `ON`. If you leave the flag out, it defaults to `OFF`.

	bii configure -DBUILD_SHARED_LIBS=ON

Finally to build the executable, run:

	bii build

The executable will be output as `bin/azriel_sl_ax_main_main`.

### Packaging

#### Linux

	export PACKAGE_DIR=/tmp/pkg/
	mkdir $PACKAGE_DIR

	cp $(find ./bii/build/ -type f -name *.so*) "/${PACKAGE_DIR}/lib/"
	cp ./bin/azriel_sl_ax_main_main "/${PACKAGE_DIR}/"

	# Remove build directory so that the executable has no opportunity to load artifacts from it
	rm -rf ./bii/build/

	# 'run' script
	cat > "/${PACKAGE_DIR}/run.sh" <<EOF
	#!/bin/sh
	CURRENT_DIR=$(dirname $0)
	export LD_LIBRARY_PATH="${CURRENT_DIR}/lib":$LD_LIBRARY_PATH

	$CURRENT_DIR/azriel_sl_ax_main_main
	EOF
	chmod +x "/${PACKAGE_DIR}/run.sh"
	"/${PACKAGE_DIR}/run.sh"

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
