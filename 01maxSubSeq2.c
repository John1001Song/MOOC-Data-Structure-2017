#include <stdio.h>
#include <stdlib.h>

typedef struct Result
{
	int maxSum; 
	int subSeqHead;
	int subSeqTail;
}Res;

int main()
{
	int arraySize, i;
	scanf("%d", &arraySize);
	int array[arraySize];
	Res* result;

	result = resultInitialize();
	
	MaxSubseqSum(array, arraySize, result);

	printf("%d %d %d", result->maxSum, result->subSeqHead, result->subSeqTail);
	return 0;
}

Res* resultInitialize(){
	Res* result = (Res*) malloc(sizeof(Res));
	result->maxSum = 0;
	result->subSeqHead = 0;
	result->subSeqTail = 0;

	return result; 
}

Res* MaxSubseqSum(int array[], int arraySize, Res* result){
	int thisSum, maxSum;
	int i, element;
	int tempSubSeqHead = 0;
	thisSum = 0;
	
	for (i = 0; i < arraySize; i++)
	{
		scanf("%d", &element);
		array[i] = element;
	}
	

	for (i = 0; i < arraySize; i++)
	{
		thisSum += array[i];
		if (thisSum > result->maxSum)
		{
			result->maxSum = thisSum;
			result->subSeqTail = array[i];
			result->subSeqHead = array[tempSubSeqHead];
		}else if (thisSum < 0)
		{
			thisSum = 0;
			tempSubSeqHead = i+1;
		}
	}

	return result;
}

