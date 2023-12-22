#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define V 9

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void printGraph(vector<pair<int, int>> adj[]) {
	int v, w;
	
	for (int u = 0; u < V; u++) {
		cout << "Vertice: " << u << " has an edge with:" << endl;

		for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
			v = it->first;
			w = it->second;
			cout << "\t Node " << v << " with edge weight " << w << endl;
		}
		cout << endl;
	}
}

vector<int> graphBFS(vector<pair<int, int>> adj[]) {	
	queue<int> verticesSeen;
	vector<int> verticesBfs;

	verticesSeen.push(0);
	verticesBfs.push_back(0);

	while (!verticesSeen.empty()) {
		int curr = verticesSeen.front();
		verticesSeen.pop();

		for (auto neighbour : adj[curr]) {
			int nextNode = neighbour.first;
			int edgeWeight = neighbour.second;

			if (find(verticesBfs.begin(), verticesBfs.end(), nextNode) == verticesBfs.end()) {
				verticesSeen.push(nextNode);
				verticesBfs.push_back(nextNode);
			}
		}
	}
	return verticesBfs;
}

int main() {
	vector<pair<int, int>> adj[V];
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
	printGraph(adj);
	vector<int> resBfs = graphBFS(adj);
	
	cout << "BFS: " << endl;
	for (auto i : resBfs) {
 		cout << i << ' ';
	}
	return 0;
}
    
}