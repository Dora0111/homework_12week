#include<iostream>
#define MAXSIZE 10

int main(void)
{
	int A[MAXSIZE] = { 1,5,4,8,4,9,7,8,6,4 };
	for (int i = 1; i < MAXSIZE; i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j > 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
	for (int i = 0; i < MAXSIZE; i++)
		std::cout << A[i] << std::endl;
	return 0;
}