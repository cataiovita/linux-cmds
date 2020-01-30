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
