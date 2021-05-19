#ifndef FINDSHORTESTPATH_H
#define FINDSHORTESTPATH_H
#include <QVector>
#include <climits>
using namespace std;
#define V 5
int graph[V][V] = { {0, 4, 0, 0, 0},
                   {4, 0, 8, 0, 0},
                    {0, 8, 0, 7, 0},
                    {0, 0, 7, 0, 9},
                    {0, 0, 0, 9, 0}};
class FindShortestPath
{

public:
    FindShortestPath();
    int mindistance();
    void FindShortestPathf();
};

#endif // FINDSHORTESTPATH_H
