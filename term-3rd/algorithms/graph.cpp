#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include <string>
using namespace std;

void addEdge(vector<pair<int, int>> *adj_list, int u, int v, int wt)
{
    adj_list[u].push_back(make_pair(v, wt));
}

void printGraph(vector<pair<int, int>> *adj, int v)
{
    for (int u = 0; u < v; u++)
    {
        cout << "Vertice: " << u << " has an edge with: " << endl;

        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            cout << "\t Node " << it->first << " with edge weight " << it->second << endl;
        }
        cout << endl;
    }
}

vector<int> graphBFS(vector<pair<int, int>> adj_list[])
{
    queue<int> vertices_seen;
    vector<int> vertices_res;

    vertices_seen.push(0);
    vertices_res.push_back(0);


    while (!vertices_seen.empty())
    {
        int cur = vertices_seen.front();
        vertices_seen.pop();

        for (auto neighbour : adj_list[cur])
        {
            int node_next = neighbour.first;

            if (find(vertices_res.begin(), vertices_res.end(), node_next) == vertices_res.end())
            {
                vertices_seen.push(node_next);
                vertices_res.push_back(node_next);
            }
        }
    }
    return vertices_res;
}

void graphDFS(vector<pair<int, int>> adj_list[], int cur, vector<bool> &vertices_seen, vector<int> &vertices_res)
{
    vertices_seen[cur] = true;
    vertices_res.push_back(cur);

    for (auto neighbour : adj_list[cur])
    {
        int node_next = neighbour.first;

        if (!vertices_seen[node_next])
        {
            graphDFS(adj_list, node_next, vertices_seen, vertices_res);
        }
    }
    return;
}

void primMST(vector<pair<int, int>> adj_list[], int v)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(v, INT_MAX);
    vector<bool> inMST(v, false);
    vector<int> parent(v, -1);

    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto it = adj_list[u].begin(); it != adj_list[u].end(); it++)
        {
            int v = it->first;
            int weight = it->second;

            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST: " << endl;
    for (int i = 1; i < v; ++i)
    {
        cout << parent[i] << " -> " << i << " weight: " << key[i] << endl;
    }
}

void dijkstra(vector<pair<int, int>> adj_list[], int V, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (auto it = adj_list[u].begin(); it != adj_list[u].end(); it++)
        {
            int v = it->first;
            int weight = it->second;

            if (!visited[v] && dist[u] != INT_MAX && dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Dijkstra: " << endl;
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
	vector<pair<int, int>> *adj = new vector<pair<int, int>>[9];
	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
	addEdge(adj, 1, 7, 11);
	addEdge(adj, 1, 2, 8);
	addEdge(adj, 7, 8, 7);
	addEdge(adj, 6, 7, 1);
	addEdge(adj, 2, 8, 2);
	addEdge(adj, 6, 8, 6);
	addEdge(adj, 2, 3, 7);
	addEdge(adj, 2, 5, 4);
	addEdge(adj, 5, 6, 2);
	addEdge(adj, 3, 5, 14);
	addEdge(adj, 3, 4, 9);
	addEdge(adj, 4, 5, 10);
	printGraph(adj, 9);
}