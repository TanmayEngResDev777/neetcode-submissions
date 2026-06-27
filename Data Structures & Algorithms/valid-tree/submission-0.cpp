class Solution {
private:
    bool hasCycle(int node, int parent, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : graph[node]) {
            if(neighbor == parent) continue;
            if(visited[neighbor]) return true;
            if(hasCycle(neighbor, node, graph, visited)) return true;
        }

        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<vector<int>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        if(hasCycle(0, -1, graph, visited)) return false;

        for(bool v : visited) {
            if(!v) return false;
        }

        return true;
    }
};
