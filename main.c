#include "k3d/k3d.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	k3d_t k3d;
	void * buffer = NULL;
	unsigned long long int length = 0;
	{
		FILE * fp = fopen("./test.k3d", "rb");
		if (fp == NULL) {
			printf("Failed to open \"./test.k3d\"\n");
			return 1;
		}

		fseek(fp, 0L, SEEK_END);
		length = ftell(fp);
		fseek(fp, 0L, SEEK_SET);

		buffer = malloc(length);
		if (buffer == NULL) {
			printf("Failed to allocate buffer\n");
			return 2;
		}

		if (fread(buffer, 1, length, fp) != length) {
			printf("Failed to read\n");
			return 3;
		}

		fclose(fp);
	}

	return k3d_load(&k3d, buffer, length);
}