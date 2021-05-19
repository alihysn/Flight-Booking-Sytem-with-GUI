#ifndef FINDSHORTESTPATH_H
#define FINDSHORTESTPATH_H
#include <QVector>
#include <climits>
#define V 5

using namespace std;

class FindShortestPath
{
public:
    int graph[V][V] = { {0, 1, 6, 8, 10},
                        {1, 0, 1, 6, 8},
                        {6, 1, 0, 1, 6},
                        {8, 6, 1, 0, 1},
                        {10, 8, 6, 1, 0}};
    int mindistance(int dist[],bool isvisited[]);
    void FindShortestPathfinder(int graphh[5][5],int src, int destt);
    void printpath(QVector<int> path);
};

#endif // FINDSHORTESTPATH_H
