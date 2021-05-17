#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *result = (int*) malloc(sizeof(int));
	long returnCode = syscall(334, 5, 10, result);
	printf("%li %d", returnCode, *result);
	free(result);
	return 0;
}

