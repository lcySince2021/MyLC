#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

// bool dfs(std::vector<std::vector<int>> &adj, std::vector<bool> &visited, int source, int dest) {
//     if (source == dest) return true;
//     visited[source] = true;
//     for (auto next : adj[source]) {
//         if (!visited[next] && dfs(adj, visited, next, dest)) return true;
//     }
//     return false;
// }

// bool Test(int n, std::vector<std::vector<int>>& edges, int source, int dest) {
//     std::vector<std::vector<int>> adj(n);
//     for (auto edge : edges) {
//         int x = edge[0];
//         int y = edge[1];
//         adj[x].emplace_back(y);
//         adj[y].emplace_back(x);
//     }
//     std::vector<bool> visited(n, false);
//     return dfs(adj, visited, source, dest);
// }
//

bool Test(int n, std::vector<std::vector<int>>& edges, int source, int dest) {
    std::vector<std::vector<int>> adj(n);
    for (auto edge : edges) {
        int x = edge[0];
        int y = edge[1];
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    std::vector<bool> visited(n, false);
    std::queue<int> que;
    visited[source] = true;
    que.emplace(source);
    while (!que.empty()) {
        auto tmp = que.front();
        que.pop();
        if (tmp == dest) break;
        for (auto next : adj[tmp]) {
            if (!visited[next]) {
                que.emplace(next);
                visited[next] = true;
            }
        }

    }
    return visited[dest];

}

class UnionFind {
public:
    UnionFind(int n) {
       parents_ = std::vector<int>(n);
       rank_ = std::vector<int>(n);
       for (int i = 0; i < n; ++i) {
           parents_[i] = i;
       }
    }

    int Find(int x) {
        if (parents_[x] != x) {
            parents_[x] = Find(parents_[x]);
        }
        return parents_[x];
    }

    void Merge(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry) {
            if (rank_[rx] > rank_[ry]) {
                parents_[ry] = rx;
            } else if (rank_[rx] < rank_[ry]) {
                parents_[rx] = ry;
            } else {
                parents_[ry] = rx;
                rank_[rx]++;
            }
        }
    }

    bool Connect(int x, int y) {
        return Find(x) == Find(y);
    }

private:
    std::vector<int> parents_;
    std::vector<int> rank_;
};

int main(int argc, char** argv) {
    std::vector<std::vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
    // auto res = Test(3, vec, 0, 2);
    UnionFind uf(3); // 定点数量
    for (auto edge : edges) {
        uf.Merge(edge[0], edge[1]);
    }
    auto res = uf.Connect(0, 2);
    if (res) printf("123\n");
    return 0;
}
