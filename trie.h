
#ifndef _trie_h_
#define _trie_h_

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAXCHAR 256

typedef struct trie_node trie_node;
typedef struct trie trie;
struct trie_node{
    bool is_leaf;
    trie_node * child[MAXCHAR];
};

struct trie{
    trie_node *root;  
};

trie_node * create_trie_node();
trie * create_trie();
void free_trie_node(trie_node *node);

void trie_add_string(trie * TRIE,char * str);
void show_trie(trie *Trie);
#endif /* _trie_h_ */