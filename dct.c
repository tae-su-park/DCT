#include	<stdio.h>
#include	<math.h>
#define	PI	3.1415926535897

#define		N 8

float getCval(int u, int v) {
	float Cu, Cv;

	if (u==0) Cu=1/sqrt(2); else Cu=1;
	if (v==0) Cv=1/sqrt(2); else Cv=1;

	return 1/4.0*Cu*Cv;
}


int	main(void)
{

int	i,j,x,y,u,v;
float	fdct[N][N],idct[N][N],sum;

// Forward [S]
float	in[N][N]=
				{{144, 139, 149, 155, 153, 155, 155, 155},
				{151,  151, 151, 159, 156, 156, 156, 158},
				{151,  156, 160, 162, 159, 151, 151, 151},
				{158,  163, 161, 160, 160, 160, 160, 161},
				{158,  160, 161, 162, 160, 155, 155, 156},
				{161,  161, 161, 161, 160, 157, 157, 157},
				{162,  162, 161, 160, 161, 157, 157, 157},
				{162,  162, 161, 160, 163, 157, 158, 154}};

	for (u=0;u<N;u++)
	{
		for (v=0;v<N;v++)
		{
			sum=0;
			for (x=0;x<N;x++)
			{
				for (y=0;y<N;y++)
				{
					sum+=in[x][y]*
						 cos(((2.0*x+1)*u*PI)/(2.0*N))*
						 cos(((2.0*y+1)*v*PI)/(2.0*N));
				}
			}

			fdct[u][v]=getCval(u,v)*sum;
			printf("%8.1f ",fdct[u][v]);
		}
		printf("\n");
	}
	printf("\n\n");
// Forward [E]


// Reverse [S]
	for (x=0;x<N;x++)
	{
		for (y=0;y<N;y++)
		{
			sum=0;
			for (u=0;u<N;u++)
			{
				for (v=0;v<N;v++)
				{
					sum += getCval(u,v)*fdct[u][v]*
						   cos(((2.0*y+1)*v*PI)/(2.0*N))*
						   cos(((2.0*x+1)*u*PI)/(2.0*N));
				}
			}
			idct[x][y]=sum;

			printf("%8.1f ",idct[x][y]);
		}
		printf("\n");
	}
// Reverse [E]


	printf("\n");
	return(0);
}
