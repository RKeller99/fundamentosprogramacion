int a[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','\xA4','o','p','q','r','s','t','u','v','w','x','y','z'};
int b[27]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
char c[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','\xA4','o','p','q','r','s','t','u','v','w','x','y','z'};
#include<stdio.h>
#include <ctype.h>

main()
{
int i,j,size;
char srt[100], temp, ordenaL[5];
int resultado, ordenaN[5];
printf("Ingresa las letras:   ");
scanf("%s",&srt);
fflush(stdin);
            for(i=0;i<=size;i++)
             {
              for(j=0;j<27;j++)
                {
                    if(srt[i]==a[j])
                	 {
                  		ordenaN[i]=b[j];	
                   	 }
                 
             
                 }
              }
printf("La conversion a numeros es: \n" );          
for(i=0; i <5; i=i+1) 
printf("%3i", ordenaN[i]); 

/* Ordenando el arreglo de números */ 
for (i=0; i <5; i=i+1) 
for (j=0; j <5; j=j+1) 
if ( ordenaN[i] < ordenaN[j] ) 
{ 
temp= ordenaN[i]; 
ordenaN[i]=ordenaN[j]; 
ordenaN[j]=temp; 
} 

printf("\n");
printf("La numeros ordenados: \n" ); 
for(i=0; i <5; i=i+1) 
printf("%3i", ordenaN[i]);

/*Regresa letras ordenadas*/

for(i=0;i<=5;i++)
             {
              for(j=0;j<27;j++)
                {
                    if(ordenaN[i]==b[j])
                	 {
                  		ordenaL[i]=c[j];
	                   	}
                 }
              }

printf("\n");
printf("Las letras ordenadas son : \n" ); 
for(i=0; i <5; i=i+1) 
printf("%c", ordenaL[i]);

 return 0;
}

