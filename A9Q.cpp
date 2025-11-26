#include <bits/stdc++.h>
using namespace std;

// Graph class supporting multiple algorithms
class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // (neighbor, weight)
    vector<tuple<int,int,int>> edges; // (weight, u, v)

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w = 1, bool undirected = true) {
        adj[u].push_back({v, w});
        edges.push_back({w, u, v});
        if (undirected) adj[v].push_back({u, w});
    }

    // 1. Breadth First Search (BFS)
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while(!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for(auto &nbr : adj[node]) {
                if(!visited[nbr.first]) {
                    visited[nbr.first] = true;
                    q.push(nbr.first);
                }
            }
        }
        cout << endl;
    }

    // 2. Depth First Search (DFS)
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";
        for(auto &nbr : adj[node]) {
            if(!visited[nbr.first])
                DFSUtil(nbr.first, visited);
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Disjoint Set for Kruskal
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) : parent(n), rank(n,0) {
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int x) {
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }
        void unite(int a, int b) {
            a=find(a); b=find(b);
            if(a!=b) {
                if(rank[a]<rank[b]) swap(a,b);
                parent[b]=a;
                if(rank[a]==rank[b]) rank[a]++;
            }
        }
    };

    // 3a. Kruskal's Minimum Spanning Tree
    void KruskalMST() {
        sort(edges.begin(), edges.end());
        DSU dsu(V);
        int mstWeight = 0;

        cout << "Kruskal MST Edges:\n";
        for(auto &e : edges) {
            int w,u,v;
            tie(w,u,v) = e;
            if(dsu.find(u) != dsu.find(v)) {
                dsu.unite(u,v);
                mstWeight += w;
                cout << u << " - " << v << " : " << w << endl;
            }
        }
        cout << "Total Weight: " << mstWeight << endl;
    }

    // 3b. Prim's Minimum Spanning Tree
    void PrimMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        key[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int totalWeight = 0;

        cout << "Prim MST Order:\n";
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if(inMST[u]) continue;
            inMST[u] = true;
            totalWeight += key[u];

            for(auto &nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;
                if(!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.push({key[v], v});
                }
            }
        }
        cout << "Total Weight: " << totalWeight << endl;
    }

    // 4. Dijkstra's Shortest Path
    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if(d > dist[u]) continue;
            for(auto &nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra Shortest Paths from " << src << ":\n";
        for(int i=0;i<V;i++)
            cout << "Vertex " << i << " -> Distance = " << dist[i] << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0,1,4);
    g.addEdge(0,2,3);
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,4);
    g.addEdge(3,4,2);
    g.addEdge(4,5,6);

    g.BFS(0);
    g.DFS(0);

    g.KruskalMST();
    g.PrimMST();
    g.Dijkstra(0);

    return 0;
}
