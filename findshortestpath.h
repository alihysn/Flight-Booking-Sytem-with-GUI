#ifndef FINDSHORTESTPATH_H
#define FINDSHORTESTPATH_H
#include <QVector>
#include <QVector2D>
#include <climits>
using namespace std;
class FindShortestPath
{
    QVector2D graph(5,5);
public:
    int mindistance();
    void FindShortestPath();
};

#endif // FINDSHORTESTPATH_H
