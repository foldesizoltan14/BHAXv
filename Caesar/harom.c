#include<stdio.h>
#include<stdlib.h>

int main()
{
	int nr=5;
	double **tm;
	//printf("%p\n",&tm);

	if ((tm = (double **)malloc(nr*sizeof(double)))==NULL)
	{
		return -1;
	}

	//printf("%p\n",tm);

	for(int i=0; i<nr; i++)
	{
		if((tm[i]=(double *) malloc ((i+1) * sizeof (double)))==NULL)
	  {
		return -1;
	  }
   	}

//printf("%p\n",tm[0]);

for(int i=0; i<nr; i++) //i 4ig fog menni
	for(int j=0; j<i+1; j++) //j mindig i-ig
	  tm[i][j]=i*(i+1)/2+j; // i. sor j. eleme = egyenlet

for(int i=0; i<nr; i++) //kiiratjuk a mátrix elemeit
{
	for(int j=0; j<i+1; j++)
	  printf("%f,", tm[i][j]);
	printf("\n");
}
//átírjuk a 3. sor elemeit, így is ki lehet őket iratni
tm[3][0]=42.0;
(*(tm+3))[1]=43.0;
*(tm[3]+2)=44.0;
*(*(tm+3)+3)=45.0;

for(int i=0; i<nr; i++) //megint kiiratjuk
{
	for(int j=0; j<i+1; j++)
	  printf("%f,",tm[i][j]);
	printf("\n");
}

for(int i=0; i<nr; i++)
	free(tm[i]); //felszabadítjuk a lefoglalt sorokat

free(tm); //mindent felszabadítunk

return 0;
}
