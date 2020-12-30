#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void printN (int *n, int size) {
	for (int i = 0; i < size; ++i)
		printf("%i ", n[i]);

	printf("\n");
}

int main (int argc, char **argv) {
	int n;

	if (argc != 2) {
		fprintf(stderr, "Wrong number of arguments. Supply one natural number.\n");
		exit(EXIT_FAILURE);
	}

	char buffer[80];

	if (sscanf(argv[1], "%u%s", &n, buffer) != 1) {
	// this is a comment:		
		fprintf(stderr, "Supplied argument is not a natural number.\n");
		exit(EXIT_FAILURE);
	} 

	int *naturalN;

	naturalN = malloc(sizeof(int) * n);

	if (naturalN == NULL) {
		fprintf(stderr, "Memory allocation for a natural number failed.\n");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < n; ++i)
		naturalN[i] = i;

	printN(naturalN, n);

	free(naturalN);

	return 0;
}

