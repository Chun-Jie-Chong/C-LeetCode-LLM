#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
} TrieNode;

typedef struct Trie {
    TrieNode *root;
} Trie;

TrieNode* createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char * word) {
    TrieNode *node = obj->root;
    while (*word) {
        if (!node->children[*word - 'a'])
            node->children[*word - 'a'] = createNode();
        node = node->children[*word - 'a'];
        word++;
    }
    node->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char * word) {
    TrieNode *node = obj->root;
    while (*word) {
        if (!node->children[*word - 'a'])
            return false;
        node = node->children[*word - 'a'];
        word++;
    }
    return node != NULL && node->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    TrieNode *node = obj->root;
    while (*prefix) {
        if (!node->children[*prefix - 'a'])
            return false;
        node = node->children[*prefix - 'a'];
        prefix++;
    }
    return true;
}

void trieFree(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; i++) {
        trieFree(node->children[i]);
    }
    free(node);
}
