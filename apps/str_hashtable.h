#ifndef UPO_STR_HASHTABLE_H
#define UPO_STR_HASHTABLE_H

#include <stdlib.h>

typedef struct upo_strings_list_node_s upo_strings_list_node_t;

struct upo_strings_list_node_s {
    char* s;
    upo_strings_list_node_t* next;
};

typedef upo_strings_list_node_t* upo_strings_list_t;

upo_strings_list_t upo_find_dups(const char**strs, size_t n);
upo_strings_list_t upo_find_idups(const char**strs, size_t n, int ignore_case);

#endif