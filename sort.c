#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int **matrix;
	int i, j, n;
	int *init;
	int elem;
	int m;
	float medie[400] = {0};
	int size[700];
	float sum[800]= {0};
	float aux;
	int *adc;
	int aux2;

	scanf("%d", &m);

	init = (int *)malloc(m * sizeof(int));
	
	// Aloc memorie initiala fiecarei linii - 3;
	for (i = 0; i < m; i++)
	{
		init[i] = 3;
	}

	//CITIRE MATRICE
	// Aloc memorie matricei;
	matrix = (int **)malloc(m * sizeof(int *));
	
	for (i = 0; i < m; i++)
	{
		// Aloc memorie initiala 3 fiecarei linii de pe matrice;
		matrix[i] = (int *)malloc(init[i] * sizeof(int));
		n = 0;

		// Citesc fiecare linie ;
		do {
			scanf("%d", &elem);
			
			// Setez conditia de realocare a memoriei in functie de numarul 
			// de elemente introduse
			if (init[i] == n)
			{
				init[i] += 3;
				matrix[i] = (int *)realloc(matrix[i], init[i] * sizeof(int));
			}
			
			// Introdu fiecare element pe fiecare pozitie in matrice;
			matrix[i][n] = elem;

			// Calculez suma de pe fiecare linie;
			sum[i] += matrix[i][n];
			n++;	

		// Pana la intalnirea elementului 0;
		} while(elem != 0);

		// Calculez dimensiunea fiecarei linii;
		size[i] = n;

		// Calculez media de pe fiecare linie;
		medie[i] = sum[i] / (n - 1);
	}


	// Sortare
	for (i = 0; i < m - 1; i++)
	{
		for (j = i + 1; j < m; j++)
		{
			if (medie[i] < medie[j])
			{

				// Sortez medie pe fiecare linie;
				aux = medie[i];
				medie[i] = medie[j];
				medie[j] = aux;
				
				// Sortez linie in functie de medie;
				adc = matrix[i];
				matrix[i] = matrix[j];
				matrix[j] = adc;

				// Sortez implicit lungimile liniilor;
				aux2 = size[i];
				size[i] = size[j];
				size[j] = aux2;

			}	
		
			// Tratez cazul de existenta al unor multiple
			// linii ce au o medie similara si
			// efectuez o sortare de aceeasi natura;
			if (medie[i] == medie[j] && matrix[i] > matrix[j])
			{
				adc = matrix[i];
				matrix[i] = matrix[j];
				matrix[j] = adc;
	
				aux2 = size[i];
				size[i] = size[j];
				size[j] = aux2;
			}
		}	
	}
	
	//Afisez matricea impreuna cu mediile, cu spatierea impusa;
	for (i = 0; i < m; i++)
	{
		printf("%-10.3f", medie[i]);
		for (j = 0; j < size[i]; j++)
		{
			if (matrix[i][j] != 0)
			{
				printf("%d ", matrix[i][j]);
			}
		}
	printf("\n");
	}


	// Eliberez memoria alocata matricei si vectorului de memorie;
	free(init);

	for (i = 0; i < m; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}