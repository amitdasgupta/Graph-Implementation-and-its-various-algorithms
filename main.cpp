#include <iostream>
#include<deque>
#include<stack>
#include<queue>
#define pp pair<int,int>
using namespace std;
/**************class for defining priority queue*///////////////
class priority{
    public:
bool operator()(pp &a,pp &b)
{
    return a.first>b.first;
}
};
/*******************************graph defination using matrix*////////////////////////////////////////////////////////////////////////
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
        arr_[i]=new int[v]();
    this->e=0;
}
void insertIntoGraph()
{
    cout<<"enter the number of edges:";
    cin>>e;
    int x,y,weight;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>weight;
        arr_[x][y]=weight;
        //arr_[y][x]=1;
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
        for(j=0;j<v;j++)
    {
        if(arr_[i][j])
            {
                cout<<i<<"->"<<j<<endl;
            }

    }
}
/**************************dfs*///////////////////////
void visitNode(int* &arr,int i)
{

    arr[i]=1;
    for(int j=0;j<this->v;j++)
        if(!arr[j]&&this->arr_[i][j])
      visitNode(arr,j);
     cout<<i<<" ";

}
void dfs()
{
    int *arr=new int[this->v]();
    for(int i=0;i<this->v;i++)
    {
        if(!arr[i])
            visitNode(arr,i);

    }
}
/**********************bfs*//////////////////////////
void bfs()
{
    int *arr=new int[this->v]();
    deque<int> deque_;
    int temp;
    deque_.push_back(0);

    while(!deque_.empty())
    {
     temp=deque_.front();
     deque_.pop_front();
     cout<<temp<<" ";
     arr[temp]=1;
         for(int i=0;i<this->v;i++)
        {
            if(!arr[i]&&this->arr_[temp][i])
                {
                    deque_.push_back(i);
                }
        }
    }
}
/*******************topological sort*/////////////////
void helperTopoSort(int node,stack<int> &s,int* &arr)
{

    arr[node]=1;
    for(int i=0;i<this->v;i++)
    {
        if(!arr[i]&&this->arr_[node][i])
        {
            helperTopoSort(i,s,arr);
        }
    }
    s.push(node);
}
void topologicalSort()
{
    int temp;
    stack<int> s;
    int* arr=new int[this->v]();
    for(int i=0;i<this->v;i++)
    {
        if(!arr[i])
            helperTopoSort(i,s,arr);
    }
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp<<" ";
    }
}
/**************************shortest path algorithms*//////////////////////////
void shortestPath()
{
    int* distance=new int[this->v];
    cout<<"\nenter the vertex from which you want to find the shortest path";
    int ver,temp,curr_distance;
    cin>>ver;
    int* previous=new int[this->v]();
    for(int i=0;i<this->v;i++)
        distance[i]=-1;
    distance[ver]=0;
    deque<int> deque_;
    deque_.push_back(ver);
    while(!deque_.empty())
    {
     temp=deque_.front();
        deque_.pop_front();
        for(int i=0;i<this->v;i++)
        {
            //curr_distance=distance[temp]+1;
           if(distance[i]==-1&&this->arr_[temp][i])
            {

                distance[i]=distance[temp]+1;
                previous[i]=temp;
                deque_.push_back(i);
            }
            /*else
                if(distance[i]>curr_distance)
            {
             distance[i]==curr_distance;
                previous[i]=temp;
                deque_.push_back(i);
            }*/
        }
    }
    cout<<"\n printing distance array";
    for(int i=0;i<this->v;i++)
        cout<<distance[i]<< " ";
    cout<<"\n printing previous array";
    for(int i=0;i<this->v;i++)
        cout<<previous[i]<< " ";
}
/*****************************code for shortest path in weighted graph*////////////////////////
void dijskastraWeightedShortestPath()
{
    int* distance=new int[this->v];
    cout<<"\nenter the vertex from which you want to find the shortest path";
    int ver,temp,curr_distance;
    cin>>ver;
    int* previous=new int[this->v]();
    for(int i=0;i<this->v;i++)
        distance[i]=-1;
    distance[ver]=0;
    priority_queue<pp,vector<pp>,priority> p_queue;
    p_queue.push(pp(0,ver));
    while(!p_queue.empty())
    {
     temp=p_queue.top().second;
        p_queue.pop();
        for(int i=0;i<this->v;i++)
        {
            curr_distance=distance[temp]+this->arr_[temp][i];
           if(distance[i]==-1&&this->arr_[temp][i])
            {

                distance[i]=curr_distance;
                previous[i]=temp;
                p_queue.push(pp(distance[i],i));
            }
            else
                if(distance[i]>curr_distance&&this->arr_[temp][i])
            {
             distance[i]=curr_distance;
                previous[i]=temp;
               p_queue.push(pp(distance[i],i));

            }
        }
    }
    cout<<"\n printing distance array";
    for(int i=0;i<this->v;i++)
        cout<<distance[i]<< " ";
    cout<<"\n printing previous array";
    for(int i=0;i<this->v;i++)
        cout<<previous[i]<< " ";
}
};
/*************************representation of graph using adjacency list
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
*//////////////////////
/****************code for dfs*//////////////////////


int main()
{
    int v;
    cout<<"enter number of vertices:";
    cin>>v;
    Graph g(v);
    g.insertIntoGraph();
    g.showGraph();
    cout<<"\n";
   /**** g.topologicalSort();
    cout<<"\n";
    g.dfs();*/
   // g.shortestPath();
     g.dijskastraWeightedShortestPath();
    return 0;
}
