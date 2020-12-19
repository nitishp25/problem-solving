#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {

    public:
    int size;
    vector<vector<int>> adj;

    Graph(int s) {
        size = size;
        adj = vector<vector<int>>(s);
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    void removeEdge(int v1, int v2) {

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

};

int main() {



    return 0;
}