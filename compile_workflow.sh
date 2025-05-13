#!/bin/bash

rm -rf build
rm -rf compile_commands.json
cmake --preset rel
cmake --build build
ln -sf build/compile_commands.json .

