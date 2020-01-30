#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char **save, **encrypted;
	int flag[12500] = {0};
	
	char buffer[700];
	int key, character;
	int i, j, m, n = 0, k = 0;
	char *p;

	// Introduc numar linii;
	scanf("%d\n", &m);

	// Aloc memorie necesara liniilor pentru criptare;
	save = (char **)malloc(m * sizeof(char *));
	encrypted = (char **)malloc(500 * m * sizeof(char *));

	// Salvez in save liniile introduse de la tastatura,
	// introducand si \0 dupa fiecare linie;
	for (i = 0; i < m; i++)
	{
		fgets(buffer, 700, stdin);
		buffer[strlen(buffer) - 1] = '\0';
		save[i] = strdup(buffer);
		k++;
	}
	
	// Citesc fiecare linie din save;
	for (i = 0; i < m; i++)
	{
		// Ma folosesc de pointerul p pentru a gasi fiecare spatiu de pe linii;
		p = strtok(save[i], " ");

		// Dezbin fiecare string de criptat dupa caracterul " " si il introduc
		// in matricea encrypted;
		while (p != NULL)
		{	
			encrypted[n] = strdup(p);
			p = strtok(NULL, " ");		
			n++;					
		}

		// Adaug la fiecare sfarsit de linie pentru criptat \n si terminatorul de sir;
		encrypted[n] = (char *) malloc(500);
		encrypted[n][0] = '\n';
		encrypted[n++][1] = '\0';
	}	

	// Parcurg fiecare string necesar criptarii pentru a verifica 
	// daca este format doar din cifre;
	for (i = 0; i < n; i++)
	{
		// Ma folosesc de un vector de flaguri (flag[i]) pentru a retine valoarea
		// de adevar;
		flag[i] = 0;
		
		for (j = 1; j < strlen(encrypted[i]); j++)
		{
			if  (encrypted[i][j] < 48 || encrypted[i][j] > 57)
			{
				flag[i] = 1;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		// Creez fiecare cheie pentru fiecare sir de criptat;
		key = encrypted[i][0];
		
		// Daca sirul e creat doar din numere, sari la urmatorul sir;
		for (j = 1; j < strlen(encrypted[i]); j++)
		{
			if ((key >= 48) && (key <= 57) && (flag[i] == 0))
			{
				break;
			}
			
			// Altfel cripteaza-mi sirul;
			else 
			{
				character = encrypted[i][j];
				character += key;
				encrypted[i][j] = character;
			}
		}
	}


	// Afisez fiecare sir din matrice;
	for(i = 0; i < n - 1; i++)
	{	
		printf("%s", encrypted[i]);
		
		// Daca ultimul caracter din sir nu e sfarsit cu \n, adauga-mi " ",
		// necesare afisarii ca in forma initiala;
		if (encrypted[i + 1][0] != '\n' && encrypted[i][0] != '\n')
		{
			printf(" ");
		}
	}
	printf("\n");
	

	// Eliberez memoria alocata liniilor matricei initiale;
	for (i = 0; i < m; i++)
	{
		free(save[i]);
	}

	free(save);

	// Eliberez memoria alocata fiecarui sir criptat;
	for (j = 0; j < n; j++)
	{
		free(encrypted[j]);
	}

	free(encrypted);
	//}
	//getInput(save, m);
	//getTokens(save, m, n);
	//Encrypt(fin, n);
	//getPrint(fin, n);
	
	return 0;
}	
