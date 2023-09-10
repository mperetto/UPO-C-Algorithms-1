#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <upo/bst.h>
#include <upo/error.h>

int int_compare(const void *a, const void *b) {
    int *aa = (int*)a;
    int *bb = (int*)b;

    return (*aa > *bb) - (*aa < *bb);
}

void test_rank() {
    int keys[] = {8,3,1,6,4,7,10,14,13};
    int values[] = {8,3,1,6,4,7,10,14,13};

    upo_bst_t bst;
    bst = upo_bst_create(int_compare);
    assert(bst != NULL);

    for(int i = 0; i < 9; i++) {
        upo_bst_insert(bst, &keys[i], &values[i]);
        assert(upo_bst_contains(bst, &keys[i]));
    }

    int rank_keys[] = {8, 1, 13, 14, 0, 5, 12, 100};
    size_t rank_results[] = {5, 0, 7, 8, 0, 3, 7, 9};

    for(int i = 0; i < 8; i++) {
        size_t r = upo_bst_rank(bst, &rank_keys[i]);
        assert(r == rank_results[i]);
    }
}

void test_predecessor() {
    int keys[] = {8,3,1,6,4,7,10,14,13};
    int values[] = {8,3,1,6,4,7,10,14,13};

    upo_bst_t bst;
    bst = upo_bst_create(int_compare);
    assert(bst != NULL);

    for(int i = 0; i < 9; i++) {
        upo_bst_insert(bst, &keys[i], &values[i]);
        assert(upo_bst_contains(bst, &keys[i]));
    }

    int pred_keys[] = {8, 1, 13, 12, 0, 100};
    int pred_results[] = {7, -1, 10, 10, -1, 14};

    for(int i = 0; i < 6; i++) {
        int *r = (int*)upo_bst_predecessor(bst, &pred_keys[i]);
        
        if(r == NULL) {
            assert(pred_results[i] == -1);
        }
        else {
            assert(*r == pred_results[i]);
        }
        
    }
}

void test_value_depth() {
    int keys[] = {8,3,1,6,4,7,10,14,13};
    int values[] = {8,3,1,6,4,7,10,14,13};

    upo_bst_t bst;
    bst = upo_bst_create(int_compare);
    assert(bst != NULL);

    for(int i = 0; i < 9; i++) {
        upo_bst_insert(bst, &keys[i], &values[i]);
        assert(upo_bst_contains(bst, &keys[i]));
    }

    int valdepth_keys[] = {8, 1, 13, 12, 0, 100};
    int valdepth_value_results[] = {8, 1, 13, -1, -1, -1};
    int valdepth_depth_results[] = {0, 2, 3, -1, -1, -1};

    for(int i = 0; i < 6; i++) {
        
        long depth = 0;
        int *r = (int*)upo_bst_get_value_depth(bst, &valdepth_keys[i], &depth);
        
        if(r == NULL) {
            assert(valdepth_value_results[i] == -1);
            assert(depth == valdepth_depth_results[i]);
        }
        else {
            assert(*r == valdepth_value_results[i]);
            assert(depth == valdepth_depth_results[i]);
        }
    }
}

int main()
{

    printf("Test rank:... ");
    fflush(stdout);
    test_rank();
    printf("OK\n");

    printf("Test predecessor:... ");
    fflush(stdout);
    test_predecessor();
    printf("OK\n");

    printf("Test value_depth:... ");
    fflush(stdout);
    test_value_depth();
    printf("OK\n");

    return 0;
}
