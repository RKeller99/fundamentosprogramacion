#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
char x,y,z,w,r,opc,resp,x1;
char letras[5],ordenado[5],N[50],textoA[100],abecedario[28];
int i,j,k;
int main()
	{
		printf("\n\t\t\t\t\tBasile Alvarez Andr%cs Jos%c\n\t\t\t\t\tGuzm%cn Mercado Sergio Francisco\n\t\t\t\t\tKeller Ascencio Rodolfo Andr%cs\n\t\t\t\t\tPardo Reyna Anelissa Allizon\n\t\t\t\t\tPulido Rodr%cguez Aramis de Jes%cs",130,130,160,130,161,163);
		printf("\n\n\t\t\t\t\tFundamentos de Programaci%cn\n\n\t\t\t\t\t\tGrupo: 1101\n\n\t\t\t\t\tM.C. Cintia Quezada Reyes",162); 
		printf("\n\n\t\tIngresa tu nombre: ");	//El usuario ingresa su nombre
		scanf(" %[^\n]",&N);
		resp='s';
		while((resp=='s')||(resp=='S'))
			{
				printf("\nSELECCIONA UNA OPCI%cN: ",224);
				printf("\n\n\t [A] MODIFICACION%cN DE UN TEXTO ",224);
				printf("\n\n\t [B] OBTENCI%cN DEL TEXTO ORIGINAL \n\n\t\t\t\t",224); 
				printf("Respuesta: ");
				scanf("%s",&opc);			
				system("cls");
				opc=toupper(opc);
				if(opc=='A') //Empieza A
				
				
				
				
				
				
				
				
				
				
				
				
				
				{
					printf("\n\n\t\t\t\t %c MODIFICACI%cN DE UN TEXTO %c",174,224,175); 
					printf("\n\n\tProporciona 5 letras del alfabeto\n\t");
					scanf("%s",letras);
					//Aqui se ordenan alfabeticamente
			      	strupr(letras);
					if(letras[5]>=6)
			      		{
			      			printf("Solamente se permiten 5 letras");
						}
					else
						{
							strcpy(ordenado,letras);
							for(i = 1; i < 5; i++)
			                	{
								for(j=0;j<5-i;j++)
									{
										if((ordenado[j])>(ordenado[j+1]))
			                                {
			                 					x1=ordenado[j];
			                 					ordenado[j]=ordenado[j+1];
			                 					ordenado[j+1]=x1;
			                 				}
			                 		}	
								}
						printf("Tus letras ordenadas son: %s\n",ordenado);
						char square[6][6] = 
						{
							{' ',ordenado[0],ordenado[1],ordenado[2],ordenado[3],ordenado[4]},
							{ordenado[0],'A','B','C','D','E'},
							{ordenado[1],'F','G','H','I','K'},
							{ordenado[2],'L','M','N','O','P'},
							{ordenado[3],'Q','R','S','T','U'},
							{ordenado[4],'V','W','X','Y','Z'},
						};
						/* Para verificar matriz
						for(i=0;1<6;i++)
							{
								for(j=0;j<6;j++)
									{
											printf("%c",square[i][j]);  	
									}
								printf("\n");
							}	
						*/	
						//char abecedario[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','Ñ','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
						printf("Se lee el texto que deseas modificar");	 
					    scanf(" %[^\n]",textoA);
					    strupr(textoA);
						printf("%s",textoA);
						//printf("%d",strcmp(abecedario,textoA));	 
						/*for(i=1;i<6;i++)
				                {
									for(j=1;j<6;j++)
										{
												printf("%d",strcmp(abecedario,textoA));
												//instrucción para saber la coordenada
				                 		}	
								}
								*/
							}
						
				}
				else
				{
					if(opc=='B') //Empieza B
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					{
						printf("\n\n\t\t\t\t %c OBTENCI%cN DEL TEXTO ORIGINAL %c",174,224,175);
					}
					else
					{
						printf("\n\n\t\tOPCI%cN NO V%cLIDA, DEBES SELECCIONAR UNA OPCI%cN",224,181,224); 
					}
				}
				printf("\n\n\n\tPara regresar al men%c, oprima una S: ",163); //Termina opción B
				scanf("%s", &resp);
			}	
    getchar();
   	getchar();
    return 0;
	}
