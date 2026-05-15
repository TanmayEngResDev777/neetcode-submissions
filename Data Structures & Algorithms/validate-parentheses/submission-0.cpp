class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s){
            if(mapping.count(c)) {
                if(!stack.empty() && stack.top() == mapping[c]){
                    stack.pop();
                } else {
                    return false;
                }
            }

            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
