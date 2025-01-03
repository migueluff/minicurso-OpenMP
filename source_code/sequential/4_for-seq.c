#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

void inicializa(int **v, int size) {
  (*v) = (int *) malloc(sizeof(int)*size);
  for (int i = 0; i < size; i++) {
    (*v)[i] = rand() % 10000;
  }
}

float square(int x){
  int k = 0;
  while(k < 5000) k++;  // espera ocupada 
  return sqrt(x);  
}


void show_vector(int *v, int size) {
	for(int i =0; i < size; i++){
			printf("%d ", v[i]);
		}

}
int main(int argc, char **argv) {
	srand(time(NULL));
	
	int *vetor;
	int size = 1000000;

	inicializa(&vetor, size);
	printf("Numero de processadores: %d\n", omp_get_num_procs());
	omp_set_num_threads(8);
	#pragma omp parallel
	{
		int chuck_size, local_init, local_end;
		chuck_size = size / omp_get_num_threads();

		local_init = chuck_size * omp_get_thread_num();
		local_end = (omp_get_thread_num() + 1) * chuck_size;

		if ( (omp_get_num_threads()-1) == omp_get_thread_num()) local_end = size;

		for(int i = 0; i < size; i++){
			vetor[i] = square(vetor[i]);
		}
	}
	
	  
	//show_vector(vetor, size);
	
	return 0;
}
