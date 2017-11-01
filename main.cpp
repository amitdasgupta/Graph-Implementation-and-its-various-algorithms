#include <iostream>

using namespace std;
class Graph{
int v;
int e;
int** arr_;
public:
Graph(int v)
{
    this->v=v;
    arr_=new int*[v];
    for(int i=0;i<v;i++)
        arr_[i]=new int[v];
    this->e=0;
}
void insertIntoGraph()
{
    cout<<"enter the number of edges:";
    cin>>e;
    int x,y;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        arr_[x][y]=1;
        arr_[y][x]=1;
    }
}
~Graph()
{
    for(int i=0;i<v;i++)
        delete[] arr_[i];
    delete[] arr_;
}
void showGraph()
{
    int i=0,j=0;
    for(i=0;i<v;i++)
        for(j=i;j<v;j++)
    {
        if(arr_[i][j]==1)
            {
                cout<<i<<"->"<<j<<endl;
                cout<<j<<"->"<<i<<endl;
            }

    }
}
};
int main()
{
    int v;
    cout<<"enter number of vertices:";
    cin>>v;
    Graph g(v);
    g.insertIntoGraph();
    g.showGraph();
    return 0;
}
