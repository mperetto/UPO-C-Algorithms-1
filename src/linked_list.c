/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/*
 * Copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 * This file is part of UPOalglib.
 *
 * UPOalglib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * UPOalglib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "linked_list_private.h"
#include <stdio.h>
#include <stdlib.h>
#include <upo/error.h>

upo_linked_list_t upo_linked_list_create(upo_linked_list_comparator_t value_cmp) {
    upo_linked_list_t list = malloc(sizeof(struct upo_linked_list_node_s));
    
    if(list == NULL) {
        perror("Memory alloc Error");
        abort();
    }

    list->head = NULL;
    list->value_cmp = value_cmp;
    
    return list;
}

void upo_linked_list_insert_head(upo_linked_list_t l, void* el) {

    upo_linked_list_node_t *n = malloc(sizeof(struct upo_linked_list_node_s));

    n->value = el;
    n->next = l->head;
    l->head = n;

}

void* upo_linked_list_search(upo_linked_list_t l, void* el) {
    upo_linked_list_node_t *n = l->head;
    upo_linked_list_comparator_t cmp = l->value_cmp;

    assert(n->value != NULL);
    assert(cmp != NULL);
    
    while(n != NULL) {

        if(cmp(el, n->value) == 0)
            return n->value;

        n = n->next;
    }

    return NULL;
}

void upo_linked_list_print(upo_linked_list_t l, FILE* f, upo_linked_list_print_t print) {
    upo_linked_list_node_t *n = l->head;

    fprintf(f, "[");
    while(n != NULL){
        print(f, n->value);
        fprintf(f, ", ");
        n = n->next;
    }
    fprintf(f, "]\n");
}