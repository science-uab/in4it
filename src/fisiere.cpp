// author: Mihai Oltean
// MIT license

#include <stdio.h>

#define E_OK 0
#define E_CANNOT_OPEN_FILE 1
#define E_EOF 3
#define E_INVALID_DATA 2
//--------------------------------------------------
int read_file(const char* filename, int &a)
{
	FILE *f;

	f = fopen(filename, "r");
	if (f) {
		int num_read = fscanf(f, "%d", &a);
		if (num_read == 0)
			return E_INVALID_DATA;
		else
			if (num_read == -1)
				return E_EOF;
		return E_OK;
	}
	return E_CANNOT_OPEN_FILE;
}
//--------------------------------------------------
int main()
{
	int a;

	int result = read_file("test.txt", a);

	switch (result){
	case E_OK:
		printf("a = %d", a);
		break;
	case E_CANNOT_OPEN_FILE:
		printf("Cannot read file ...\n");
		break;
	case E_INVALID_DATA:
		printf("Cannot read content ... \n");
		break;
	case E_EOF:
		printf("End of file reached ... \n");
		break;
	}
	
	getchar();
    return 0;
}
//--------------------------------------------------