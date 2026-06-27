class Solution {
private:
    void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;

        for(int neighbor : graph[node]) {
            if(!visited[neighbor]){
                dfs(neighbor, graph, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int componentCount = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                componentCount++;
                dfs(i, graph, visited);
            }
        }

        return componentCount;
    }
};
