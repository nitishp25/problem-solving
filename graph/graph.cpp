#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int s, vector<vector<int>> adj) {

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

void dfs(int s, vector<vector<int>> adj, vector<bool> &visited) {

    visited[s] = true;
    cout<<s<<" ";
    for(int i : adj[s]) {
        if(!visited[s]) {
            dfs(i, adj, visited);
        }
    }
}

int main() {



    return 0;
}