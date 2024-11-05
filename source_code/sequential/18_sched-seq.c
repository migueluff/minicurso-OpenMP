#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void inicializa(int **v, int size) {
    (*v) = (int *) malloc(sizeof(int)*size);
 
    for (int i = 0; i < size; i++) {
        (*v)[i] = 1;
    }
}

int main(int argc, char **argv) {
     
	srand(time(NULL));
    int *vetor;
    int size = 100000000;
    inicializa(&vetor, size);
    
	int k = 15; // valor aleatório
	for (int i = 0; i < size; i++) {
		vetor[i] += k;
	}
 
    return 0;
}