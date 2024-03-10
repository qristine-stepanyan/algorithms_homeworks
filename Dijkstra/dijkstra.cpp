#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9; 

struct Node
{
    int id;
    int distance;
    Node(int _id, int _distance) : id(_id), distance(_distance) {}
    bool operator>(const Node& other) const
    {
        return distance > other.distance;
    }
};

std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>>& graph, int source)
{
    int num_nodes = graph.size();
    std::vector<int> distances(num_nodes, INF);
    std::vector<bool> visited(num_nodes, false);
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    distances[source] = 0;
    pq.push(Node(source, 0));

    while(!pq.empty())
    {
        int u = pq.top().id;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(auto& neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if(distances[v] > distances[u] + weight)
            {
                distances[v] = distances[u] + weight;
                pq.push(Node(v, distances[v]));
            }
        }
    }
return distances;
}

int main()
{
    int num_nodes, num_edges;
    std::cin>> num_nodes>> num_edges;
    std::vector<std::vector<std::pair<int, int>>> graph(num_nodes);
    for (int i = 0; i < num_edges; ++i)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        graph[from].push_back(std::make_pair(to, weight));
    }

    int source;
    std::cin >> source;

    std::vector<int> shortest_distances = dijkstra(graph, source);

    std::cout << "Shortest distances from node " << source << " to other nodes:" << std::endl;
    for(int i = 0; i < num_nodes; ++i)
    {
        std::cout << "Node " << i << ": ";
        if(shortest_distances[i] == INF)
        {
            std::cout << "Infinity" << std::endl;
        }
        else
        {
            std::cout << shortest_distances[i] << std::endl;
        }
    }
return 0;
}
