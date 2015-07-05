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

The packaging scripts use `move` commands rather than copy for the shared libraries and executables so that when testing the packaged directory, there is no opportunity for the shared libraries to be loaded from the build directory.

#### Linux

```bash
export PACKAGE_DIR=/tmp/pkg/
mkdir $PACKAGE_DIR

mv -f $(find ./bii/build/ -type f -name *.so*) "/${PACKAGE_DIR}/lib/"
mv -f ./bin/azriel_sl_ax_main_main "/${PACKAGE_DIR}/"

cp -f -p ./packaging/linux/run.sh "/${PACKAGE_DIR}/"
"/${PACKAGE_DIR}/run.sh"
```

#### Windows

```batch
set PACKAGE_DIR=%TEMP%\pkg\
md %PACKAGE_DIR%\lib

move /Y .\bin\*.dll %PACKAGE_DIR%\lib
move /Y .\bin\azriel_sl_ax_main_main.exe %PACKAGE_DIR%

copy /Y .\packaging\windows\run.bat %PACKAGE_DIR%
%PACKAGE_DIR%\run.bat
```

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
