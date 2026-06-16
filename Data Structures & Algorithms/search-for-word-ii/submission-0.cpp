class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
    };

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int index = ch - 'a';

            if(curr -> children[index] == nullptr) {
                curr -> children[index] = new TrieNode();
            }

            curr = curr -> children[index];
        }
        curr -> word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr, vector<string>& result) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        int idx = ch - 'a';

        if(!curr -> children[idx]) {
            return;
        }

        curr = curr -> children[idx];
        
        if(!curr -> word.empty()) {
            result.push_back(curr -> word);
            curr -> word = "";
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, curr, result);
        dfs(board, r - 1, c, curr, result);
        dfs(board, r, c + 1, curr, result);
        dfs(board, r, c - 1, curr, result);

        board[r][c] = ch;

    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for(const string& word : words) {
            insertWord(root, word);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                dfs(board, r, c, root, result);
            }
        }
        return result;
    }
};
