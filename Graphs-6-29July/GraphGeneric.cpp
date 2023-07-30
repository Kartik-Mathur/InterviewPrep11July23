#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph {
public:
	unordered_map<T, list<T> > adj;

	void addEdge(T u, T v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir)
			adj[v].push_back(u);
	}

	void print() {
		for (auto p : adj)
		{
			cout << p.first << "--> ";
			for (auto child : p.second) {
				cout  << child << ", ";
			}
			cout << endl;
		}
	}

	void bfs(T src, T des) {

		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;
		unordered_map<T, int>  distance;
		parent[src] = src;
		visited[src] = true;
		distance[src] = 0;
		queue<T> q;

		q.push(src);

		while (!q.empty()) {
			T f = q.front();
			q.pop();
			cout << f << " ";
			for (auto ch : adj[f]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch]  = true;
					parent[ch] = f;
					distance[ch] =  distance[f] + 1;
				}
			}
		}

		for (auto p : distance) {
			cout << "Distance of " << p.first << "  from " << src << " : " << p.second << endl;
		}

		cout << "Path: ";
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;
	}

	void dfsHelper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;
		for (auto ch : adj[src]) {
			if (!visited[ch]) dfsHelper(ch, visited);
		}
	}

	void dfs(T src) {
		unordered_map<T, bool> visited;
		dfsHelper(src, visited);
		int cmt  = 1;
		for (auto p : adj) {
			if (!visited[p.first])
				dfsHelper(p.first, visited), cmt++;
		}

		cout << endl << "Components: " << cmt << endl;
	}

};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 1);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(5, 3);
	g.addEdge(15, 13);

	// g.print();
	// g.bfs(0, 5);
	g.dfs(0);


	return 0;
}
















