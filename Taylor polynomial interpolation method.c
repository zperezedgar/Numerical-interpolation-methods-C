#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, i, c, k, p, j, cont=0, interpolar;
double elemento, factor, suma;
double dummy, big, valor;

int main(int argc, char *argv[]) 
{
	printf("\nBIENVENIDO AL ALGORITMO PARA EL POLINOMIO DE TAYLOR\n");
	printf("\nIntroduzca el Numero de Puntos\n");
	scanf("%i", &n);
	
	long double x[n];
	long double y[n];
	long double matrizx[n][n+1];
	
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
	
	for(i=0; i<n; i++) //creacion de la matriz extendida de n X (n+1)
	{
		for(j=0; j<n+1; j++)
		{
			if((x[i]==0)&&((j)==0))
			{
				matrizx[i][j]=1;
			}
			else
			{
				matrizx[i][j]=pow(x[i],(j));
			}
		}
		matrizx[i][n]=y[i];
	}

	//Algoritmo de Gauss
	
	//Elimicacion hacia adelante
	for(k=0; k<=(n-1); k++)
	{
		//****************** PIVOTEO PARCIAL ********************************//
		p=k;
		big=abs(matrizx[k][k]);
		
		for(i=k+1; i<n; i++)	//Rutina para identificar el coeficiente mayor
		{
			dummy=abs(matrizx[i][k]);
			if(dummy>big) 
			{
				big=dummy;
				p=i;
				
			}
		}
			
		if(p!=k)	//Burbuja
		{
			for(j=k; j<n; j++)
			{
				dummy=matrizx[p][j];
				matrizx[p][j]=matrizx[k][j];
				matrizx[k][j]=dummy;
				 
			}
			dummy=matrizx[p][n];
			matrizx[p][n]=matrizx[k][n];
			matrizx[k][n]=dummy;
			cont++;
		}
		//******************************************************************//
	
		
		for(i=k+1; i<n; i++)
		{
			factor=matrizx[i][k]/matrizx[k][k];
			
			for(j=0; j<=n; j++)
			{
				matrizx[i][j]=matrizx[i][j]-((matrizx[k][j])*factor);
			}
		}
	}
	
	
	//SUSTITUCION HACIA ATRAS (Regreso)
	double s[n];
	
	s[n-1]=matrizx[n-1][n]/matrizx[n-1][n-1];
	
	for(i=n-2; i>=0; i--)
	{
		suma=0;
		
		for(j=n-1; j>=i+1; j--)
		{
			suma+=s[j]*matrizx[i][j];
		}
		
		s[i]=(matrizx[i][n]-suma)/matrizx[i][i];
	}
	
	
	system("cls"); 
	//imprimimos el polinomio
	printf("\nPolinomio de Taylor de Grado n-1:\n");
	printf("\nP(X)= %g + %g*X", s[0], s[1]);
	for(i=2; i<n; i++)
		{	
			
			printf(" + %g*(X^%i)",s[i], i);
			
		}
	
	
	do
	{
		printf("\n\n\nIngrese valor a Interpolar o Extrapolar\n");
		scanf("%lf", &valor);
		
		suma=s[0];  //Evitamos el error de elevar algo a la cero
		
		for(i=1; i<n; i++)
		{
			suma+=s[i]*pow(valor, i);
		}
	
		system("cls");
		printf("\nPol(%g)= %g",valor, suma);
		
		
		printf("\n\nDesea Interpolar o Extrapolar otro Dato?\n");
		printf("Ingrese 1 para continuar. Ingrese cualquier otro numero para salir.\n");
		scanf("%i", &interpolar);
		system("cls"); 		
	}while(interpolar==1);
	
	system("PAUSE");
	return 0;
}
