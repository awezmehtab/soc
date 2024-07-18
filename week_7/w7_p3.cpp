#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    TrieNode* fail;
    vector<int> output;

    TrieNode() {
        fill(begin(children), end(children), nullptr);
        fail = nullptr;
    }
};

class AhoCorasick {
public:
    AhoCorasick() {
        root = new TrieNode();
    }

    void insert(const string& pattern, int index) {
        TrieNode* node = root;
        for (char c : pattern) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->output.push_back(index);
    }

    void build() {
        queue<TrieNode*> q;
        root->fail = root;
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            } else {
                root->children[i] = root;
            }
        }

        while (!q.empty()) {
            TrieNode* node = q.front();
            q.pop();

            for (int i = 0; i < 26; ++i) {
                if (node->children[i]) {
                    TrieNode* fail = node->fail;
                    while (!fail->children[i]) {
                        fail = fail->fail;
                    }
                    node->children[i]->fail = fail->children[i];
                    node->children[i]->output.insert(
                        node->children[i]->output.end(),
                        node->children[i]->fail->output.begin(),
                        node->children[i]->fail->output.end()
                    );
                    q.push(node->children[i]);
                }
            }
        }
    }

    vector<int> search(const string& text, int k) {
        vector<int> result(k, -1);
        TrieNode* node = root;
        for (int i = 0; i < (int)text.size(); ++i) {
            int idx = text[i] - 'a';
            while (!node->children[idx] && node != root) {
                node = node->fail;
            }
            node = node->children[idx];
            if (!node) node = root;
            for (int index : node->output) {
                if (result[index] == -1) {
                    result[index] = i - patterns[index].size() + 2;
                }
            }
        }
        return result;
    }

    void setPatterns(const vector<string>& pats) {
        patterns = pats;
    }

private:
    TrieNode* root;
    vector<string> patterns;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // cout << "Reading input..." << endl;
    string t;
    cin >> t;
    int k;
    cin >> k;
    vector<string> patterns(k);
    AhoCorasick ac;
    for (int i = 0; i < k; ++i) {
        cin >> patterns[i];
        ac.insert(patterns[i], i);
    }
    ac.setPatterns(patterns);
    // cout << "Building Aho-Corasick automaton..." << endl;
    ac.build();

    // cout << "Searching patterns..." << endl;
    vector<int> result = ac.search(t, k);
    for (int i = 0; i < k; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}