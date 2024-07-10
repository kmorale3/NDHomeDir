typedef union // 8 bytes
{
    char* key; //8 bytes
    int value; //4 bytes
} Pair

typedef struct //8+4 = 12  -> 16 bytes (word alignment)
{
    char* key; //8 bytes
    int value; //4 bytes
} Pair