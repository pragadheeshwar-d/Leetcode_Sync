class TrieNode {
    public:
    TrieNode* children[26] = {nullptr};
    int i = -1;
};

class Solution {
private:
    TrieNode* root;
    void insert(const string& word, int word_idx, const vector<string>& wordsContainer) {
        TrieNode* curr = root;
        
        if (curr->i == -1) {
            curr->i = word_idx;
        } else {
            int curr_best = curr->i;
            if (word.length() < wordsContainer[curr_best].length()) {
                curr->i = word_idx;
            }
        }

        for (int i = word.length() - 1; i >= 0; --i) {
            int idx = word[i] - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];

            if (curr->i == -1) {
                curr->i = word_idx;
            } else {
                int curr_best = curr->i;
                if (word.length() < wordsContainer[curr_best].length()) {
                    curr->i = word_idx;
                }
            }
        }
    }

    int search(const string& query) {
        TrieNode* curr = root;
        int last_valid_idx = root->i;

        for (int i = query.length() - 1; i >= 0; --i) {
            int idx = query[i] - 'a';
            if (!curr->children[idx]) {
                break;
            }
            curr = curr->children[idx];
            last_valid_idx = curr->i;
        }
        return last_valid_idx;
    }

    void clear(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) {
            if (node->children[i]) {
                clear(node->children[i]);
            }
        }
        delete node;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode();

        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        clear(root);
        return ans;
    }
};