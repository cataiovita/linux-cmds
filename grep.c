#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void colorIt(char *word, char *newword)
{
	// Creez sirul nou colorat si adaug \0;
	strcpy(newword, "\e[0;31m");
	strcat(newword, word);
	strcat(newword, "\e[m");
	newword[strlen(newword)] = 0;
}

void printLine(char **lines, int n, char *newword)
{	// Afisez fiecare linie cu conditia daca vechiul string se gasea in aceasta.
	int i;
	char *f;
	
	for (i = 0; i < n; i++)
	{
		f = strstr(lines[i], newword);

		if (f != NULL)
		{
			printf("%s\n", lines[i]);
		}
	}
}

void freeMem(char **lines, char *word,  char *newword, int n)
{
	// Eliberez memoria de pe fiecare linie.
	int i;
	for (i = 0; i < n; i++)
	{
		free(lines[i]);
	}

	// Eliberez memoria alocata dinamic vectorilor.
	free(word);
	free(newword);
}

int main()
{
	char **lines;
	char *word, *newword, *p, *f, *temp;
	int newlen;
	int n, x, i;

	// Aloc memorie necesara stringului prin care caut cuvantul necesar;
	lines = (char **)malloc(200 * sizeof(char *));
	
	word = (char *)malloc(30 * sizeof(char));
	newword = (char *)malloc(200 * sizeof(char));
	
	// Citesc sirul pe care il caut in string;
	fgets(word, 30, stdin);
	word[strlen(word) - 1] = '\0';

	// Citesc numarul de linii;
	scanf("%d\n", &n);
	
	// Creez sirul nou colorat si adaug \0;
	colorIt(word, newword);

	// Citirea liniilor;
	for (i = 0; i < n; i++)
	{				
		lines[i] = malloc(900);

		fgets(lines[i], 200, stdin);

		// Realoc memorie exact necesara fiecarei linii;
		lines[i] = (char *)realloc(lines[i], strlen(lines[i]) + 1);
	
		lines[i][strlen(lines[i]) - 1] = '\0';

		x = 0;
		f = strstr(lines[i], word);
	
		// Numar aparitiile stringului vechi din fiecare linie;
		while (f != NULL)
		{
			f = strstr(f + strlen(word), word);
			x++;
		}

		// Realoc memorie in functie de numarul de cuvinte gasite;
		lines[i] = (char *)realloc(lines[i], strlen(lines[i]) + x * 10 * strlen(newword) + 1);

		// Utilizez pointerul p pentru a gasi stringul vechi in fiecare linie.
		p = strstr(lines[i], word);

		// Functie de inlocuire a stringului;
		while (p != NULL)
		{	
			// Copiez in vectorul temp ce ramane dupa taierea de pe fiecare linie a stringu-
			// lui cautat.
			temp = strdup(p + strlen(word));

			// Copiez la pozitia p noul string, colorat;
			strcpy(p, newword);

			// Concatenez sirul temporar(ce a ramas in urma taierii), cu stringul colorat.
			strcat(p, temp);

			// Lungimea noului sir;
			newlen = strlen(newword);

			// Plec in cautarea urmatorului cuvant vechi de pe linie.
			p = strstr(p + newlen, word);

			// Eliberez memoria vectorului temporar de care m-am folosit.
			free(temp);
		}
	}

	printLine(lines, n, newword);
	freeMem(lines, word, newword, n);
	free(lines);
	return 0;
}
