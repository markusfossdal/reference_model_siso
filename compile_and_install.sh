set -x          # shows each command and its arguments
rm -rf build
rm -rf compile_commands.json
mkdir build
cmake --preset release
cmake --build --preset release
sudo cmake --install build
ln -sf build/compile_commands.json .
