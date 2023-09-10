/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file queue_private.h
 *
 * \brief Private header for sorting algorithms.
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

#ifndef UPO_QUEUE_PRIVATE_H
#define UPO_QUEUE_PRIVATE_H

#include <stddef.h>
#include <upo/queue.h>

struct upo_queue_node_s{
    void *data;
    struct upo_queue_node_s *next;
};

typedef struct upo_queue_node_s upo_queue_node_t;

struct upo_queue_s{
    upo_queue_node_t *first;
    upo_queue_node_t *last;
    size_t size;
};

#endif /* UPO_QUEUE_PRIVATE_H */