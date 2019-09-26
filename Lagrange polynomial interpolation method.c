#include <stdio.h>
#include <stdlib.h>

int n, c, i, j, interpolar;
double valor, elemento, producto, suma;

int main(int argc, char *argv[]) 
{
	printf("\nBIENVENIDO AL ALGORITMO PARA EL POLINOMIO DE LAGRANGE\n");
	printf("\nIntroduzca el Numero de Puntos n. (Su polinomio sera de grado n-1)\n");
	scanf("%i", &n);

	double x[n];
	double y[n];

	c=1;
	for(i=0; i<n; i++) //Peticion de puntos
	{
		printf("\nIngrese X%i\n", c);
		scanf("%lf", &elemento);
		x[i]=elemento;
		
		printf("\nIngrese Y%i\n", c);
		scanf("%lf", &elemento);
		y[i]=elemento;
		c++;
	}

	system("cls");

	//Imprimimos el Polinomio
	printf("\n F(X)= ");
	
	for(i=0; i<n; i++)
	{
		printf("[");
		for(j=0; j<n; j++)
		{
			if(i!=j)
			{
				printf("(X-%g)", x[j]);
			}	
		}
		
		printf("] / [");
		
		for(j=0; j<n; j++)
		{
			if(i!=j)
			{
				printf("(%g-%g)", x[i], x[j]);
			}	
		}
		
		printf("] * %g", y[i]);
		if(i!=(n-1))
		{
			printf(" +\n\t");	
		}
	}
	
	////////////////////////////


	do
	{
		printf("\n\nIngrese valor a Interpolar o Extrapolar\n");
		scanf("%lf", &valor);
	
		suma=0;
		
		for(i=0; i<n; i++)
		{
			producto=1.0;
			
			for(j=0; j<n; j++)
			{
				if(i!=j)
				{
					producto*=(valor-x[j])/(x[i]-x[j]);
				}
			}
			
			suma+=y[i]*producto;
		}	
	
		system("cls");
		printf("\nPol(%g)= %g",valor, suma);
		
		printf("\n\nDesea Interpolar o Extrapolar otro Dato?\n");
		printf("Ingrese 1 para continuar. Ingrese cualquier otro numero para salir.\n");
		scanf("%i", &interpolar);
		system("cls"); 
	
	} while(interpolar==1);



	system("PAUSE");
	return 0;
}
