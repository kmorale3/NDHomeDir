#include <stdio.h>
#include <stdlib.h>

int main(void) {

	long unsigned int size = 15* sizeof(char);

	void* irish = malloc(size);
	void* reference = irish;

	*(char *)(reference) = 0x4c;//L

	reference +=sizeof(char);
	*(char *)(reference) = 0x65;//e

	reference +=sizeof(char);
	*(char *)(reference) = 0x74;//t

	reference +=sizeof(char);
	*(char *)(reference) = 0x27;//'

	reference +=sizeof(char);
	*(char *)(reference) = 0x73;//s

	reference +=sizeof(char);
	*(char *)(reference) = 0x20;//space

	reference +=sizeof(char);
	*(char *)(reference) = 0x47;//G

	reference +=sizeof(char);
	*(char *)(reference) = 0x6f;//o

	reference +=sizeof(char);
	*(char *)(reference) = 0x20;//space

	reference +=sizeof(char);
	*(char *)(reference) = 0x49;//I

	reference +=sizeof(char);
	*(char *)(reference) = 0x72;//r

	reference +=sizeof(char);
	*(char *)(reference) = 0x69;//i

	reference +=sizeof(char);
	*(char *)(reference) = 0x73;//s

	reference +=sizeof(char);
	*(char *)(reference) = 0x68;//h

	reference +=sizeof(char);
	*(char *)(reference) = 0x0a;//new line

	long unsigned int i;
	for( i=0; i<size; ++i) {
		fprintf(stdout, "%c", *( (char *)(irish + i*sizeof(char))));
	}

	free(irish);
	return 0;
	}
