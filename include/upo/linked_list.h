/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file upo/bst.h
 *
 * \brief The Binary Search Tree (BST) abstract data type.
 *
 * Trees are nonlinear containers where data is structured according to
 * hierarchical organization.
 * Trees are made of nodes that are connected to each other according to a
 * parent-child relationship.
 * Binary Search Trees are Binary Trees where:
 * - Each node has a key and an associated value (possibly, the
 *   key itself),
 * - The key in node v is greater than the keys in all nodes in the
 *   left subtree of v, and
 * - The key in node v is less than the keys in all nodes in the right
 *   subtree of v.
 * .
 *
 * \author Your Name
 *
 * \copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 *  This file is part of UPOalglib.
 *
 *  UPOalglib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  UPOalglib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UPO_LINKED_LIST_H
#define UPO_LINKED_LIST_H

#include <stdio.h>

typedef struct upo_linked_list_s* upo_linked_list_t;
typedef int (*upo_linked_list_comparator_t)(const void*, const void*);
typedef void (*upo_linked_list_print_t)(FILE* f, const void* el);

upo_linked_list_t upo_linked_list_create(upo_linked_list_comparator_t value_cmp);

void upo_linked_list_insert_head(upo_linked_list_t l, void* el);

void* upo_linked_list_search(upo_linked_list_t l, void* el);

void upo_linked_list_print(upo_linked_list_t l, FILE* f, upo_linked_list_print_t print);

#endif