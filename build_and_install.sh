#!/bin/bash

rm -rf build
rm -rf compile_commands.json
cmake --preset rel
cmake --build --preset rel
sudo cmake --install build-rel
ln -sf build-rel/compile_commands.json .
