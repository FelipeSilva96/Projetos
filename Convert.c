#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Funcao para converter um inteiro positivo em base 2, 4, 8 ou 16
    Aceita dois parametros - @Param #1 int >= 0 // @Param #2 base p/ conversao

*/

char *Convert(int x, int base)
{

    char *result = (char *)malloc(100 * sizeof(char));

    if (!(base == 2 || base == 4 || base == 8 || base == 16))
    {
        printf("\nBase invalida\n");
        result = NULL;
    }

    int q = x;
    int *r = (int *)malloc(100 * sizeof(int));
    int *array = NULL;
    int cont = 0;
    if (x >= 0)
    {
        do
        {
            r[cont] = q % base;
            q = q / base;
            cont++;
        } while (q != 0);
    }
    else
    {
        printf("\nParam #1 menor que 0 (zero)\n");
        result = NULL;
    }

    array = (int *)malloc(cont * sizeof(int));
    int j = cont;
    for (int i = 0; i < cont; i++)
    {
        array[i] = r[j - 1];
        j--;
    }

    for (int i = 0; i < cont; i++)
    {
        if (array[i] >= 10)
        {
            int ultimo = array[i] % 10;
            result[i] = ultimo + 'A';
        }
        else
        {
            result[i] = array[i] + 48;
        }
    }

    result[cont] = '\0';

    free(r);
    free(array);
    return result;
}

int main(void)
{
    char *result = NULL;

    for (int i = 250; i < 256; i++) // Teste com lista de valores
    {
        result = Convert(i, 2);
        printf("\nDecimal = %d -> Hexadecimal = %s", i, result);
    }

    free(result);

    return 0;
}
