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

#include <assert.h>
#include <stdio.h>
#include <upo/error.h>
#include <upo/queue.h>

static void test_create_destroy();
static void test_enqueue_dequeue();
static void test_peek();
static void test_empty();
static void test_size();
static void test_clear();
static void test_null();

static void test_create_destroy(){
    upo_queue_t queue = upo_queue_create();

    assert(queue != NULL);
    
    upo_queue_destroy(queue, 0);
}

static void test_enqueue_dequeue(){
    upo_queue_t queue = upo_queue_create();

    int value = 1;

    upo_queue_enqueue(queue, &value);

    assert(upo_queue_size(queue) == 1);
    assert(*((int *)upo_queue_peek(queue)) == 1);

    upo_queue_dequeue(queue, 0);

    assert(upo_queue_size(queue) == 0);

    upo_queue_destroy(queue, 0);
}

static void test_peek(){
    upo_queue_t queue = upo_queue_create();
    int vet[4] = {1,2,3,4};

    for(int i=0; i<4; i++){
        upo_queue_enqueue(queue, &vet[i]);
    }
    for(int i=0; i<4; i++){
        assert(vet[i] == *((int*)upo_queue_peek(queue)));
        upo_queue_dequeue(queue, 0);
    }
    
    upo_queue_destroy(queue, 0);
}

static void test_empty(){
    upo_queue_t queue = upo_queue_create();

    assert(upo_queue_is_empty(queue));

    int value = 2;
    upo_queue_enqueue(queue, &value);

    assert(!upo_queue_is_empty(queue));

    upo_queue_dequeue(queue, 0);

    assert(upo_queue_is_empty(queue));

    upo_queue_destroy(queue, 0);
}

static void test_size(){
    upo_queue_t queue = upo_queue_create();

    double vet[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

    for(int i=0; i<13; i++){
        upo_queue_enqueue(queue, &vet[i]);
    }
    assert(upo_queue_size(queue) == 13);

    upo_queue_destroy(queue, 0);
}

static void test_clear(){
    upo_queue_t queue = upo_queue_create();

    char vet[10] = {'a','b','c','d','f','g','h','i','j','k'};

    for(int i=0; i<10; i++){
        upo_queue_enqueue(queue, &vet[i]);
    }

    assert(upo_queue_size(queue) == 10);

    upo_queue_clear(queue, 0);

    assert(upo_queue_is_empty(queue));

    upo_queue_destroy(queue, 0);
}

static void test_null(){
    upo_queue_t queue = NULL;

    assert(upo_queue_size(queue) == 0);
    assert(upo_queue_is_empty(queue));

    upo_queue_enqueue(queue, NULL);
    upo_queue_dequeue(queue, 0);

    upo_queue_clear(queue, 0);

    assert(upo_queue_size(queue) == 0);

    upo_queue_destroy(queue, 0);
}

int main()
{
    printf("Test case 'create destroy'... ");
    fflush(stdout);
    test_create_destroy();
    printf("OK\n");

    printf("Test case 'enqueue dequeue'... ");
    fflush(stdout);
    test_enqueue_dequeue();
    printf("OK\n");

    printf("Test case 'peek'... ");
    fflush(stdout);
    test_peek();
    printf("OK\n");

    printf("Test case 'empty'... ");
    fflush(stdout);
    test_empty();
    printf("OK\n");

    printf("Test case 'size'... ");
    fflush(stdout);
    test_size();
    printf("OK\n");

    printf("Test case 'clear'... ");
    fflush(stdout);
    test_clear();
    printf("OK\n");

    printf("Test case 'null'... ");
    fflush(stdout);
    test_null();
    printf("OK\n");

    return 0;
}
