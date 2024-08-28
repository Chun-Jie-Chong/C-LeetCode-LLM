#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        node->children[i] = NULL;
    return node;
}

typedef struct {
    TrieNode *root;
} Trie;

Trie* trieCreate() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char *word) {
    TrieNode *node = obj->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index])
            node->children[index] = createNode();
        node = node->children[index];
        word++;
    }
    node->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char *word) {
    TrieNode *node = obj->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
        word++;
    }
    return node->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char *prefix) {
    TrieNode *node = obj->root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!node->children[index])
            return false;
        node = node->children[index];
        prefix++;
    }
    return true;
}

void trieFreeNode(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i])
            trieFreeNode(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    trieFreeNode(obj->root);
    free(obj);
}
