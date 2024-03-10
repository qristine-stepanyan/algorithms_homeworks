#include <iostream>
#include <vector>

const int white = 0;
const int gray = 1;
const int black = 2;

bool hasCycleDFS(int node,const std::vector<std::vector<int>>& graph,std::vector<int>& colors)
{
    colors[node] = gray;
    
    for(int neighbor : graph[node])
    {
        if(colors[neighbor] == gray)
        {
            return true;
        }
        if(colors[neighbor] == white && hasCycleDFS(neighbor,graph,colors))
        {
            return true;
        }
    }
    colors[node] = black; 
    return false;
}

bool hasCycle(const std::vector<std::vector<int>>& graph)
{
    std::vector<int> colors(graph.size(),white);
    
    for(int node = 0; node < graph.size(); ++node)
    {
        if(colors[node] == white && hasCycleDFS(node,graph,colors))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> graph1 = {{1, 2, 3}, {4}, {4, 5}, {2}, {}, {6}, {}, {6, 8}, {}};
    
    if(hasCycle(graph1))
    {
        std::cout << "Graph 1 contains cycles." << std::endl;
    }
    else
    {
        std::cout << "Graph 1 does not contain cycles." << std::endl;
    }

    std::vector<std::vector<int>> graph2 = {{1, 2}, {3}, {4}, {0}, {}};
    if (hasCycle(graph2))
    {
        std::cout << "Graph 2 contains cycles." << std::endl;
    }
    else
    {
        std::cout << "Graph 2 does not contain cycles." << std::endl;
    }
    
    std::vector<std::vector<int>> graph3 = {{1, 2}, {3, 4}, {4}, {0}, {2}};
    if(hasCycle(graph3))
    {
        std::cout << "Graph 3 contains cycles." << std::endl;
    }
    else
    {
        std::cout << "Graph 3 does not contain cycles." << std::endl;
    }

    std::vector<std::vector<int>> graph4 = {{1}, {2}, {3}, {4}, {}};
    if(hasCycle(graph4))
    {
        std::cout << "Graph 4 contains cycles." << std::endl;
    }
    else
    {
        std::cout << "Graph 4 does not contain cycles." << std::endl;
    }
    
return 0;
}

 