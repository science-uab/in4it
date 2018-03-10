#include <stdio.h>
#include <time.h>

//--------------------------------------
void afiseaza_aranjament(int m, int *solutie)
{
	for (int j = 0; j < m; j++)
		printf("%d ", solutie[j]);
	printf("\n");
}
//--------------------------------------
void genereaza_aranjamente(int n, int m, int *solutie, int pozitie_curenta, bool *utilizare)
{
	if (pozitie_curenta == m)
		afiseaza_aranjament(m, solutie)
		;
	else {
		for (int valoare = 1; valoare <= n; valoare++) {
			if (!utilizare[valoare - 1]) {
				solutie[pozitie_curenta] = valoare;
				utilizare[valoare - 1] = true;
				genereaza_aranjamente(n, m, solutie, pozitie_curenta + 1, utilizare);
				utilizare[valoare - 1] = false;
			}
		}
	}
}
//--------------------------------------
int main(void)
{
	int n, m;
	printf("n, m = ");
	scanf("%d%d", &n, &m);

	int *solutie;
	solutie = new int[m];
	bool *utilizare = new bool[n];

	for (int i = 0; i < n; i++)
		utilizare[i] = false;

	clock_t start_time = clock();
	genereaza_aranjamente(n, m, solutie, 0, utilizare);
	clock_t stop_time = clock();

	printf("timp de rulare = %lf\n", (stop_time - start_time) / (double)CLOCKS_PER_SEC);
	delete[] solutie;
	delete[] utilizare;

	getchar();
	getchar();
	return 0;
}