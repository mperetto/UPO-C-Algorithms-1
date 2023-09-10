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

#include "queue_private.h"
#include <stdlib.h>
#include <upo/error.h>

upo_queue_t upo_queue_create()
{
    upo_queue_t queue = malloc(sizeof(struct upo_queue_s));

    if(queue == NULL){
        fprintf(stderr, "Unable to create a queue\n");
        abort();
    }

    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    return queue;
}

void upo_queue_destroy(upo_queue_t queue, int destroy_data)
{    
    if(queue != NULL){
        upo_queue_clear(queue, destroy_data);
        free(queue);
    }

}

void upo_queue_clear(upo_queue_t queue, int destroy_data)
{
    if(queue != NULL){
        while(!upo_queue_is_empty(queue)){
            upo_queue_dequeue(queue, destroy_data);
        }
    }
}

void upo_queue_enqueue(upo_queue_t queue, void *data)
{
    if(queue != NULL){
        upo_queue_node_t *node = malloc(sizeof(upo_queue_node_t));
        if(node == NULL){
            fprintf(stderr, "Unable to create a node\n");
            abort();
        }

        node->data = data;
        node->next = NULL;
        
        if(queue->first == NULL){
            queue->first = node;
            queue->last = node;
        }
        else{
            queue->last->next = node;
            queue->last = node;
        }
        queue->size += 1;
    }
}

void upo_queue_dequeue(upo_queue_t queue, int destroy_data)
{
    if(queue != NULL && queue->first != NULL){
        upo_queue_node_t *w = queue->first;

        if(queue->first == queue->last){
            queue->last = NULL;
        }

        queue->first = queue->first->next;
        if(destroy_data == 1){
            free(w->data);
        }
        free(w);
        queue->size -= 1;
    }
}

void* upo_queue_peek(upo_queue_t queue)
{
    if(queue != NULL){
        if(queue->first != NULL){
            return queue->first->data;
        }
        else{
            return NULL;
        }
    }
    return NULL;
}

size_t upo_queue_size(const upo_queue_t queue)
{
    if(queue != NULL){
        return queue->size;
    }

    return 0;
}

int upo_queue_is_empty(const upo_queue_t queue)
{
    if(queue != NULL){
        if(queue->first == NULL){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 1;
}