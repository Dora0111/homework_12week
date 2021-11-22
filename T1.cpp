
#include<iostream>
#define MAX 99999999
#define MAXSIZE 10
int left_sum = -MAX, right_sum = -MAX;
int max_left, max_right;
int left_border, right_border;

void FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high);
int* FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);

int main(void)
{
	int A[MAXSIZE] = { 5,-9,7,4,6,-3,11,-22,76,-52 };
	FIND_MAXIMUM_SUBARRAY(A, 0, MAXSIZE);
	for (int i = 0; i < MAXSIZE; i++)
		std::cout << A[i] << " ";
	return 0;
}

void FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
	int sum = 0;
	for (int i = mid; i >= 0; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	sum = 0;
	for (int j = mid + 1; j < MAXSIZE; j++)
	{
		sum = sum + A[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	return;
}

int* FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
	int mid, left_low, left_high, right_low, right_high, cross_low, cross_high, cross_sum;
	if (high == low)
	{
		left_border = low;
		right_border = high;
		return &A[low];
	}
	else
	{
		mid = (low + high) / 2;
		FIND_MAXIMUM_SUBARRAY(A, low, mid);
		FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
		FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			left_low
		}
	}
	return;
}
