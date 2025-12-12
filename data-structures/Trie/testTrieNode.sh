# Compile and run the test program using g++
echo "Compiling and running testTrieClass.cpp..."
g++ -std=c++14 -o main testTrieNode.cpp TrieNode.cpp -lgtest -lgtest_main -pthread
./main

