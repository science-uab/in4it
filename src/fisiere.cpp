// author: Mihai Oltean
// MIT license

#include <stdio.h>
#include <fstream>

//--------------------------------------------------

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
int read_array_from_file(const char* filename, int *&a, int &a_length)
{

	FILE *f;

	f = fopen(filename, "r");
	if (f) {
		a_length = 0;

		int num_read = 1;
		while (num_read == 1) {
			int b;
			num_read = fscanf(f, "%d", &b);
			a_length++;
		}
		a_length--;
		fclose(f);
	}
	else
		return E_CANNOT_OPEN_FILE;

	if (a_length) {
		a = new int[a_length];
		f = fopen(filename, "r");
		a_length = 0;

		int num_read = 1;
		while (num_read == 1) {
			int b;
			num_read = fscanf(f, "%d", &b);
			if (num_read == 1) {
				a[a_length] = b;
				a_length++;
			}
		}
		fclose(f);
	}
	return E_OK;
}
//--------------------------------------------------
void print_array(int *x, int x_length)
{
	for (int i = 0; i < x_length; i++)
		printf("%d ", x[i]);
	printf("\n");
}
//--------------------------------------------------
int read_file_cpp(const char* filename, int &a)
{
	std::ifstream f(filename);
	if (!f.is_open())
		return E_CANNOT_OPEN_FILE;
	f >> a;
	if (f.fail()) {
		f.close();
		return E_INVALID_DATA;
	}
	f.close();
	return E_OK;
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

	//-------------------------------------------
	int result = read_file("test.txt", a);

	switch (result) {
	case E_OK:
		printf("a = %d\n", a);
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
	//-------------------------------------------
	result = read_file_cpp("test.txt", a);

	switch (result) {
	case E_OK:
		printf("a = %d\n", a);
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
	//-------------------------------------------
	int *x = NULL;
	int x_length;

	result = read_array_from_file("test.txt", x, x_length);

	if (result == E_CANNOT_OPEN_FILE)
		printf("Cannot read file ...\n");
	else {
		printf("file content is = ");
		print_array(x, x_length);
		if (x)
			delete[] x;
	}

	getchar();
	return 0;
}
//--------------------------------------------------
