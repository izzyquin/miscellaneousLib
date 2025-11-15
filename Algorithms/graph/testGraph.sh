# Compile and run the test program using g++
echo "Compiling and running testGraph.cpp..."
g++ -std=c++14 -o main testGraph.cpp graph.cpp Node.cpp DataType.cpp Stack.cpp Queue.cpp -lgtest -lgtest_main -pthread
./main
