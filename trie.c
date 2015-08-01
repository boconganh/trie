#include "trie.h"
#include <assert.h>
#include <stdio.h>

trie_node * create_trie_node(){
    trie_node *node=(trie_node*)malloc(sizeof(trie_node));
    int i;
    for(i=0;i<MAXCHAR;i++){
        node->child[i]=NULL;
    }
    return node;
    
};
trie * create_trie(){
    trie * TRIE=(trie*) malloc(sizeof(trie));
    TRIE->root=create_trie_node();
    return TRIE;
}

void free_trie_node(trie_node *node){
    int i;
    if(!node) return;
    for(i=0;i<MAXCHAR;++i){
        free_trie_node(node->child[i]);
    }
    free(node);
}

void trie_add_string(trie *TRIE,char * str){
    
    trie_node *cur_node=TRIE->root;
    assert(TRIE->root);
    char cur_char;
    int i=0;
    while(str[i]){
        //printf("%c\n",str[i]);
        if(!cur_node->child[str[i]]){
            cur_node->child[str[i]]=create_trie_node();
        }
        if(!str[i+1]){
            cur_node->child[str[i]]->is_leaf=true;   
        }
        cur_node=cur_node->child[str[i]];
        
        i++;
    }
}


static void _show_trie_dfs(trie_node *node,char *output,int depth){
    if(!node) return;
    if(node->is_leaf){
        output[depth]='\0';
        puts(output);
    }
    int c;
    
    for(c=0;c<MAXCHAR;++c){
        output[depth]=c;
        _show_trie_dfs(node->child[c],output,depth+1);
    }
}
void show_trie(trie *Trie){
    
    char *output=(char *)malloc(200);
    _show_trie_dfs(Trie->root,output,0);
    free(output);
}