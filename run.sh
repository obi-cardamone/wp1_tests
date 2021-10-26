clang++ -std=c++17 -fpic -o my_low_level_library.so -shared ctypes/my_low_level_library.cpp -lpthread
echo "Running ctypes test with low-level C++ implementation..."
time python3 ctypes/producer.py "cpp"
echo "Running ctypes test with numpy implementation..."
time python3 ctypes/producer.py "np"
