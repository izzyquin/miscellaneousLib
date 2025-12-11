#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "../lib/assert_lib.h"
#include "../graph/DataType.h"


class DataType;

using namespace std;
class dijkstra {
private:
    int V;
    vector<vector<DataType> > distMatrix;

public:
    dijkstra(vector<vector<DataType> > distTable);
    
    ~dijkstra();

    int dijkstra::minDistance(vector<DataType> &dist, vector<bool> &visited_vorteces);

    vector<DataType> calc(int src);

    void calc();

    void print();
};

#endif // DIJKSTRA_H