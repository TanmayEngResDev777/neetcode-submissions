class Solution {
private:
    bool hasCycle(int course, vector<vector<int>>& graph, vector<int>& state) {
        if(state[course] == 1) return true;
        if(state[course] == 2) return false;

        state[course] = 1;
        for(int neighbor : graph[course]) {
            if(hasCycle(neighbor, graph, state)) {
                return true;
            }
        } 
        state[course] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); 
        for(const auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph[prereq].push_back(course);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; ++i) {
            if(state[i] == 0){
                if(hasCycle(i, graph, state)){
                    return false;
                }
            } 
        }
        
        return true;
    }
};