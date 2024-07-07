
#include <stdio.h>   // para entradas e saidas
#include <stddef.h>  // para definicoes basicas
#include <stdlib.h>  // para a biblioteca padrao
#include <string.h>  // para cadeias de caracteres
#include <stdarg.h>  // para tratar argumentos
#include <stdbool.h> // para definicoes logicas
#include <ctype.h>   // para tipos padroes
#include <math.h>    // para definicoes matematicas
#include <time.h>    // para medir tempo
#include <wchar.h>   // para 16-bit characters
#include <iso646.h>  // para and, or, xor, not alternatives
#include <float.h>   //Define as limitações de tipos de dados em ponto flutuante.
#include <limits.h>  // Define as limitações de tipos de dados,
// como os valores máximos e mínimos para diferentes tipos de dados.

struct Estrutura // inicializador de arranjo
{
    int *arranjo;
    int tamanho;
};
typedef struct Estrutura ARRANJO;
typedef ARRANJO *POINTER_ARRAY;

int ehPrimo(int n) // Função para verificar se um número é primo
{
    int primo = 1;

    if (n < 0)
    {
        n = n * (-1);
    }
    if (n == 0)
    {
        primo = 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            primo = 0;
        }
    }

    return primo;
}

char *lerCadeia() // Função para ler uma cadeia de caracteres
{
    int tamanho = 100;
    char *cadeia = (char *)malloc(tamanho * sizeof(char));
    int i = 0;
    char c;
    int x = 1;
    printf("String: ");

    while (x == 1)
    {
        c = getchar();

        if (c == '\n' || c == EOF)
        {
            x = 0;
        }

        cadeia[i] = c;
        i++;

        if (i >= tamanho - 1)
        {
            tamanho *= 2;
            cadeia = realloc(cadeia, tamanho * sizeof(char));
        }
    }

    cadeia[i] = '\0';

    return cadeia;
}

int *readIntArray(int n)
{
    int *arranjo = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Elemento [%d]: ", i + 1);
        scanf("%d", &arranjo[i]);
    }
    return arranjo;
}

double *readDoubleArray(int n)
{
    double *arranjo = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        printf("Elemento [%d]: ", i + 1);
        scanf("%lf", &arranjo[i]);
    }
    return arranjo;
}

double mediaDoubleArray(double *arranjo, int n)
{
    double soma = 0.0;
    double media = 0.0;
    for (int i = 0; i < n; i++)
    {
        soma += arranjo[i];
    }
    media = soma / n;
    return media;
}

int *readNintArray(int *n)
{
    *n = 100;
    int i = 0;

    int elemento = 0;
    int *arranjo = (int *)malloc(*n * sizeof(int));
    do
    {
        printf("Elemento[%d]: ", i + 1);

        scanf("%d", &elemento);
        arranjo[i] = elemento;
        i++;
        if (i >= *n)
        {
            *n *= 2;
            int *novoArranjo = (int *)realloc(arranjo, *n * sizeof(int));
            if (novoArranjo == NULL)
            {
                printf("\nErro na alocacao de memoria");
                exit(-1);
            }
            arranjo = novoArranjo;
        }

    } while (elemento != -1);

    *n = i - 1;
    return arranjo;
}

double *readNdoubleArray(int *n)
{
    *n = 100;
    int i = 0;
    double elemento = 0;
    double *arranjo = (double *)malloc(*n * sizeof(double));
    do
    {
        printf("Elemento[%d]: ", i + 1);

        scanf("%lf", &elemento);
        arranjo[i] = elemento;
        i++;
        if (i >= *n)
        {
            *n *= 2;
            double *novoArranjo = (double *)realloc(arranjo, *n * sizeof(double));
            if (novoArranjo == NULL)
            {
                printf("\nErro na alocacao de memoria");
                exit(-1);
            }
            arranjo = novoArranjo;
        }

    } while (elemento != 0);

    *n = i - 1;
    return arranjo;
}

bool ehLogico(char c)
{
    bool logico = 0;
    if (c == '&' || c == '|' || c == '!')
    {
        logico = 1;
    }
    return logico;
}

bool ehAritmetico(char c)
{
    bool aritmetico = 0;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        aritmetico = 1;
    }
    return aritmetico;
}

bool ehRelacional(char c)
{
    bool relacional = 0;
    if (c == '>' || c == '<' || c == '=')
    {
        relacional = 1;
    }
    return relacional;
}

bool ehSeparador(char c)
{
    bool separador = 0;
    if (c == ' ' || c == ',' || c == '.' || c == ';' || c == '_' || c == ':')
    {
        separador = 1;
    }
    return separador;
}

bool ehMaiuscula(char c)
{
    bool maiuscula = 0;
    if (c >= 'A' && c <= 'Z')
    {
        maiuscula = 1;
    }
    return maiuscula;
}

bool ehMinuscula(char c)
{
    bool minuscula = 0;
    if (c >= 'a' && c <= 'z')
    {
        minuscula = 1;
    }
    return minuscula;
}
bool ehDigito(char c)
{
    bool digito = 0;
    if (c >= '0' && c <= '9')
    {
        digito = 1;
    }
    return digito;
}

int *arranjoPrimoOuNao(int n, int *arranjo)
{
    for (int i = 0; i < n; i++)
    {
        if (ehPrimo(arranjo[i]))
        {
            arranjo[i] = 1;
        }
        else
        {
            arranjo[i] = 0;
        }
    }
    return arranjo;
}

double **inicializaMatriz(int linhas, int colunas)
{

    double **matriz = (double **)malloc(linhas * sizeof(double *));

    if (matriz == NULL)
    {

        printf("Nao ha espaço\n");
        exit(1);
    }
    else
    {
        for (int i = 0; i < linhas; i++)
        {
            matriz[i] = (double *)malloc(colunas * sizeof(double));
            if (matriz[i] == NULL)
            {
                printf("Erro ao alocar a linha %d\n", i);
                exit(1);
            }
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = 0.0;
        }
    }
    return matriz;
}
void liberaMatrizDouble(double **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void liberaMatrizInt(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

char *lerArquivo(char *arquivoNome)
{
    FILE *arquivoLeitura = fopen(arquivoNome, "r");
    if (arquivoLeitura == NULL)
    {
        printf("Nao foi possivel ler o arquivo");
        return NULL;
    }

    int tamanho = 200;
    char *conteudo = (char *)malloc(tamanho * sizeof(char));

    if (conteudo == NULL)
    {
        printf("Erro ao alocar memoria");
        fclose(arquivoLeitura);
        return NULL;
    }
    conteudo[0] = '\0';
    char string[tamanho];
    int tamTotal = 0;
    while (fgets(string, sizeof(string), arquivoLeitura) != NULL)
    {
        tamTotal = strlen(conteudo) + strlen(string) + 1;
        if (tamTotal > tamanho)
        {
            tamanho *= 2;
            char *novoConteudo = (char *)realloc(conteudo, tamanho * sizeof(char));
            if (novoConteudo == NULL)
            {
                printf("Erro ao realocar memoria");
                free(conteudo);
                fclose(arquivoLeitura);
                return NULL;
            }
            conteudo = novoConteudo;
        }
        strcat(conteudo, string);
    }

    fclose(arquivoLeitura);
    return conteudo;
}

double *inicializaArranjoDouble(int tamanho)
{
    double *arranjo = (double *)malloc(tamanho * sizeof(double));
    if (arranjo == NULL)
    {
        printf("Falha na alocacao de memoria\n");
        return NULL;
    }
    for (int i = 0; i < tamanho; i++)
    {
        arranjo[i] = 0.0;
    }

    return arranjo;
}

int *inicializaArranjoInt(int tamanho)
{
    int *arranjo = (int *)malloc(tamanho * sizeof(int));
    if (arranjo == NULL)
    {
        printf("Falha na alocacao de memoria\n");
        return NULL;
    }
    for (int i = 0; i < tamanho; i++)
    {
        arranjo[i] = 0;
    }

    return arranjo;
}
POINTER_ARRAY iniciador(int n)
{
    POINTER_ARRAY estrutura = (POINTER_ARRAY)malloc(sizeof(ARRANJO));
    if (estrutura == NULL)
    {
        printf("SEM ESPACO\n");
        return estrutura;
    }
    estrutura->tamanho = n;
    estrutura->arranjo = (int *)malloc(n * sizeof(int));
    if (estrutura->arranjo == NULL)
    {
        printf("NAO HA ESPACO\n");
        return estrutura;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Elemento[%d]: ", i + 1);
        scanf("%d", &estrutura->arranjo[i]);
    }

    return estrutura;
}

char *push_front(char *string, char c)
{
    int tamanho = strlen(string) + 1;

    char *aux = (char *)calloc(tamanho, sizeof(char));
    if (aux == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++)
    {
        aux[i] = string[i];
    }

    tamanho = strlen(string) + 2;

    char *result = (char *)calloc(tamanho, sizeof(char));

    if (result == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return NULL;
    }
    int j = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (i == 0)
        {
            result[i] = c;
        }
        else
        {
            result[i] = aux[j];
            j++;
        }
    }
    result[tamanho] = '\0';
    free(aux);

    return result;
}

char *pop_front(char *string)
{
    int tamanho = strlen(string);
    char *result = (char *)calloc(tamanho, sizeof(char));
    if (result == NULL)
    {
        printf("Erro na alocacao de memoria");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++)
    {
        result[i] = string[i + 1];
    }

    result[tamanho] = '\0';
    return result;
}

char *pop_back(char *string)
{
    int tamanho = strlen(string);

    char *result = calloc(tamanho, sizeof(char));
    if (result == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++)
    {
        result[i] = string[i];
        if (i == tamanho - 1)
        {
            result[i] = '\0';
        }
    }

    return result;
}


