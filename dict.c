#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main(int argc,const char * argv[]){
    
    trie * T=create_trie();
    char str[100];
    
    strcpy(str,"banana");
    
    trie_add_string(T,str);
 
    strcpy(str,"a");
    
    trie_add_string(T,str);
    
     strcpy(str,"baa");
    
    trie_add_string(T,str);
     strcpy(str,"ban");
    
    trie_add_string(T,str);
    
    char ouput[1000];
    show_trie(T);
    
    free_trie_node(T->root);
    
    return 0;
}