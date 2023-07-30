#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
public:
	vector<list<int> > adj;

	Graph(int v) {
		adj.resize(v);
	}

	void addEdge(int u, int v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir)
			adj[v].push_back(u);
	}

	void print() {
		for (int i = 0; i < adj.size(); ++i)
		{
			cout << i << "--> ";
			for (auto child : adj[i]) {
				cout  << child << ", ";
			}
			cout << endl;
		}
	}

};

int main() {

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(3, 2);

	g.print();

	return 0;
}
















