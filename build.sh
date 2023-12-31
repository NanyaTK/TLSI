cd build/
rm -rf ../build/*
echo "Deleted old files"
echo "Starting CMake build..."
cmake ..
echo "Starting Make build..."
make