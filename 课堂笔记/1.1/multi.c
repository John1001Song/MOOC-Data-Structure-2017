#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10000000000 // maximum parameter
#define MAXK 5e4 // maximum repeat time

clock_t start, stop;
double duration;

double funcTrad(int n, double a[], double x)
{
	int i;
	double p = 1;
	for (int i = 0; i <= n; i++)
	{	
		p += (pow(x, i)/a[i]);
	}
	return p;
}

double funcNew(int n, double a[], double x)
{
	int i;
	double p = 1/a[n];
	for (int i = n; i > 0; i--)
	{
		p = 1/a[i-1] + x*p;
	}
	return p*x+1;
}

int main()
{
	int i;
	double a[MAXN];
	for (int i = 0; i < MAXN; i++) 
	{
		a[i] = (double) i;
	}

	start = clock();
	funcTrad(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double) (stop - start))/CLOCKS_PER_SEC;
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);


	start = clock();
	funcNew(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLOCKS_PER_SEC;
	printf("ticks2 = %f\n", (double)(stop - start) );
	printf("duration2 = %6.2e\n", duration);

	return 0;
}