#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {

    public:
    int size;
    vector<vector<int>> adj;

    Graph(int s) {
        size = s;
        adj = vector<vector<int>>(s);
    }

    void addEdge(int v1, int v2) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
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