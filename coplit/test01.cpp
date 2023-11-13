
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 定义边结构体
struct Edge {
    int from, to, weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};

// 定义最小堆
struct MinHeap {
    bool operator() (const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

// Prim算法
vector<Edge> prim(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<Edge> res;
    vector<bool> visited(n, false);
    priority_queue<Edge, vector<Edge>, MinHeap> pq;
    visited[0] = true;
    for (int i = 0; i < n; i++) {
        if (graph[0][i] != 0) {
            pq.push(Edge(0, i, graph[0][i]));
        }
    }
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if (visited[e.to]) {
            continue;
        }
        visited[e.to] = true;
        res.push_back(e);
        for (int i = 0; i < n; i++) {
            if (graph[e.to][i] != 0 && !visited[i]) {
                pq.push(Edge(e.to, i, graph[e.to][i]));
            }
        }
    }
    return res;
}

// Kruskal算法
vector<Edge> kruskal(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<Edge> res;
    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back(Edge(i, j, graph[i][j]));
            }
        }
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    for (Edge e : edges) {
        int root1 = find(parent, e.from);
        int root2 = find(parent, e.to);
        if (root1 != root2) {
            res.push_back(e);
            parent[root1] = root2;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    vector<Edge> primRes = prim(graph);
    vector<Edge> kruskalRes = kruskal(graph);
    cout << "Prim Algorithm:" << endl;
    for (Edge e : primRes) {
        cout << e.from << " - " << e.to << " : " << e.weight << endl;
    }
    cout << endl;
    cout << "Kruskal Algorithm:" << endl;
    for (Edge e : kruskalRes) {
        cout << e.from << " - " << e.to << " : " << e.weight << endl;
    }
    return 0;
}
