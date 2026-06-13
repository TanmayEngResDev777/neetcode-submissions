class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    bool searchHelper(string& word, int index, TrieNode* current) {
        if(index == word.length()) return current -> isEndOfWord;
        char ch = word[index];

        if(ch == '.') {
            for(int i = 0; i < 26; i++) {
                if(current -> children[i] != nullptr) {
                    if(searchHelper(word, index + 1, current -> children[i])) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int childIndex = ch - 'a';
            if(current -> children[childIndex] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, current -> children[childIndex]);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for(char ch : word) {
            int index = ch - 'a';

            if(current -> children[index] == nullptr) {
                current -> children[index] = new TrieNode();
            }

            current = current -> children[index];
        }
        current -> isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
