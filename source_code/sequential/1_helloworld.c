#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv) {

	#pragma omp parallel 
	{
		printf("Hello World :)\n");
		printf("E agora??? %d\n", omp_get_thread_num());
	}

	return 0;
}
