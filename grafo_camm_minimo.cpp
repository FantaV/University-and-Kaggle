#include <iostream>
using namespace std;
const int INT_MAX = 10;

int miniDist(int distance[], bool Tset[])
// finding minimum distance
{ int minimum=INT_MAX;
    int ind;
    for(int k=0;k<5;k++) { if(Tset[k]==false && distance[k]<=minimum)
    { minimum=distance[k]; ind=k; } }
    return ind; }

void DijkstraAlgo(int graph[5][5],int src)
// adjacency matrix
{   int distance[5];
    int p[5];//
    // array to calculate the minimum distance for each node
    bool Tset[5];
    // boolean array to mark visited and unvisited for each node
    for(int k = 0; k<5; k++) { distance[k] = INT_MAX;
        Tset[k] = false; }
    distance[src] = 0;
    // Source vertex distance is set 0
    for(int k = 0; k<5; k++)
    { int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<5; k++)
        { // updating the distance of neighbouring vertex
            if(!Tset[k]
            && graph[m][k]
            && distance[m]!=INT_MAX
            && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
        p[k]=m;
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<5; k++)
    { char str=65+k;
        cout<<str<<"\t\t\t"<<distance[k]<<endl;

    }
    for(int k = 0; k<5; k++)
    {

        cout<<"p  "<<p[k];
    }
}


int main()
{ int graph[5][5]={
    {0, 5, 10, 0, 0},
    {0, 0, 3, 2, 9},
    {0, 2, 0, 0, 1},
    {0, 0, 0, 0, 6},
    {0, 0, 0, 4, 0}};
    //s  a  b  c  d*/
    DijkstraAlgo(graph,0);
    return 0; }
