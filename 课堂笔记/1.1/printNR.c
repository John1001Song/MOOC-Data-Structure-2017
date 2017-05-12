#include <stdio.h>

void printN(int N)
{
	int i;
	for(i = 1; i<=N; i++)
		printf("%d\n", i);
}

int main()
{
	int n;
	printf("plz input nr: ");
	scanf("%d", &n);
	printN(n);
//	return 0;
}