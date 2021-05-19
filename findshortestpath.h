#ifndef FINDSHORTESTPATH_H
#define FINDSHORTESTPATH_H
#include <QVector>
#include <climits>
#define V 5

using namespace std;

class FindShortestPath
{
public:
    int graph[V][V] = { {0, 4, 0, 0, 0},
                        {4, 0, 8, 0, 0},
                         {0, 8, 0, 7, 0},
                         {0, 0, 7, 0, 9},
                         {0, 0, 0, 9, 0}};
    int mindistance(int dist[],bool isvisited[]);
    void FindShortestPathfinder(int graphh[5][5],int src, int destt);
    void printpath(QVector<int> path);
};

#endif // FINDSHORTESTPATH_H
