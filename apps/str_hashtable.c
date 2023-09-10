#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <upo/hashtable.h>
#include "str_hashtable.h"

int str_cmp(const void* a, const void* b) {

    const char **aa = (const char**)a;
    const char **bb = (const char**)b;

    return strcmp(*aa, *bb);
}

int main() {

    const char* strs[5] = {"Tre", "tigri", "contro", "tre", "tigri"};

    printf("Test find dups: ...");
    fflush(stdout);
    upo_strings_list_t l = upo_find_dups(strs, 5);

    assert(l != NULL);

    upo_strings_list_node_t* q;
    upo_strings_list_node_t* w;
    q = l;

    assert(strcmp(q->s, "tigri") == 0);
    assert(q->next == NULL);
    free(q->s);
    free(q);
    printf("OK\n");
    fflush(stdout);

    printf("Test find idups: ...");
    fflush(stdout);
    l = upo_find_idups(strs, 5, 1);
    assert(l != NULL);

    char* s[] = {"tigri", "tre"};
    q = l;

    int i = 0;
    while(q != NULL) {
        assert(strcmp(q->s, s[i]) == 0);
        w = q;
        q = q->next;
        free(w->s);
        free(w);
        i++;
    }

    printf("OK\n");
    fflush(stdout);

}

upo_strings_list_t upo_find_dups(const char**strs, size_t n) {

    upo_ht_sepchain_t ht;

    ht = upo_ht_sepchain_create(UPO_HT_SEPCHAIN_DEFAULT_CAPACITY, upo_ht_hash_str_kr2e, str_cmp);

    upo_strings_list_t l = NULL;

    for(size_t i = 0; i < n; i++) {
        
        if(upo_ht_sepchain_put(ht, &strs[i], &strs[i]) != NULL) {
            
            upo_strings_list_node_t* node = (upo_strings_list_node_t*)malloc(sizeof(upo_strings_list_node_t));
            
            node->s = malloc(sizeof(char)*(strlen(strs[i])+1));
            strcpy(node->s, strs[i]);
            node->next = l;
            l = node;
        }
    }

    upo_ht_sepchain_destroy(ht, 0);

    return l;
}

upo_strings_list_t upo_find_idups(const char**strs, size_t n, int ignore_case) {

    if(!ignore_case) {
        return upo_find_dups(strs, n);
    }
    else {
        char* s[n];

        for(size_t i = 0; i < n; i++) {
            s[i] = malloc(sizeof(char)*(strlen(strs[i])+1));
            strcpy(s[i], strs[i]);
            
            for(int j = 0; s[i][j] != '\0'; j++) {
                s[i][j] = tolower(s[i][j]);
            }
        }
        upo_strings_list_t l = upo_find_dups(s, n);
        
        for(size_t i = 0; i < n; i++)
            free(s[i]);
        
        return l;
    }

}