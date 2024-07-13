//Programa que converte números decimais em números binários

#include <stdlib.h>  // biblioteca padrão do C, usada para várias funções, como conversões e alocação de memória
#include <locale.h>  // biblioteca para configurar localização, como linguagem
#include <stdio.h>   // biblioteca para entrada e saída
#include <ctype.h>   // biblioteca para funções de manipulação de caracteres
#include <string.h>  // biblioteca para manipulação de strings

void converterDecimalParaBinario(int nDecimal) // função para converter o número decimal em número binário
{
    int nBinario[100], i = 0, j;
    int aux_num = nDecimal;

    while (nDecimal > 0) 
    {
        nBinario[i] = nDecimal % 2;
        i++;
        nDecimal = nDecimal / 2;
    }

    printf("%d em binário é: ", aux_num);
    for (j = i - 1; j >= 0; j--) 
    {
        printf("%d", nBinario[j]);
    }
    printf("\n");
}

int main() // função principal 
{
    setlocale(LC_ALL, "Portuguese"); // configuração do idioma para português, permitindo acentos, etc.
    
    int opcao, nDecimal;
    char input[100];
    
    system("color 0A");
    
    // título e cabeçalho do programa
    printf("\t\t\t\t\t###################################################\n\n");
    printf("\t\t\t\t\tConversor de base de números decimais para binários\n\n"); 
    printf("\t\t\t\t\t###################################################\n\n");
    
    do {
        // interação com o utilizador 
        printf("Escolha uma opção:\n");
        printf("1. Converter número decimal para binário\n"); 
        printf("2. Sair\n"); 
        scanf("%d", &opcao); 
        getchar(); // limpa o buffer de entrada
        
        switch(opcao) // estrutura de controle 
        {    
            case 1: 
                printf("Insira o número decimal que pretende converter:\n");
                while (1) 
                {
                    fgets(input, sizeof(input), stdin);
                    int valid = 1;
                    int i; 

                    // Verificar se a string contém apenas dígitos
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
                        printf("Entrada inválida. Por favor, insira um número decimal positivo:\n");
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
                printf("Opção inválida. Tente novamente.\n\n\n");
                break;    
        }
    } while (opcao != 2);
    
    return 0; 
}

