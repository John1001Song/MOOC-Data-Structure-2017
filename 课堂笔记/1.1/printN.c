#include <stdio.h>

void printN(int N)
	{
		if (N)
		{
			printN(N-1);
			printf("%d\n", N);
		}
	}

int main()
{
	int n;
	printf("plz input n: ");
	scanf("%d", &n);
	printN(n);
}