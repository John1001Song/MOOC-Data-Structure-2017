#include <stdio.h>
#include <stdlib.h>

int main()
{
	int listSize;
	scanf("%d", &listSize);
	
	int list[listSize];
	for (int i = 0; i < listSize; i++)
	{
		scanf("%d", &list[i]);
	}

	int maxSubSeq;
	maxSubSeq = MaxSubSeqSum3(list, listSize);

	printf("%d\n", maxSubSeq);
	
	return 0;
}

int Max3(int A, int B, int C){
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int list[], int left, int right){
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;

	int LeftBorderSum, RightBorderSum;
	int center, i;

	if (left == right)
	{
		if (list[left] > 0)
		{
			return list[left];
		}else return 0;
	}

	/* divide */
	center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(list, left, center);
	MaxRightSum = DivideAndConquer(list, center+1, right);

	/*largest sum through the border*/
	MaxLeftBorderSum = 0;
	MaxRightBorderSum = 0;
	for (i = center; i >= left; i--)
	{
		LeftBorderSum += list[i];
		if (LeftBorderSum > MaxLeftBorderSum)
		{
			MaxLeftBorderSum = LeftBorderSum;
		}
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = center+1; i <= right; i++)
	{
		RightBorderSum += list[i];
		if (RightBorderSum > MaxRightBorderSum)
		{
			MaxRightBorderSum = RightBorderSum;
		}
	}
	/*return conquer*/
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum+MaxRightBorderSum);
}

int MaxSubSeqSum3(int list[], int N){
	return DivideAndConquer(list, 0, N-1);
}