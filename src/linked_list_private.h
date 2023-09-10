/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file bst_private.h
 *
 * \brief Private header for the Binary Search Tree abstract data type.
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

#ifndef UPO_LINKED_LIST_PRIVATE_H
#define UPO_LINKED_LIST_PRIVATE_H

#include <upo/linked_list.h>

typedef struct upo_linked_list_node_s upo_linked_list_node_t;

struct upo_linked_list_s {
    upo_linked_list_node_t* head;
    upo_linked_list_comparator_t value_cmp;
};

struct upo_linked_list_node_s {
    void* value;
    upo_linked_list_node_t* next;
};

#endif