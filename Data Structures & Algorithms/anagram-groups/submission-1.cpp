class Solution {
public:
    /* Sorting Method
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string, vector<string>> groups;
        for(const auto& s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            groups[sortedS].push_back(s);
        }

        vector<vector<string>> res;
        for(auto& pair : groups){
            res.push_back(pair.second);
        }

        return res;
    }
    */

    /* Ordered Map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> groups;

        for(const string& s: strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }
            groups[count].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& entry: groups){
            result.push_back(entry.second);
        }
        return result;
    }
    */

    // Unordered Map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(const string& s: strs){
            vector<int> count(26,0);
            for(char c : s){
                count[c - 'a']++;
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for(const auto& entry: groups){
            result.push_back(entry.second);
        }
        return result;
    }
};
