#include <iostream>

#include <list>
#include <stack>

using namespace std;



class Graph
{
    int Vertices;
    list <int> *l;
    
    public:
    
    Graph(int V)
    {
        Vertices = V;
        l = new list <int> [Vertices];
    }
    
    void addEdge(int x, int y, bool directional)
    {
        l[x].push_back(y);
        
        if(!directional)
        {
            l[y].push_back(x);
        }
    }

    
    
    
    
    bool cycle_helper(int node, bool *visited, int *parent)
    {
        
        visited[node] = true;
        
        for(auto neigh: l[node])
        {
            if(visited[neigh] == true and neigh!=parent[node])
            {
                return true;
            }
            
            else if(visited[neigh] == false)
            {
                parent[neigh] = node;
                bool cycle_mila = cycle_helper(neigh,visited,parent);
                
                
                if(cycle_mila == true)
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
    
    
    
    
    bool contain_cycle()
    {
        bool *visited = new bool[Vertices];
        int *parent = new int[Vertices];
        
        for(int i = 0; i < Vertices; i++)
        {
            visited[i] = false;
            parent[i] = i-1;
        }
        
        
        return cycle_helper(0,visited,parent);
    }
    
    
    
};

int main()
{
    Graph G(5);
    
    G.addEdge(1,0,false);
    G.addEdge(0,4,false);
    G.addEdge(4,3,false);
    G.addEdge(3,2,false);
    G.addEdge(2,1,false);
    
    if(G.contain_cycle() == true)
    {
        cout << "Undirected Graph has a cycle. ";
    }
    
    else
    {
        cout << "Undirected Graph dont have a cycle. ";
    }
    
    return 0;
}

