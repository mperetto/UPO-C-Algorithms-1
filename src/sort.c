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
#include "sort_private.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *el1, void *el2, size_t n){
	if(el1 == el2) return;
	void *tmp = malloc(n);
	if(tmp == NULL){
		perror("sort swap Error: ");
	}
	memmove(tmp, el1, n);
	memmove(el1, el2, n);
	memmove(el2, tmp, n);
	free(tmp);
}

void upo_insertion_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */

    unsigned char *ptr = (unsigned char*)base;
    
    size_t i = 0, j;
    for(i = 1; i < n; i++){
		j = i;
		while(j>0 && cmp(ptr+(j-1)*size, ptr+j*size) >= 1){
			swap(ptr+j*size, ptr+(j-1)*size, size);
			j = j - 1;
		}
	}

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_merge_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */

    upo_merge_sort_rec(base, 0, n-1, size, cmp);

    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_merge_sort_rec(void *base, int lo, int hi, size_t size, upo_sort_comparator_t cmp){
    if(lo >= hi)
        return;
    
    int mid;
    mid = (lo+hi)/2;

    upo_merge_sort_rec(base, lo, mid, size, cmp);
    upo_merge_sort_rec(base, mid+1, hi, size, cmp);
    upo_merge(base, lo, mid, hi, size, cmp);
    
}

void upo_merge(void *base, int lo, int mid, int hi, size_t size, upo_sort_comparator_t cmp){
    int i = 0;
    int j = mid + 1 - lo;

    unsigned char* base_cpy = (unsigned char*)malloc(size*((hi-lo)+1));
    unsigned char* base_ptr = (unsigned char*)base;
    memmove(base_cpy, base_ptr+lo*size, ((hi-lo)+1)*size);

    int k;
    for(k = lo; k <= hi; ++k){
        if(i > (mid-lo)){
            memmove(base_ptr+k*size, base_cpy+j*size, size);
            j += 1;
        }
        else if(j > (hi-lo)){
            memmove(base_ptr+k*size, base_cpy+i*size, size);
            i += 1;
        }
        else if(cmp(base_cpy+j*size, base_cpy+i*size) < 0){
            memmove(base_ptr+k*size, base_cpy+j*size, size);
            j += 1;
        }
        else{
            memmove(base_ptr+k*size, base_cpy+i*size, size);
            i += 1;
        }
    }
    free(base_cpy);
}

void upo_quick_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    /* TO STUDENTS:
     *  Remove the following two lines and put here your implementation. */
    
    upo_quick_sort_rec(base, 0, n-1, size, cmp);
    
    //fprintf(stderr, "To be implemented!\n");
    //abort();
}

void upo_quick_sort_rec(void *base, int lo, int hi, size_t size, upo_sort_comparator_t cmp){

    if(lo >= hi)
        return;

    int j;
    j = upo_quick_sort_partition(base, lo, hi, size, cmp);

    if(j > 0)
        upo_quick_sort_rec(base, lo, j-1, size, cmp);

    upo_quick_sort_rec(base, j+1, hi, size, cmp);

}

int upo_quick_sort_partition(void *base, int lo, int hi, size_t size, upo_sort_comparator_t cmp){

    int p = lo;
    int i = lo;
    int j = hi + 1;
    unsigned char *base_ptr = (unsigned char*)base;

    while(1){
        do{
            i += 1;
            if(cmp(base_ptr+i*size, base_ptr+p*size) > 0 || i >= hi)
                break;
        }while(1);

        do
        {
            j -= 1;
            if(cmp(base_ptr+j*size, base_ptr+p*size) < 0 || j <= lo)
                break;
        } while(1);
        
        if(i >= j)
            break;
        
        swap(base_ptr+i*size, base_ptr+j*size, size);
    }
    swap(base_ptr+p*size, base_ptr+j*size, size);
    return j;

}