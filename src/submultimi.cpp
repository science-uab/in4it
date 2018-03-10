#include <stdio.h>
#include <time.h>

//--------------------------------------
void afiseaza_submultime(int n, int *solutie)
{
	printf("{");
	for (int j = 0; j < n; j++)
		if (solutie[j])
			printf("%d ", j + 1);
	printf("}\n");
}
//--------------------------------------
void genereaza_siruri_binare(int n, int *solutie, int pozitie_curenta)
{
	if (pozitie_curenta == n)
		afiseaza_submultime(n, solutie)
		;
	else {
		for (int valoare = 0; valoare <= 1; valoare++) {
			solutie[pozitie_curenta] = valoare;
			genereaza_siruri_binare(n, solutie, pozitie_curenta + 1);
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

	clock_t start_time = clock();
	genereaza_siruri_binare(n, solutie, 0);
	clock_t stop_time = clock();

	printf("timp de rulare = %lf\n", (stop_time - start_time) / (double)CLOCKS_PER_SEC);
	delete[] solutie;

	getchar();
	getchar();
	return 0;
}