#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    Node* next[2];
    int cnt;

    Node() {
        cnt = 0;
        for(int i = 0; i < 2; i++) {
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

    void insert(int num) {
        Node* cur = root;
        cur->cnt++;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if(cur->next[bit] == NULL) {
                cur->next[bit] = new Node();
            }

            cur = cur->next[bit];
            cur->cnt++;
        }
    }

    void erase(int num) {
        Node* cur = root;
        cur->cnt--;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            cur = cur->next[bit];
            cur->cnt--;
        }
    }

    int get_max_xor(int num) {
        Node* cur = root;
        int ans = 0;

        for(int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int want = bit ^ 1;

            if(cur->next[want] != NULL && cur->next[want]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->next[want];
            }
            else {
                cur = cur->next[bit];
            }
        }

        return ans;
    }
};

Trie trie;
unordered_map<int, int> freq;

void add(int x) {
    trie.insert(x);
    freq[x]++;
}

void remove_one(int x) {
    if(freq[x] == 0) return;

    trie.erase(x);
    freq[x]--;
}

void remove_all(int x) {
    while(freq[x] > 0) {
        trie.erase(x);
        freq[x]--;
    }
}
