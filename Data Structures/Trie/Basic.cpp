#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    Node* next[26];
    // 1 Node contains 26 Node type pointers(next) that
    // can point to a new Node
    bool is_end;
    Node() {
        is_end = false;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {  // O(L)  [here L is the length of the word]
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) {
                cur->next[idx] = new Node();
                // NULL chara onno kauke point kortese mane 
                // oikhane index er equvalent ch ache
            }
            cur = cur->next[idx];
        }
        cur->is_end = true;
    }

    bool search(string word) { // O(L)
        Node* cur = root;
        for(auto ch: word) {
            int idx = ch - 'a';
            if(cur->next[idx] == NULL) return false;
            cur = cur->next[idx];
        }
        return cur->is_end;
        // For prefix search, just use "return true;"
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Trie t;
    t.insert("harvard");
    t.insert("yoyo");
    t.insert("kuet");
    cout << t.search("harvard") << '\n';
    cout << t.search("hard") << '\n';

    return 0;
}
