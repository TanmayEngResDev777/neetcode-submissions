class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> inDegree;

        for(const string& word : words) {
            for(char c : word) {
                if(graph.find(c) == graph.end()) {
                    graph[c] = unordered_set<char>();
                    inDegree[c] = 0;
                }
            }
        }

        for(size_t i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            
            if(w1.length() > w2.length() && w1.compare(0, w2.length(), w2) == 0) {
                return "";
            }

            size_t minlen = min(w1.length(), w2.length());
            for(size_t j = 0; j < minlen; ++j) {
                if(w1[j] != w2[j]) {
                    char u = w1[j];
                    char v = w2[j];

                    if(graph[u].find(v) == graph[u].end()) {
                        graph[u].insert(v);
                        inDegree[v]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto const& [ch, degree] : inDegree) {
            if(degree == 0) {
                q.push(ch);
            }
        }

        string result = "";
        while(!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for(char neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if(result.length() < graph.size()) {
            return "";
        }

        return result;
    }   
};
