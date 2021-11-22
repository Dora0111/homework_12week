#include<iostream>
#define MAXSIZE 10
#define MAX 99999999
void MERGE(int A[], int p, int q, int r);
void MERGE_SORT(int A[], int p, int r);

int main(void)
{
	int A[MAXSIZE] = { 1,5,4,8,4,9,7,8,6,4 };
	MERGE_SORT(A, 0, MAXSIZE);
	for (int i = 0; i < MAXSIZE; i++)
		std::cout << A[i] << " ";
	return 0;
}

void MERGE(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1+1];
	int* R = new int[n2+1];
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i - 1];
	for (int j = 0; j < n2; j++)
		R[j] = A[q + j];
	L[n1 ] = MAX;
	R[n2 ] = MAX;
	int i = 0; int j = 0;
	for(int k = p - 1; k < r;k++)
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	return;
}

void MERGE_SORT(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
	return;
}