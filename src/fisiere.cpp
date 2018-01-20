// author: Mihai Oltean
// MIT license

#include <stdio.h>

#define E_OK 0
#define E_CANNOT_OPEN_FILE 1
#define E_EOF 3
#define E_INVALID_DATA 2
//--------------------------------------------------

int get_file_size(const char* filename)
{
	FILE *f;

	f = fopen(filename, "r");
	if (f) {
		fseek(f, 0, SEEK_END);
		int file_size = ftell(f);
		fclose(f);
		return file_size;
	}
	else
		return -1;
}
//--------------------------------------------------

int read_file(const char* filename, int &a)
{
	FILE *f;

	f = fopen(filename, "r");
	if (f) {
		int num_read = fscanf(f, "%d", &a);
		if (num_read == 0) {
			fclose(f);
			return E_INVALID_DATA;
		}
		else
			if (num_read == -1) {
				fclose(f);
				return E_EOF;
			}
		fclose(f);
		return E_OK;
	}
	return E_CANNOT_OPEN_FILE;
}
//--------------------------------------------------
int main()
{
	int a;

	int file_size = get_file_size("test.txt");
	if (file_size == -1) {
		printf("Cannot read file ...\n");
	}
	else {
		printf("file size = %d\n", file_size);
	}

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