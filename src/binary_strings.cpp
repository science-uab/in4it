#include <stdio.h>

//--------------------------------------
void afiseaza_solutie(int n, int *solutie)
{
	for (int j = n - 1; j >= 0; j--)
		printf("%d", solutie[j]);
	printf("\n");
}
//--------------------------------------
void genereaza_siruri_binare(int n, int *solutie)
{
	int m = 1 << n; // 2 ^ n
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			solutie[j] = (i & 1 << j) >> j;
		afiseaza_solutie(n, solutie);
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

	genereaza_siruri_binare(n, solutie);

	delete[] solutie;

	getchar();
	getchar();
	return 0;
}