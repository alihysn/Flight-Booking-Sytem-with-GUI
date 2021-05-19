#include "findshortestpath.h"
#include <iostream>
#include <climits>
#include <QString>
#include <QVector>
#include <list>
#include <queue>
using namespace std;
int mindistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void FindShortestPathf(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = mindistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
}
void FindShortestPath::printpath(int parent[],int j)
{

}
