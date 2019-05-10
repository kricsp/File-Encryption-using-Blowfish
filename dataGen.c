#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: testFileGenerator <Size in MB>\n");
		exit(-1);
	}
	size_t i = 0, filesize = atoi(argv[1]) * 1<<20;
	printf("Generating file of size %zu bytes\n", filesize);
	FILE* output = fopen("./datafile", "w");
	srand(3465);
	for (i = 0; i < filesize; ++i)
		fputc(rand() & 0xFF, output);
	return 0;
}