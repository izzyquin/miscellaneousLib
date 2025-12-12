#include "Dijkstra.h"
#include <limits.h>

#define INVALID_IDX -1

dijkstra::dijkstra(vector<vector<DataType> > distTable){
	distMatrix = distTable;
	V = distTable.size();
}

int dijkstra::minDistance(vector<DataType> &dist, vector<bool> &visited_vorteces){

	ASSERT_RETURN(V, index);
	ASSERT_RETURN(dist.size() == V, index);

	DataType min(INT_MAX);
	int index = INVALID_IDX;
	
	for (int i = 0; i < V; i++)
	{
		if(visited_vorteces[i] == false && 
		   dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

vector<DataType> dijkstra::calc(int src) {

	ASSERT_RETURN(src < V, std::vector<DataType> emptyVec);
	vector<bool> visited_vorteces(V, false);
	vector<DataType> dist(V, DataType(INT_MAX));

	dist[src] = 0;
	DataType max(INT_MAX);

	for (int count = 0; count < V; count++)
	{
		int min_idx = minDistance(dist, visited_vorteces);

		if (min_idx == INVALID_IDX)
		{	
			continue;
		}
		visited_vorteces[min_idx] = true;
		for (int i = 0; i < V; i++)
		{
			if (!visited_vorteces[i] &&
			    nodesTable[min_idx][i] != max &&
			    dist[min_idx] != max &&
			    dist[i] > (dist[min_idx] + nodesTable[min_idx][i]))
			{
				dist[i] = dist[min_idx] + nodesTable[min_idx][i];
			}	
		} 	
	}
}

void dijkstra::calc(){
	for (int i = 0; i < V; i++)
	{	
		distMatrix[i] = calc(i);
	}
}

void dijkstra::print(){	
	for (int i = -1; i < V; i++)
	{	
		if (i < 0)	cout<<"D"<<"\t";
		else 		cout<<i<<"\t";

		for (int j = 0; j < V; j++)
        {
        	if (i < 0)
        	{ 
        		cout<<j<<"\t";
        		continue;
        	}
        	cout<<dist[j]<<"\t";
    	}
		cout<<endl;
	}
}



int main ()
{
/*
	int nodesTable[V][V] = {
	{0, 1, INT_MAX},
	{1, 0, 2},
	{INT_MAX, 2, 0}
	};
*/
	vector<vector<DataType> > nodesTable = {
        {0, 2, INT_MAX, 1, INT_MAX},
        {2, 0, 4, INT_MAX, 5},
        {INT_MAX, 4, 0, 3, INT_MAX},
        {1, INT_MAX, 3, 0, 6},
        {INT_MAX, 5, INT_MAX, 6, 0}
    };
	
	
    dijkstra d(nodesTable);
    d.calc();
    d.print();

	return 0;
}
