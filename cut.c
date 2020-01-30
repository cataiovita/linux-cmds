#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   
void sort(int *auxfields, int f)
{
	int i, j;
	int aux;
	for (i = 0; i < f - 1; i++)
	{
		for (j = i + 1; j < f; j++)
		{
			if (auxfields[i] > auxfields[j])
			{
				aux = auxfields[i];
				auxfields[i] = auxfields[j];
				auxfields[j] = aux;
			}
		}
	}
}

void freeMem(char **token, char **save)
{
	free(token);
	free(save);
}

int main()
{
	// indici
	int m, i, j, n = 0, f;
	int l;

	// matrici
	char **token, **save;
	// delimitatori
	char del[10];
	char newdel[10];
	char *fl, *p;
	char *poken;
	
	// fields
	char infields[200];
	int auxfields[200];
	int offields[200];

	// Citesc de la tastatura delimitatorul initial, ce trebuie
	// inlocuit;
	fgets(del, 20, stdin);
	del[strlen(del) - 1] = '\0';

	// Aloc memorie necesara matricei de tokenuri si 
	save = (char **)malloc(450 * sizeof(char *));
	token = (char **)malloc(400  * sizeof(char *));

	// Citesc numarul de fielduri;
	scanf("%d", &f);

	// Citesc sirul de fielduri;
	scanf("%s", infields); 
	
	// Citesc noul delimitator;
	scanf("%s", newdel);


	// Incep prelucrarea sirului de fielduri,
	// pentru a-l desparti de virgule;
	fl = strtok(infields, ",");
	n = 0;

	// Elimin virgulele din sir si salvez numerele intr-un vector
	// auxiliar de tip int;
	while (fl != NULL)
	{
		poken = strdup(fl);
		auxfields[n] = atoi(poken);
		fl = strtok(NULL, ",");
		n++;
		free(poken);
	}


	// Sortez fiecare vector auxiliar 
	sort(auxfields, f);

	// Unific elementele din multimea vectorului auxiliar
	// si le salvez intr-un vector offields cu elemente unice;
	l = 1;
	for (i = 0; i < f - 1; i++)
	{
		if (auxfields[i] == auxfields[i + 1])
		{

		}

		else 
		{
			offields[l] = auxfields[i + 1];
			l++;
		}
	}
	offields[0] = auxfields[0];
	offields[l] = auxfields[f - 1];

	// Introduc numar linii 
	scanf("%d\n", &m);

	// Citesc de la tastatura intr-o matrice save, fiecare linie;
	for (i = 0; i < m; i++)
	{
		save[i] = malloc(300);
		fgets(save[i], 300, stdin);
		save[i][strlen(save[i]) - 1] = '\0';

		n = 0;
		
		// Ma folosesc de strtok pentru a dezbina matricea in functie
		// de delimitator;
		p = strtok(save[i], del);
		while (p != NULL)
		{	
			// Salvez in matricea token fiecare sir dezbinat;
			token[n] = strdup(p);
			p = strtok(NULL, del);
			n++;		
		}

		token[n - 1][strlen(token[n - 1])] = 0;
		
		// Parcurg vectorul de numere si verifica daca numarul
		// de elemente din vector e mai mic decat numarul de 
		// tokenuri de pe linie pentru afisarea delimitatorilor;
		int counter = 0;
		for (j = 0; j < l; j++)
		{	
			// Daca da, incrementeaza counterul;
			if (offields[j] - 1 < n)
			{
				counter++;
			}
		}

		// Initiez un counter pentru fiecare index al fiecarui token
		// din matrice, pentru evitarea plasarii delimitatorului la sfarsit
		// de linie;
		int counterIndex = 0;
		for (j = 0; j < l; j++)
		{	
			if (offields[j] - 1 < n)
			{
				printf("%s", token[offields[j] - 1]);
				
				if (counterIndex != counter - 1)
				{
					printf("%s", newdel);
				}
				counterIndex++;
			}
		}

		printf("\n");

		for (j = 0; j < n; j++)
		{
			free(token[j]);
		}
	}

	for (i = 0; i < m; i ++)
	{
		free(save[i]);
	}	
	freeMem(token, save);
	return 0;
}