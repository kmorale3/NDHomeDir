/* table.c: Separate Chaining Hash Table */

#include "table.h"
#include "hash.h"
#include "macros.h"

/**
 * Create Table data structure.
 * @param   capacity        Number of buckets in the hash table.
 * @return  Allocated Table structure.
 */
Table *	    table_create(size_t capacity) {
    if (capacity == 0)
        capacity = DEFAULT_CAPACITY;

    //the table has an array of dummy pairs that need to be calloced
    //size starts at 0 since nothing is in the table
    //capicity is given  
    Table *t = malloc(sizeof(Table));
    if (!t) {
	    fprintf(stderr, "%s\n", strerror(errno));
	    return NULL;
    }
    t->buckets = (Pair*)calloc(capacity, sizeof(Pair));
        if(!t->buckets) {
    	    fprintf(stderr, "%s\n", strerror(errno));
    	    return NULL;
        }
    t->capacity = capacity;
    t->size = 0;
    return t;
}

/**
 * Delete Table data structure.
 * @param   t               Table data structure.
 * @return  NULL.
 */
Table *	    table_delete(Table *t) {
    //check that table exists
    if (t) {
        if (t->buckets){
            //the first pair is a part of the array, so it is deleted with the array
            //if the pair is pointing to another array, then we need to delete it
            //thus we call pair delete on the next pair of each pair in the array
            for (int i = 0; i < t->capacity; i++){
                pair_delete((t->buckets[i].next), true);
            }
            //free the buckets themselves that were calloced
            free(t->buckets);
        }
        //free the table
        free(t);
    }
    //return null table pointer
    return NULL;
}

/**
 * Insert or update Pair into Table data structure.
 * @param   m               Table data structure.
 * @param   key             Pair's key.
 * @param   value           Pair's value.
 * @param   type            Pair's value's type.
 */
void        table_insert(Table *t, const char *key, const Value value, Type type) {
    //hash using the key and the length of the key (it is a string) 
    uint64_t bucket = hash_from_data(key, strlen(key));
    //make sure that the bucket fits in the capacity of the table
    bucket = bucket % t->capacity;

    //the pairs in the array itself are dummy pairs
    //thus we will look for the existing key starting at the "next" pair
    for (Pair *curr = t->buckets[bucket].next; curr; curr = curr->next) {
        if (streq(curr->key, key)) {
            pair_update(curr, value, type);
            return;
        }
    }
    //inserts new pair at the front
    t->buckets[bucket].next = pair_create(key, value, t->buckets[bucket].next, type);
    //if inserted, increse the size of the table
    t->size++;
}

/**
 * Search Table data structure by key.
 * @param   t               Table data structure.
 * @param   key             Key of the Pair to search for.
 * @return  Pointer to the Value associated with specified key (or NULL if not found).
 */
Value *     table_search(Table *t, const char *key) {
    //hash and use capacity to make sure the bucket fits in the capacity 
    uint64_t bucket = hash_from_data(key, strlen(key));
    bucket = bucket % t->capacity;

    //search
    for (Pair *curr = t->buckets[bucket].next; curr; curr = curr->next) {
        if (streq(curr->key, key)) {
            //expected return is a Value* so we send the address
            return &curr->value;
        }
    }
    //return null value if there is no match
    return NULL;
}

/**
 * Remove Pair from Table data structure with specified key.
 * @param   t               Table data structure.
 * @param   key             Key of the Pair to remove.
 * return   Whether or not the removal was successful.
 */
bool        table_remove(Table *t, const char *key) {
    //hash and alter buckte based on capcity 
    uint64_t bucket = hash_from_data(key, strlen(key));
    bucket = bucket % t->capacity;

    //for the pair being deleted...
        //we need to set the pointer that points to it
        //to be the pair that it is pointing to

    //this is the very first bucket in the corresponding array for the selected hash
    Pair *prev = &t->buckets[bucket];

        //search for the pair to be deleted 
        for (Pair *curr = prev->next; curr; curr = curr->next) {
            if (streq(curr->key, key)) {
                prev->next = curr->next;
                //we want to delete a single pair, not recursive
                pair_delete(curr, false);
                //decrease the size
                t->size--;
                return true;
            }
            prev = curr;
        }
    return false;
}

/**
 * Format all the entries in the Table data structure.
 * @param   m               Table data structure.
 * @param   stream          File stream to write to.
 */
void	    table_format(Table *t, FILE *stream) {
    //format the table by individually formatting the pairs
    for (int i = 0; i < t->capacity; i++){
        for (Pair *curr = t->buckets[i].next; curr; curr = curr->next) {
            pair_format(curr, stream);
        }
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
