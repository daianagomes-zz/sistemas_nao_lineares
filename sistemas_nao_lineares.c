#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 3
#define m 4


void imprime(double M[N][m])
{  int i, j;
  
   
   for(i=0;i<N;i++)
     { 	
     		for(j=0;j<m;j++)
     		{
     		    printf("%lf\t", M[i][j] );
     		 
     		
     		}
     		printf("\n");
     }

}


double f1(double x[N])                       
{ 	
    return( pow(x[0],2) - 81*pow( (x[1]+0.1), 2) + sin(x[2]) + 1.06);
} 
double f2(double x[N])
{ 	
    return exp(x[0]*x[1]) + 20*x[2] + (10*M_PI - 3)/3;
   
}
double f3(double x[N])
{ 	
    return 3*x[0] - cos(x[1]*x[2]) - 1/2;
    
}

void escalonamento(double M[N][m])
{
	int i, j, v;
	double pivo;
	
	for(v=0; v<N-1; v++)
	{
		for(i=v+1; i<N; i++)
		{
			pivo = (M[i][v] / M[v][v]);

			for(j=v; j<N+1; j++)
				M[i][j] = M[i][j] - (pivo * M[v][j]);
		}	
	}
	
}


double df(double f(), double x[N], int k)     
{
    double dff, h, aux;

    h = 1e-6;
    
    aux = x[k];                  
    x[k] = x[k] + h/2.;
    
    dff = f(x);
    
    x[k] = x[k] - h;
    dff = (dff - f(x))/h;
    
    x[k] = aux;
    
    return dff;

}

double Reversa(double M[N][n])
{
	double b, x[n], aux, xn;
	int i, j;
	
	b = M[N-1][N];
	x[N] = b / M[N-1][N-2];

	for(i=N-1; i>=0; i--)
	{
		b = M[i][N];
		for(j=i+1; j<N; j++)
			aux += M[i][j]*x[j];
		x[i] = (b - aux) / M[i][i];

		aux=0;
	}

	printf("\n--------Solução da Equação--------\n");
	for(i=0; i<N; i++){
		printf("X%d = %.2lf \t", i+1, x[i]);
		
	}
	printf("\n\n");
	for(i=0;i<N;i++)
		return x[i];
}
