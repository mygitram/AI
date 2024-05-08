#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<list>
using namespace std;

class Graph
{
    public:
    map<int,list<int>> adjList;
    map<int,bool> visited;
    queue<int> q;

    void addEdge(int src,int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    void DFS(int node)
    {
        visited[node] = true;
        cout<<node;
        for(int i:adjList[node])
        {
            if(!visited[i]) DFS(i);
        }
    }
    void BFS(int start)
    {
        q.push(start);
        visited[start] = true;
        BFSSupport();
    }
    void BFSSupport()
    {
        if(q.empty()) return;

        int node = q.front();
        q.pop();
        cout<<node<<endl;
        for(int i:adjList[node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
        BFSSupport();
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,6);

    cout<<"BFS: ";
    // g.BFS(0);
    cout<<"DFS: ";
    g.DFS(0);
    return 0;
}