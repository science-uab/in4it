#include <stdio.h>
#include <time.h>

//--------------------------------------
void afiseaza_combinare(int m, int *solutie)
{
	for (int j = 0; j < m; j++)
		printf("%d ", solutie[j]);
	printf("\n");
}
//--------------------------------------
void genereaza_combinari(int n, int m, int *solutie, int pozitie_curenta)
{
	if (pozitie_curenta == m)
		afiseaza_combinare(m, solutie)
		;
	else {
		for (int valoare = pozitie_curenta?solutie[pozitie_curenta - 1] + 1: 1; valoare <= n; valoare++) {
				solutie[pozitie_curenta] = valoare;
				genereaza_combinari(n, m, solutie, pozitie_curenta + 1);
			}
		}
} 
// int x = a==b?2:5
//--------------------------------------
int main(void)
{
	int n, m;
	printf("n, m = ");
	scanf("%d%d", &n, &m);

	int *solutie;
	solutie = new int[m];

	clock_t start_time = clock();
	genereaza_combinari(n, m, solutie, 0);
	clock_t stop_time = clock();

	printf("timp de rulare = %lf\n", (stop_time - start_time) / (double)CLOCKS_PER_SEC);
	delete[] solutie;

	getchar();
	getchar();
	return 0;
}