#include "findshortestpath.h"
#include <iostream>
#include <climits>
#include <QString>
#include <QVector>
#include <QMessageBox>
using namespace std;
int FindShortestPath::mindistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void FindShortestPath::FindShortestPathf(int graph[V][V], int src, int destt)
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
    QVector <int> path;
   int i=src;
       do
       {
       if (i<4)
          { path.push_back(i);
           i++;}
       else if(i==4)
       {
           i=0;
           {
               path.push_back(i);
               i++;
           }
       }
       }while(i!=destt);
}
void FindShortestPath::printpath(QVector<int> paths)
{
     QMessageBox box;
     QString str;
    for (int i=0;i<V;i++)
    {
        if(paths[i]==0)
            str= "cairo";
        else if(paths[i]==1)
            str="Rome";
        else if(paths[i]==2)
            str="Paris";
        else if (paths[i]==3)
            str="Capetown";
        else if (paths[i]==4)
            str="California";
    box.setWindowTitle("Your best options are");
    box.setText(str);
    box.exec();
    }
}
