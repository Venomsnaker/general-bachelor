#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include <string>
#include <fstream>
#include <sstream>
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

void writeGraphToTxt(string filePath, vector<pair<int, int>> *adj, int v) {
    ofstream outfile(filePath);
    outfile << v << endl;; 

    for (int u = 0; u < v; u++) {
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            outfile << u << " " << it->first << " " << it->second << endl;
        }
    }
    outfile.close();
    return;
}

void constructGraphFromTxt(string filePath, vector<pair<int, int>> *&adj_list, int &v) {
    fstream infile(filePath);

    if (infile.is_open()) {
        string line;

        getline(infile, line);
        istringstream iss(line);
        iss >> v;
        adj_list = new vector<pair<int, int>>[v];

        while (getline(infile, line))
        {
            istringstream iss(line);
            int from, to, weight;

            if ((iss >> from >> to >> weight))
            {
                addEdge(adj_list, from, to, weight);
            }
        }
        infile.close();
    }
    return;
}

int main() {
    int v = -1, options = -1, again = 1;
    string answer = "";
    vector<pair<int, int>> *adj_list;

    while (again) {
        system("cls");
        cout << "0: End the program" << endl;
        cout << "1: Create a graph from txt file" << endl;
        cout << "2: Traverse BFS" << endl;
        cout << "3: Traverse DFS" << endl;
        cout << "4: Construct MST (Prim)" << endl;
        cout << "5: Get Dijkstra table" << endl;
        cout << "6: Print the graph" << endl;

        do 
        {
            cout << "Insert the option: " << endl;
            cin >> options;
        } while (options < 0 || options > 6);

        switch (options)
        {
        case 1: {
            constructGraphFromTxt("graph.txt", adj_list, v);
            break;
        }
        case 2: {
            vector<int> res_bfs = graphBFS(adj_list);

            cout << "BFS: " << endl;
            for (auto i : res_bfs)
            {
                cout << i << ' ';
            }
            cout << endl;
            break;
        }
        case 3: {
            vector<int> res_dfs;
            vector<bool> visited(v, false);
            graphDFS(adj_list, 0, visited, res_dfs);

            cout << "DFS: " << endl;
            for (auto i : res_dfs)
            {
                cout << i << ' ';
            }
            cout << endl;
            break;
        }
        case 4: {
            primMST(adj_list, v);
            cout << endl;
            break;
        }
        case 5: {
            dijkstra(adj_list, v, 0);
            break;
        }
        case 6: {
            printGraph(adj_list, v);
            break;
        }
        default:
            break;
        }

        do 
        {
            cout << "Do you wish to continue (y/n)" << endl;
            cin >> answer;

        } while (answer != "y" && answer != "n");

        if (answer == "n") {
            again = 0;
        }
    }
}
