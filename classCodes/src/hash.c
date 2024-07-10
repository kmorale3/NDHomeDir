/* hash.c: hash functions */

#include "hash.h"

#include <stdio.h>

/**
 * Constants
 * http://isthe.com/chongo/tech/comp/fnv/
 */

#define FNV_OFFSET_BASIS    (0xcbf29ce484222325ULL)
#define FNV_PRIME           (0x100000001b3ULL)

/**
 * Compute FNV-1 hash.
 * @param   data            Data to hash.
 * @param   n               Number of bytes in data.
 * @return  Computed hash as 64-bit unsigned integer.
 */
uint64_t    hash_from_data(const void *data, size_t n) {
    uint64_t hash = FNV_OFFSET_BASIS;
    //a char is one byte 
    //so a char pointer will go forward by a byte
    //data is const and c should also be const 
    const char *c = data;
    for (size_t i=0; i < n; i++) {
        hash = hash ^ (*c);
        hash = hash * FNV_PRIME;
        c++;
    }
    return hash;
}

/**
 * Compute MD5 digest.
 * @param   path            Path to file to checksum.
 * @param   hexdigest       Where to store the computed checksum in hexadecimal.
 * @return  Whether or not the computation was successful.
 */
bool        hash_from_file(const char *path, char hexdigest[HEX_DIGEST_LENGTH]) {

    //open file
    FILE *stream = fopen(path, "r");
    /*if (!stream) {
        fprintf(stderr, "%s\n", strerror(errno));
        return false;
    }*/
    MD5_CTX context;
    char buffer[BUFSIZ];
    unsigned char digest[MD5_DIGEST_LENGTH];

    MD5_Init(&context);
    while (fgets(buffer, BUFSIZ, stream)) {
        MD5_Update(&context, buffer, strlen(buffer));
    }

    MD5_Final(digest, &context);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(hexdigest + i*2, "%02x", digest[i]);
    } 
    fclose(stream);
    return true;
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */