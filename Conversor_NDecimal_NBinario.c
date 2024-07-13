//Programa que converte n�meros decimais em n�meros bin�rios

#include <stdlib.h>  // biblioteca padr�o do C, usada para v�rias fun��es, como convers�es e aloca��o de mem�ria
#include <locale.h>  // biblioteca para configurar localiza��o, como linguagem
#include <stdio.h>   // biblioteca para entrada e sa�da
#include <ctype.h>   // biblioteca para fun��es de manipula��o de caracteres
#include <string.h>  // biblioteca para manipula��o de strings

void converterDecimalParaBinario(int nDecimal) // fun��o para converter o n�mero decimal em n�mero bin�rio
{
    int nBinario[100], i = 0, j;
    int aux_num = nDecimal;

    while (nDecimal > 0) 
    {
        nBinario[i] = nDecimal % 2;
        i++;
        nDecimal = nDecimal / 2;
    }

    printf("%d em bin�rio �: ", aux_num);
    for (j = i - 1; j >= 0; j--) 
    {
        printf("%d", nBinario[j]);
    }
    printf("\n");
}

int main() // fun��o principal 
{
    setlocale(LC_ALL, "Portuguese"); // configura��o do idioma para portugu�s, permitindo acentos, etc.
    
    int opcao, nDecimal;
    char input[100];
    
    system("color 0A");
    
    // t�tulo e cabe�alho do programa
    printf("\t\t\t\t\t###################################################\n\n");
    printf("\t\t\t\t\tConversor de base de n�meros decimais para bin�rios\n\n"); 
    printf("\t\t\t\t\t###################################################\n\n");
    
    do {
        // intera��o com o utilizador 
        printf("Escolha uma op��o:\n");
        printf("1. Converter n�mero decimal para bin�rio\n"); 
        printf("2. Sair\n"); 
        scanf("%d", &opcao); 
        getchar(); // limpa o buffer de entrada
        
        switch(opcao) // estrutura de controle 
        {    
            case 1: 
                printf("Insira o n�mero decimal que pretende converter:\n");
                while (1) 
                {
                    fgets(input, sizeof(input), stdin);
                    int valid = 1;
                    int i; 

                    // Verificar se a string cont�m apenas d�gitos
                    for (i = 0; i < strlen(input) - 1; i++) // -1 para ignorar o '\n'
                    {
                        if (!isdigit(input[i])) 
                        {
                            valid = 0;
                            break;
                        }
                    }

                    if (valid && sscanf(input, "%d", &nDecimal) == 1 && nDecimal > 0) 
                    {
                        break;
                    }
                    else 
                    {
                        printf("Entrada inv�lida. Por favor, insira um n�mero decimal positivo:\n");
                    }
                }
                converterDecimalParaBinario(nDecimal);
                system("pause");
                system("cls");
                break; 
                
            case 2: 
                system("cls");
                break;

            default:    
                system("cls");
                printf("Op��o inv�lida. Tente novamente.\n\n\n");
                break;    
        }
    } while (opcao != 2);
    
    return 0; 
}

