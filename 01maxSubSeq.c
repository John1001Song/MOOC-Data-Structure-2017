#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arraySize, element, i;
	scanf("%d", &arraySize);
	int array[arraySize];
	int result;

	for (i = 0; i < arraySize; i++)
	{
		scanf("%d", &element);
		array[i] = element;
		//printf("element: %d, array[i]: %d\n", element, array[i]);
	}

	result = MaxSubseqSum4(array, arraySize);
	printf("%d\n", result);
	return 0;
}

int MaxSubseqSum4(int array[], int arraySize){
	int thisSum, maxSum;
	int i;
	thisSum = maxSum = 0;

	for (i = 0; i < arraySize; i++)
	{
		thisSum += array[i];
		if (thisSum > maxSum)
		{
			maxSum = thisSum;
		}else if (thisSum < 0)
		{
			thisSum = 0;
		}
	}

	return maxSum;
}