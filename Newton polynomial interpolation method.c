#include <stdio.h>
#include <stdlib.h>

int n, c, i, j, interpolar;
double valor, elemento, producto, suma;

int main(int argc, char *argv[]) 
{
	printf("\nBIENVENIDO AL ALGORITMO PARA EL POLINOMIO DE NEWTON\n");
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
	
	
	//Construimos las diferencias Divididas
	double Diferencias[n][n];
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			Diferencias[i][j]=0;	//Inicializamos la matriz con ceros
		}
	}
	
	for(i=0; i<n; i++)
	{
		Diferencias[i][0]=y[i];
	}
	
	for(i=1; i<n; i++)
	{
		for(j=1; j<=i; j++)
		{
			Diferencias[i][j]=(Diferencias[i][j-1]-Diferencias[i-1][j-1])/(x[i]-x[i-j]);
		}
	}
	
	////////////////
/*	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%g\t", Diferencias[i][j]);
		}
		printf("\n");
	}
	////////////////*/
	
	//Imprimimos el Polinomio
	printf("\nF(X)= ");
	for(i=0; i<n; i++)
	{
		printf("%g", Diferencias[i][i]);
		for(j=0; j<i; j++)
		{
			printf("(X-%g)", x[j]);
		}
		
		if(i!=(n-1))
		{
			printf(" + ");	
		}
		
	}
	
	////////////////////////////
	
	
	
	//Construccion del Polinomio de Newton

	do
	{
		printf("\n\nIngrese valor a Interpolar o Extrapolar\n");
		scanf("%lf", &valor);
	
		suma=Diferencias[0][0];
		
		for(i=1; i<n; i++)
		{
			producto=1.0;
			
			for(j=0; j<i; j++) //base de Newton
			{
					producto*=(valor-x[j]);
			}
			
			suma+=producto*Diferencias[i][i];
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
