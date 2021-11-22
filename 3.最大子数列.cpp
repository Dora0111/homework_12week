#include<stdio.h>
constexpr auto MAXSIZE = 10;

static int MaxSubSum(const int A[], int Left, int Right);
int MaxSubsequenceSum(const int A[], int MAXSIZE);
int Max3(int a, int b, int c);

int main(void)
{
	int A[MAXSIZE] = { 5,-9,7,4,6,-3,11,-22,76,-52 };
	printf("%d", MaxSubsequenceSum(A, MAXSIZE));
	return 0;
}

static int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum=0, MaxRightBorderSum=0;
	int LeftBorderSum = 0, RightBorderSum = 0;
	int Center, i;

	if (Left == Right)
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = Center+1; i <=Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum(const int A[],int MAXSIZE)
{
	return MaxSubSum(A, 0, MAXSIZE - 1);
}

int Max3(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > c && b > a)
		return b;
	else
		return c;
}