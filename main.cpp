#include <iostream>
using namespace std;
/*******************************graph defination using matrix
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
};*////////////////////////////////////////////////////////////////////////
class Node{
public:
int vertex;
Node* next;
Node(int vertex)
{
    this->vertex=vertex;
    this->next=NULL;
}
};
class Graph{
int v;
int e;
Node** arr_;
public:
Graph(int v)
{
    this->v=v;
    arr_=new Node*[v];
    for(int i=0;i<v;i++)
    {
        arr_[i]=new Node(i);
        arr_[i]->next=arr_[i];
    }
}
void insertIntoGraph()
{
    Node* temp;
    cout<<"enter the number of edges:";
    cin>>e;
    int x,y;
    for(int i=0;i<e;i++)
    {cin>>x>>y;
    temp=new Node(y);
    temp->next=arr_[x]->next;
    arr_[x]->next=temp;
    temp=new Node(x);
    temp->next=arr_[y]->next;
    arr_[y]->next=temp;
    }
}
~Graph()
{
    for(int i=0;i<v;i++)
        delete[] arr_[i];
    delete[] arr_;
}
void printLinked(Node* head)
{
    cout<<head->vertex<<":";
    Node* temp=head->next;
    while(temp!=head){
        cout<<"->"<<temp->vertex;
        temp=temp->next;
    }
    cout<<"\n";
}
void showGraph()
{
    int i=0;
    for(int i=0;i<v;i++)
    {
        printLinked(arr_[i]);
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
  //  cout<<"c";
    g.showGraph();
    return 0;
}