#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct Edge
{
    int source;
    int destination;
};

class DirectedUnweightedGraph
{
private:
    int numberOfVertices;
    void DFSRec(int vertex, vector<bool>& visited);
public:
    vector<vector<int>> adjacencyList;
    DirectedUnweightedGraph(int count);
    void addEdge(Edge edge);
    void BFS(); // Breadth First Search
    void DFS(int s, vector<int>& vis); // Depth First Search
};
DirectedUnweightedGraph::DirectedUnweightedGraph(int count) {
    adjacencyList.resize(count);
    numberOfVertices = count;
}

void DirectedUnweightedGraph::addEdge(Edge edge) {
    adjacencyList[edge.source].push_back(edge.destination);
}
void DirectedUnweightedGraph::BFS() {
    queue<int> q;
    vector<int> vis(numberOfVertices);
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';
        for (auto& v : adjacencyList[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    cout << endl;
}

void DirectedUnweightedGraph::DFS(int s, vector<int>& vis) {
    cout << s << ' ';
    vis[s] = 1;
    for (auto& u : adjacencyList[s]) if (!vis[u]) DFS(u, vis);
}

int main() {
    cout << "Graph 1:" << endl;
    DirectedUnweightedGraph graph(6);
    graph.addEdge({ 0, 1 });
    graph.addEdge({ 0, 2 });
    graph.addEdge({ 1, 2 });
    graph.addEdge({ 1, 3 });
    graph.addEdge({ 1, 4 });
    graph.addEdge({ 2, 4 });
    graph.addEdge({ 3, 5 });
    graph.addEdge({ 4, 3 });
    graph.addEdge({ 4, 5 });
    for (int i = 0; i < 6; i++) for (auto& v : graph.adjacencyList[i]) cout << i << ' ' << v << '\n';
    cout << "BFS: ";
    graph.BFS();
    cout << endl;
    cout << "DFS: ";
    vector<int> vis(6), vis2(7);
    graph.DFS(0, vis);
    cout << endl;

    cout << "Graph 2:" << endl;
    DirectedUnweightedGraph graph2(7);
    graph2.addEdge({ 0, 1 });
    graph2.addEdge({ 0, 2 });
    graph2.addEdge({ 1, 2 });
    graph2.addEdge({ 1, 3 });
    graph2.addEdge({ 1, 4 });
    graph2.addEdge({ 2, 4 });
    graph2.addEdge({ 3, 5 });
    graph2.addEdge({ 4, 3 });
    graph2.addEdge({ 4, 5 });
    graph2.addEdge({ 6, 0 });
    cout << "BFS: ";
    graph2.BFS();
    cout << endl;
    cout << "DFS: ";
    graph2.DFS(0, vis2);
    cout << endl;
    return 0;
}