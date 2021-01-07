#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

class Edge {
    public:
    int s, d, w;
    Edge(int source, int dest, int weight) {
        s = source;
        d = dest;
        w = weight;
    }
};

class Graph {

    public:
    int size;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<vector<int>> weight;

    Graph(int s) {
        size = s;
        adj = vector<vector<int>>(s);
        weight = vector<vector<int>>(s);
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    void addEdge(int v1, int v2, int w) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        weight[v1][v2] = w;
    }

    void removeEdge(int v1, int v2) {
        vector<int>::iterator i, j;
        for(i = adj[v1].begin(); i != adj[v1].end(); i++) {
            if(*i == v2)
                break;
        }
        adj[v1].erase(i);
        for(j = adj[v2].begin(); j != adj[v2].end(); j++) {
            if(*j == v1)
                break;
        }
        adj[v2].erase(j);
    }

    void removeVertex(int v) {
        for(int i : adj[v]) {
            removeEdge(i, v);
        }
        size--;
    }

    bool hasPath(int v1, int v2, vector<bool> &visited, string path) {
        visited[v1] = true;
        if(v1 == v2) {
            path.append(to_string(v1));
            cout<<path<<endl;
            return true;
        }
        for(int i : adj[v1]) {
            if(!visited[i]) {
                if(hasPath(i, v2, visited, path + to_string(v1)))
                    return true;
            }
        }
        return false;
    }

    void allPaths(int v1, int v2, vector<bool> &visited, string path) {
        visited[v1] = true;
        if(v1 == v2) {
            path.append(to_string(v1));
            cout<<path<<endl;
            return;
        }
        for(int i : adj[v1]) {
            if(!visited[i])
                allPaths(i, v2, visited, path + to_string(v1));
        }
    }

    void bfs(int s) {

        queue<int> q;
        vector<bool> visited(10, false);
        visited[s] = true;
        q.push(s);
        while(!q.empty()) {
            int n = q.front();
            cout<<n<<" ";
            q.pop();
            for(int i : adj[n]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void dfs(int s, vector<bool> &visited) {

        visited[s] = true;
        cout<<s<<" ";
        for(int i : adj[s]) {
            if(!visited[s]) {
                dfs(i, visited);
            }
        }
    }

    int gcc(vector<bool> &visited) {
        int ans = 0;
        for(int i = 0; i < size; i++) {
            if(!visited[i]) {
                dfs(i, visited);
                ans++;
            }
        }
        return ans;
    }

    bool hasCycleUndir(int s, vector<bool> &visited, int par) {
        visited[s] = true;
        for(int i : adj[s]) {
            if(!visited[i]) {
                if(hasCycleUndir(i, visited, s))
                    return true;
            }
            else if(i != par)
                return true;
        }
        return false;
    }

    bool hasCycleDir(int s, vector<bool> &visited, vector<bool> &recur) {
        visited[s] = true;
        recur[s] = true;
        for(int i : adj[s]) {
            if(!visited[i]) {
                if(hasCycleDir(i, visited, recur))
                    return true;
            }
            else if(recur[i] == true)
                return true;
        }
        recur[s] = false;
        return false;
    }

    int countCycles(int s, int par, vector<bool> &visited) {
        visited[s] = true;
        int ans = 0;
        for(int i : adj[s]) {
            if(!visited[i])
                ans += countCycles(i, s, visited);
            else if(i != par)
                ans++;
        }
        return ans;
    }

    void topologicalSort(int v, vector<bool> &visited, stack<int> &s) {
        visited[v] = true;
        for(int i : adj[v]) {
            if(!visited[i]) {
                topologicalSort(i, visited, s);
            }
        }
        s.push(v);
    }

    void topologicalSort_util() {
        vector<bool> visited(size, false);
        stack<int> s;
        for(int i = 0; i < size; i++) {
            if(!visited[i])
                topologicalSort(i, visited, s);
        }
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    void kahns_topological() {
        vector<int> inDegree(size, 0);
        vector<int> sorted;
        queue<int> q;
        for(int u = 0; u < size; u++)
            for(int v : adj[u])
                inDegree[v]++;
        for(int i = 0; i < size; i++)
            if(inDegree[i] == 0)
                q.push(i);
        int cnt = 0;
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            sorted.push_back(i);
            for(int v : adj[i]) {
                inDegree[v]--;
                if(inDegree[v] == 0)
                    q.push(v);
            }
            cnt++;
        }
        if(cnt != size) {
            cout<<"Invalid DAG\n";
            return;
        }
        for(int v = 0; v < size; v++)
            cout<<sorted[v]<<" ";
        cout<<endl;
    }

    Graph reverse() {
        Graph g(size);

        for(int i = 0; i < size; i++) {
            for(int v : adj[i]) {
                g.adj[v].push_back(i);
            }
        }
        return g;
    }

    void kosa_raju() {
        stack<int> s;
        vector<bool> visited(size, false);
        for(int i = 0; i < size; i++) {
            if(!visited[i])
                topologicalSort(i, visited, s);
        }
        Graph g = reverse();
        visited.assign(size, false);
        while(!s.empty()) {
            int v = s.top();
            s.pop();
            if(!visited[v]) {
                g.dfs(v, visited);
                cout<<endl;
            }
        }
    }

    void dijkstra() {

        vector<int> heap(size, INT32_MAX);
        vector<int> shortest_paths;
        vector<int> parent(size, 0);
        heap[0] = 0;
        for(int i = 0; i < size; i++) {
            int d = heap[0];
            heap.erase(heap.begin());
            shortest_paths.push_back(d);
            for(int v : adj[d]) {
                if(d + weight[d][v] < heap[v]) {
                    heap[v] = d + weight[d][v]; 
                    parent[v] = d;
                }
            }
        }
        for(int i = 0; i < size; i++)
            cout<<shortest_paths[i]<<" ";
    }

    void bellman_ford() {
        vector<int> dist(size, INT32_MAX);
        dist[0] = 0;

        for(int i = 0; i < size-1; i++) {
            for(Edge e : edges) {
                int source = e.s;
                int dest = e.d;
                int weight = e.w;
                if(dist[source] != INT32_MAX && dist[source] + weight < dist[dest])
                    dist[dest] = dist[source] + weight;
            }
        }

        // check -ve weight cycle
        for(Edge e : edges) {
                int source = e.s;
                int dest = e.d;
                int weight = e.w;
                if(dist[source] != INT32_MAX && dist[source] + weight < dist[dest]) {
                    cout<<"Negative weight cycle exists\n";
                    return;
                }
        }

        for(int d : dist)
            cout<<d<<" ";
        cout<<"\n";
    }

    void floyd_warshall() {
        vector<vector<int>> dist(size, vector<int>(size));

        for(int k = 0; k < size; k++) {
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
};

int main() {



    return 0;
}