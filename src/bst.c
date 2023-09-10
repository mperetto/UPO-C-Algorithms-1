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

#include "bst_private.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**** EXERCISE #1 - BEGIN of FUNDAMENTAL OPERATIONS ****/


upo_bst_t upo_bst_create(upo_bst_comparator_t key_cmp)
{
    upo_bst_t tree = malloc(sizeof(struct upo_bst_s));
    if (tree == NULL)
    {
        perror("Unable to create a binary search tree");
        abort();
    }

    tree->root = NULL;
    tree->key_cmp = key_cmp;

    return tree;
}

void upo_bst_destroy(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear(tree, destroy_data);
        free(tree);
    }
}

void upo_bst_clear_impl(upo_bst_node_t *node, int destroy_data)
{
    if (node != NULL)
    {
        upo_bst_clear_impl(node->left, destroy_data);
        upo_bst_clear_impl(node->right, destroy_data);

        if (destroy_data)
        {
            free(node->key);
            free(node->value);
        }

        free(node);
    }
}

void upo_bst_clear(upo_bst_t tree, int destroy_data)
{
    if (tree != NULL)
    {
        upo_bst_clear_impl(tree->root, destroy_data);
        tree->root = NULL;
    }
}

void* upo_bst_node_create(void* key, void* value){
    upo_bst_node_t *new_node = malloc(sizeof(struct upo_bst_node_s));
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void* upo_bst_put(upo_bst_t tree, void *key, void *value)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    void *value_old = NULL;
    
    tree->root = upo_bst_put_impl(tree->root, key, value, value_old, upo_bst_get_comparator(tree));
    
    return value_old;
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_put_impl(upo_bst_node_t* node, void *key, void *value, void* value_old, upo_bst_comparator_t cmp){
    value_old = NULL;

    if(node == NULL){
        /*upo_bst_node_t *new_node = malloc(sizeof(struct upo_bst_node_s));
        new_node->key = key;
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;*/

        return upo_bst_node_create(key, value);
    }
    else if(cmp(node->key, key) == 1){
        node->left = upo_bst_put_impl(node->left, key, value, value_old, cmp);
    }
    else if(cmp(key, node->key) == 1){
        node->right = upo_bst_put_impl(node->right, key, value, value_old, cmp);
    }
    else{
        value_old = node->value;
        node->value = value;
    }
    return node;
}

void upo_bst_insert(upo_bst_t tree, void *key, void *value)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    tree->root = upo_bst_insert_impl(tree->root, key, value, upo_bst_get_comparator(tree));
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_insert_impl(upo_bst_node_t* node, void *key, void *value, upo_bst_comparator_t cmp){
    if(node == NULL){
        return upo_bst_node_create(key, value);
    }
    else if(cmp(node->key, key) == 1){
            node->left = upo_bst_insert_impl(node->left, key, value, cmp);
    }
    else if(cmp(key, node->key) == 1){
                node->right = upo_bst_insert_impl(node->right, key, value, cmp);
    }
    return node;
}

void* upo_bst_get(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    const upo_bst_node_t *node = upo_bst_get_impl(tree->root, key, upo_bst_get_comparator(tree));

    if(node != NULL){
        return node->value;
    }
    else{
        return NULL;
    }
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

const void* upo_bst_get_impl(const upo_bst_node_t* node, const void *key, upo_bst_comparator_t cmp){
    if(node == NULL){
        return NULL;
    }
    
    if(cmp(node->key, key) == 1){
        return upo_bst_get_impl(node->left, key, cmp);
    }
    else if(cmp(key, node->key) == 1){
        return upo_bst_get_impl(node->right, key, cmp);
    }
    else{
        return node;
    }
}

int upo_bst_contains(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(upo_bst_get_impl(tree->root, key, upo_bst_get_comparator(tree)) != NULL){
        return 1;
    }
    else{
        return 0;
    }
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_bst_delete(upo_bst_t tree, const void *key, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    tree->root = upo_bst_delete_impl(tree->root, key, destroy_data, upo_bst_get_comparator(tree));
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_delete_impl(upo_bst_node_t* node, const void *key, int destroy_data, upo_bst_comparator_t cmp){
    if(node == NULL){
        return NULL;
    }

    if(cmp(node->key, key) == 1){
        node->left = upo_bst_delete_impl(node->left, key, destroy_data, cmp);
    }
    else if(cmp(key, node->key) == 1){
        node->right = upo_bst_delete_impl(node->right, key, destroy_data, cmp);
    }
    else if(node->left != NULL && node->right != NULL){
        node = upo_bst_delete_2_impl(node, destroy_data, cmp);
    }
    else{
        node = upo_bst_delete_1_impl(node, destroy_data);
    }
    
    return node;
}

void* upo_bst_delete_1_impl(upo_bst_node_t* node, int destroy_data){
    upo_bst_node_t *x = node;

    if(node->left != NULL){
        node = node->left;
    }
    else if(node->right != NULL){
        node = node->right;
    }
    else{
        node = NULL;
    }

    if(destroy_data == 1){
        free(x->value);
        free(x->key);
    }
    free(x);
    return node;
}

void* upo_bst_delete_2_impl(upo_bst_node_t* node, int destroy_data, upo_bst_comparator_t cmp){
    upo_bst_node_t *m = upo_bst_max_impl(node->left);

    node->key = m->key;
    node->value = m->value;
    node->left = upo_bst_delete_impl(node->left, m->key, destroy_data, cmp);

    return node;
}

size_t upo_bst_size(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL)
        return 0;

    return upo_bst_size_impl(tree->root);
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

size_t upo_bst_size_impl(const upo_bst_node_t* node){
    if(node == NULL){
        return 0;
    }
    return 1 + upo_bst_size_impl(node->left) + upo_bst_size_impl(node->right);
}

size_t upo_bst_height(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    size_t h = upo_bst_height_impl(tree->root);
    
    return h;
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

size_t upo_bst_height_impl(const upo_bst_node_t* node){
    if(node == NULL || upo_bst_is_leaf(node)){
        return 0;
    }
    size_t height_left = upo_bst_height_impl(node->left);
    size_t height_right = upo_bst_height_impl(node->right);
    
    if(height_left > height_right){
        return 1 + height_left;
    }
    else{
        return 1 + height_right;
    }
    //return 1 + ((height_left > height_right) ? height_left : height_right);
}

int upo_bst_is_leaf(const upo_bst_node_t* node){
    if(node->left == NULL && node->right == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void upo_bst_traverse_in_order(const upo_bst_t tree, upo_bst_visitor_t visit, void *visit_arg)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */

    upo_bst_traverse_in_order_impl(tree->root, visit, visit_arg);

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_bst_traverse_in_order_impl(const upo_bst_node_t* node, upo_bst_visitor_t visit, void *visit_arg){
    if(node != NULL){
        upo_bst_traverse_in_order_impl(node->left, visit, visit_arg);
        visit(node->key, node->value, visit_arg);
        upo_bst_traverse_in_order_impl(node->right, visit, visit_arg);
    }
}

int upo_bst_is_empty(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL){
        return 1;
    }
    else{
        return 0;
    }
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}


/**** EXERCISE #1 - END of FUNDAMENTAL OPERATIONS ****/


/**** EXERCISE #2 - BEGIN of EXTRA OPERATIONS ****/


void* upo_bst_min(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL)
        return NULL;

    upo_bst_node_t *node = NULL;

    node = upo_bst_min_impl(tree->root);

    return node->key;
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_min_impl(upo_bst_node_t* node){
    
    if(node == NULL)
        return NULL;
    else if(node->left != NULL){
        return upo_bst_min_impl(node->left);
    }
    else{
        return node;
    }
}

void* upo_bst_max(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL)
        return NULL;

    upo_bst_node_t *node = NULL;

    node = upo_bst_max_impl(tree->root);

    return node->key;
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_max_impl(upo_bst_node_t* node){
    
    if(node == NULL){
        return NULL;
    }
    else if(node->right != NULL){
        return upo_bst_max_impl(node->right);
    }
    else{
        return node;
    }
}

void upo_bst_delete_min(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL){
        return;
    }
    
    tree->root = upo_bst_delete_min_impl(tree->root, destroy_data);

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_delete_min_impl(upo_bst_node_t* node, int destroy_data){

    if(node == NULL){
        return NULL;
    }
    else if(node->left != NULL){
        node->left = upo_bst_delete_min_impl(node->left, destroy_data);
    }
    else{

        upo_bst_node_t *w = node;

        if(destroy_data == 1){
            free(w->key);
            free(w->value);
        }

        upo_bst_node_t *nr;
        if(node->right != NULL){
            nr = node->right;
        }
        else{
            nr = NULL;
        }

        free(w);
        return nr;
    }
    return node;
}

void upo_bst_delete_max(upo_bst_t tree, int destroy_data)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL)
        return;

    tree->root = upo_bst_delete_max_impl(tree->root, destroy_data);
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_delete_max_impl(upo_bst_node_t* node, int destroy_data){
    
    if(node == NULL){
        return NULL;
    }
    else if(node->right != NULL){
        node->right = upo_bst_delete_max_impl(node->right, destroy_data);
    }
    else{
        upo_bst_node_t *w = node;

        if(destroy_data == 1){
            free(w->key);
            free(w->value);
        }

        upo_bst_node_t *nl;
        if(node->left != NULL){
            nl = node->left;
        }
        else{
            nl = NULL;
        }

        free(w);
        return nl;
    }
    return node;
}

void* upo_bst_floor(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL)
        return NULL;

    return upo_bst_floor_impl(tree->root, key, tree->key_cmp);
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void* upo_bst_floor_impl(const upo_bst_node_t* node, const void* key, upo_bst_comparator_t cmp){
    
    if(node == NULL){
        return NULL;
    }
    
    if(cmp(key, node->key) < 0){
        return upo_bst_floor_impl(node->left, key, cmp);
    }
    else if(cmp(key, node->key) > 0 && node->right != NULL){

        upo_bst_node_t *n_min = upo_bst_min_impl(node->right);

        if(cmp(key, n_min->key) >= 0){
            return upo_bst_floor_impl(node->right, key, cmp);
        }
        else{
            return node->key;
        }

        return upo_bst_floor_impl(node->right, key, cmp);
    }
    else{
        return node->key;
    }
}

void* upo_bst_ceiling(const upo_bst_t tree, const void *key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL){
        return NULL;
    }

    return upo_bst_ceiling_impl(tree->root, key, tree->key_cmp);
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}


void* upo_bst_ceiling_impl(const upo_bst_node_t* node, const void* key, upo_bst_comparator_t cmp){

    if(node == NULL){
        return NULL;
    }
    if(cmp(node->key, key) == 0){
        return node->key;
    }
    else if(cmp(node->key, key) < 1){
        return upo_bst_ceiling_impl(node->right, key, cmp);
    }
    else if(cmp(node->key, key) == 1 && node->left != NULL){
        upo_bst_node_t *n_max = upo_bst_max_impl(node->left);

        if(cmp(n_max->key, key) >= 0){
            return upo_bst_ceiling_impl(node->left, key, cmp);
        }
        else{
            return node->key;
        }
    }
    else{
        return node->key;
    }
}

upo_bst_key_list_t upo_bst_keys_range(const upo_bst_t tree, const void *low_key, const void *high_key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    if(tree == NULL || tree->root == NULL){
        return NULL;
    }
    
    upo_bst_key_list_t list = NULL;

    upo_bst_keys_range_impl(tree->root, &list, low_key, high_key, tree->key_cmp);

    return list;

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_bst_keys_range_impl(const upo_bst_node_t* node, upo_bst_key_list_t *list, const void *low_key, const void *high_key, upo_bst_comparator_t cmp){

    if(node == NULL)
        return;

    if(cmp(node->key, low_key) >= 0 && cmp(node->key, high_key) <= 0){
        upo_bst_key_list_node_t *k_node = malloc(sizeof(upo_bst_key_list_node_t));
        k_node->key = node->key;
        k_node->next = *list;
        *list = k_node;
        assert(list != NULL);
    }

    upo_bst_keys_range_impl(node->left, list, low_key, high_key, cmp);
    upo_bst_keys_range_impl(node->right, list, low_key, high_key, cmp);

}

upo_bst_key_list_t upo_bst_keys(const upo_bst_t tree)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */

    if(tree == NULL || tree->root == NULL){
        return NULL;
    }

    upo_bst_key_list_t list = NULL;

    upo_bst_keys_impl(tree->root, &list, tree->key_cmp);

    return list;

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_bst_keys_impl(const upo_bst_node_t* node, upo_bst_key_list_t *list, upo_bst_comparator_t cmp){

    if(node == NULL){
        return;
    }

    upo_bst_keys_impl(node->left, list, cmp);

    upo_bst_key_list_node_t *k_node = malloc(sizeof(upo_bst_key_list_node_t));
    k_node->key = node->key;
    k_node->next = *list;
    *list = k_node;

    upo_bst_keys_impl(node->right, list, cmp);
}

int upo_bst_is_bst(const upo_bst_t tree, const void *min_key, const void *max_key)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */

    if(tree == NULL) {
        return 1;
    }

    return upo_bst_is_bst_impl(tree->root, min_key, max_key, upo_bst_get_comparator(tree));

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

int upo_bst_is_bst_impl(const upo_bst_node_t* node, const void *min_key, const void *max_key, upo_bst_comparator_t cmp) {
    
    if(node == NULL) {
        return 1;
    }
    else if(cmp(node->key, min_key) < 1 || cmp(node->key, max_key) >= 1) {
        return 0;
    }

    return upo_bst_is_bst_impl(node->left, min_key, node->key, cmp) && upo_bst_is_bst_impl(node->right, node->key, max_key, cmp);

}

/**** EXERCISE #2 - END of EXTRA OPERATIONS ****/

/**** EXERCISE #MORE - BEGIN of EXTRA OPERATIONS ****/

size_t upo_bst_rank(const upo_bst_t tree, const void *key) {

    if(tree != NULL) {
        return upo_bst_rank_impl(tree->root, key, upo_bst_get_comparator(tree));
    }

    return 0;

}

size_t upo_bst_rank_impl(const upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    /*
    se nodo in esame < key +1 > visito parte sin e dest
    se nodo in esame >= key +0 > visito parte sin
    */

   if(node == NULL) {
       return 0;
    }
    else if(cmp(node->key, key) < 0) {
        size_t ts, td;
        ts = upo_bst_rank_impl(node->left, key, cmp);
        td = upo_bst_rank_impl(node->right, key, cmp);
        return (ts + td + 1);
    }
    else if(cmp(node->key, key) >= 0) {
        size_t ts;
        ts = upo_bst_rank_impl(node->left, key, cmp);
        return ts;
    }

    return 0;

}

void* upo_bst_predecessor(const upo_bst_t tree, const void *key) {

    if(tree != NULL) {
        return upo_bst_predecessor_impl(tree->root, key, upo_bst_get_comparator(tree));
    }

    return NULL;

}

void* upo_bst_predecessor_impl(const upo_bst_node_t *node, const void *key, upo_bst_comparator_t cmp) {
    
    if(node == NULL) {
        return NULL;
    }
    else if(cmp(node->key, key) < 0) {
        void *r;
        r = upo_bst_predecessor_impl(node->right, key, cmp);
        if(r == NULL) {
            return node->key;
        }
        else {
            return r;
        }
    }
    else if(cmp(node->key, key) >= 0) {
        void *r;
        r = upo_bst_predecessor_impl(node->left, key, cmp);
        if(r == NULL) {
            return NULL;
        }
        else {
            return r;
        }
    }
    else {
        return NULL;
    }

}

void* upo_bst_get_value_depth(const upo_bst_t tree,const void *key,long *depth) {
    if(tree != NULL) {
        void *v = upo_bst_get_value_depth_impl(tree->root, key, depth, upo_bst_get_comparator(tree));
        if(v == NULL) {
            *depth = -1;
            return v;
        }

        return v;
    }

    *depth = -1;
    return NULL;
}

void* upo_bst_get_value_depth_impl(const upo_bst_node_t *node, const void *key, long *depth, upo_bst_comparator_t cmp) {
    
    if(node == NULL) {
        return NULL;
    }
    else if(cmp(node->key, key) < 0) {
        *depth = *depth + 1;
        return upo_bst_get_value_depth_impl(node->right, key, depth, cmp);
    }
    else if(cmp(node->key, key) > 0) {
        *depth = *depth + 1;
        return upo_bst_get_value_depth_impl(node->left, key, depth, cmp);
    }
    else {
        return node->value;
    }
}

/**** EXERCISE #MORE - END of EXTRA OPERATIONS ****/

upo_bst_comparator_t upo_bst_get_comparator(const upo_bst_t tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    return tree->key_cmp;
}
