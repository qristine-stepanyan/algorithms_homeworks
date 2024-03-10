#include <iostream>
#include <vector>
#include <queue>

int shortestPathLength(const std::vector<std::vector<int>>& graph, int start, int end)
{
    std::vector<bool> visited(graph.size(), false);
    std::queue<std::pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;

    while(!q.empty())
    {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();

        if(current == end)
        {
            return distance;
        }

        for(int neighbor : graph[current])
        {
            if(!visited[neighbor])
            {
                q.push({neighbor, distance + 1});
                visited[neighbor] = true;
            }
        }
    }
    return -1; 
}
int main()
{
    std::vector<std::vector<int>> graph = {{1, 2, 3}, {4}, {4, 5}, {2}, {}, {6}, {}, {6, 8}, {}};
    
    int start1 = 0;
    int end1 = 4;
    int shortestLength1 = shortestPathLength(graph, start1, end1);
    std::cout << shortestLength1 << std::endl;

    int start2 = 0;
    int end2 = 6;
    int shortestLength2 = shortestPathLength(graph, start2, end2);
    std::cout << shortestLength2 << std::endl;
return 0;
}

