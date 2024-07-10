/* hash_table.c */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Constants */

#define DEFAULT_BUCKETS (1<<5)

/* Structures */

typedef struct
{
    int    *data;
    size_t buckets;
} Table;

/* Functions */

Table * table_create(size_t buckets)
{
    Table *t = malloc(sizeof(Table));
    if (t)
    {
    	t->buckets = (buckets ? buckets : DEFAULT_BUCKETS);
    	t->data    = malloc(sizeof(int) * buckets);
    }
    return t;
}

void    table_delete(Table *t)
{
    free(t);
}

bool    table_insert(Table *t, int value)
{
    size_t hash = value;

    for (size_t offset = 0; offset < t->buckets; offset++)
    {
    	size_t bucket = hash + offset;
    	if (!t->data[bucket])
    	{
    	    t->data[bucket] = value;
    	    return true;
	}
    	if (t->data[bucket] == value)
    	{
    	    return false;
	}
    }

    return false;
}

bool    table_search(Table *t, int value)
{
    size_t hash = value;

    for (size_t offset = 0; offset < t->buckets; offset++)
    {
    	size_t bucket = hash + offset;
    	if (!t->data[bucket])
    	{
    	    return false;
	}
    	if (t->data[bucket] == value)
    	{
    	    return true;
	}
    }

    return false;
}

/* Main Execution */

int main(int argc, char *argv[])
{
    int   d[] = {4, 6, 5, 5, 6, 0};
    Table  *t = table_create(0);

    for (int *p = d; *p; p++)
    {
    	table_insert(t, p);
    }

    for (int i = 0; i < 10; i++)
    {
    	printf("table_search(%d) = %s\n", i, table_search(t, i) ? "true" : "false");
    }

    table_delete(t);
    return EXIT_SUCCESS;
}
