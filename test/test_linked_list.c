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

#include <upo/linked_list.h>
#include <upo/error.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* el1, const void* el2) {

    const int* el11 = el1;
    const int* el21 = el2;

    return (*el11 > *el21) - (*el11 < *el21);

}

void print_int(FILE* f, const void* el) {
    fprintf(f, "%d", *((int*)el));
}

int main() {

    //[1,2,3,4,5,4,3,2,1]
    int arr[9] = {1,2,3,4,5,4,3,2,1};

    printf("Test case 'create'... ");
    fflush(stdout);
    upo_linked_list_t l = upo_linked_list_create(cmp);
    assert(l != NULL);
    printf("OK\n");

    printf("Test case 'insert'... ");
    fflush(stdout);
    for(int i = 0; i < 9; i++) {
        upo_linked_list_insert_head(l, &arr[i]);
    }
    printf("OK\n");

    upo_linked_list_print(l, stdout, print_int);

    printf("Test case 'search'... ");
    fflush(stdout);
    int *a = upo_linked_list_search(l, &arr[2]);
    assert(*a == arr[2]);
    printf("OK\n");

    return 0;
}