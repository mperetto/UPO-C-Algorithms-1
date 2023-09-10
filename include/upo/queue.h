/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/**
 * \file upo/queue.h
 *
 * \brief The Stack abstract data type.
 *
 * A Stack is an abstract data type that represents a container of elements such
 * that:
 * -# Each element is added over the top of the Stack (*push* operation).
 * -# Each element is removed from the top of the Stack (*pop* operation).
 * .
 * A Stack is often called a Last-in First-out (LIFO) container since the last
 * element that is added is the first to be removed.
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

#ifndef UPO_QUEUE_T
#define UPO_QUEUE_T

#include <stddef.h>

/** \brief The queue abstract data type. */
typedef struct upo_queue_s* upo_queue_t;

/** \brief Creates a new queue. */
upo_queue_t upo_queue_create();

/** \brief Destroy the given queue. */
void upo_queue_destroy(upo_queue_t queue, int destroy_data);

/** \brief Removes all elements from the given queue. */
void upo_queue_clear(upo_queue_t queue, int destroy_data);

/** \brief Insert the given element into the given queue. */
void upo_queue_enqueue(upo_queue_t queue, void *data);

/** \brief Removes the next element from the given queue. */
void upo_queue_dequeue(upo_queue_t queue, int destroy_data);

/** \brief Returns the next element from the given queue. */
void* upo_queue_peek(upo_queue_t queue);

/** \brief Returns the lenght of the given queue. */
size_t upo_queue_size(const upo_queue_t queue);

/** \brief Tells whether the given queue is empty. */
int upo_queue_is_empty(const upo_queue_t queue);

#endif /* UPO_QUEUE_T */
