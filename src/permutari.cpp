#include <stdio.h>
#include <time.h>

//--------------------------------------
void afiseaza_permutare(int n, int *solutie)
{
	for (int j = 0; j < n; j++)
			printf("%d ", solutie[j]);
	printf("\n");
}
//--------------------------------------
bool exista(int valoare, int *solutie, int pozitie_curenta)
{
	for (int i = 0; i < pozitie_curenta; i++)
		if (solutie[i] == valoare)
			return true;

	return false;
}
//--------------------------------------
void genereaza_permutari(int n, int *solutie, int pozitie_curenta, bool *utilizare)
{
	if (pozitie_curenta == n)
		//afiseaza_permutare(n, solutie)
		;
	else {
		for (int valoare = 1; valoare <= n; valoare++) {
			if (!utilizare[valoare - 1]) {
				solutie[pozitie_curenta] = valoare;
				utilizare[valoare - 1] = true;
				genereaza_permutari(n, solutie, pozitie_curenta + 1, utilizare);
				utilizare[valoare - 1] = false;
			}
		}
	}
}
//--------------------------------------
int main(void)
{
	int n;
	printf("n = ");
	scanf("%d", &n);

	int *solutie;
	solutie = new int[n];
	bool *utilizare = new bool[n];

	for (int i = 0; i < n; i++)
		utilizare[i] = false;

	clock_t start_time = clock();
	genereaza_permutari(n, solutie, 0, utilizare);
	clock_t stop_time = clock();

	printf("timp de rulare = %lf\n", (stop_time - start_time) / (double)CLOCKS_PER_SEC);
	delete[] solutie;
	delete[] utilizare;

	getchar();
	getchar();
	return 0;
}