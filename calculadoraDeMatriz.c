#include "fps.h" // bib propria

void metodo_00(void) // metodo_00 - nao faz nada.
{
}

struct Matriz
{
    int linhas;
    int colunas;
    double **matriz;
    double **transposta;
    int **identidade;
    double *diagonalPrincipal;
    double *diagonalSecundaria;
    double **inversa;
    double **adjunta;
    double **resultanteSomada;
    double **resultanteSubtraida;
    double escalar;
    int tamanho;
    double **escalada;
    double determinante;
    double **matrizProduto;
    bool x;
};
typedef struct Matriz MATRIZ;

MATRIZ leMatriz()
{
    MATRIZ dados;

    printf("\nInsira os elementos da matriz (Colunas, Linhas, Elementos):\n\n");
    printf("Quantidade de linhas: ");
    scanf("%d", &dados.linhas);
    printf("Quantidade de colunas: ");
    scanf("%d", &dados.colunas);
    printf("\n");
    dados.matriz = inicializaMatriz(dados.linhas, dados.colunas);
    // int k = 1;
    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            printf("Elementos[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &dados.matriz[i][j]);
            // dados.matriz[i][j] = k;
            // k++;
        }
    }
    return dados;
}

MATRIZ matrizTransposta(MATRIZ dados)
{
    dados.transposta = inicializaMatriz(dados.colunas, dados.linhas); // função de biblioteca propria

    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            dados.transposta[j][i] = dados.matriz[i][j];
        }
    }
    return dados;
}

void mostrarMatriz(MATRIZ dados)
{
    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            printf("%.0lf\t", dados.matriz[i][j]);
        }
        printf("\n");
    }
}

void metodo_01(void)
{
    MATRIZ dados = leMatriz();

    printf("\nMatriz inserida: \n\n");

    mostrarMatriz(dados);

    printf("Sua transposta: \n\n");

    dados = matrizTransposta(dados);

    for (int i = 0; i < dados.colunas; i++)
    {
        for (int j = 0; j < dados.linhas; j++)
        {
            printf("%.0lf\t", dados.transposta[i][j]);
        }
        printf("\n");
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);     // função de biblioteca propria
    liberaMatrizDouble(dados.transposta, dados.linhas); // função de biblioteca propria
}

MATRIZ diagonalP(MATRIZ dados)
{
    dados.diagonalPrincipal = inicializaArranjoDouble(dados.linhas);
    dados.tamanho = 0;
    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {

            if (i == j)
            {

                dados.diagonalPrincipal[dados.tamanho] = dados.matriz[i][j];

                dados.tamanho++;
            }
        }
    }

    return dados;
}

void metodo_02(void)
{
    printf("\nObs: Para mostrar uma diagonal Principal, a matriz deve ser quadrada\n\n");

    MATRIZ dados = leMatriz();

    printf("\nMatriz inserida: \n\n");

    mostrarMatriz(dados);

    if (dados.linhas == dados.colunas)
    {

        printf("\nSua diagonal principal:\n");

        dados = diagonalP(dados);

        for (int i = 0; i < dados.tamanho; i++)
        {
            printf("%.0lf ", dados.diagonalPrincipal[i]);
        }
        free(dados.diagonalPrincipal);
    }
    else
    {
        printf("Nao foi possivel mostrar a diagonal principal porque a matriz nao e quadrada.\n");
    }
    liberaMatrizDouble(dados.matriz, dados.linhas);
    free(dados.diagonalPrincipal);
}

MATRIZ diagonalS(MATRIZ dados)
{
    dados.diagonalSecundaria = inicializaArranjoDouble(dados.linhas);
    dados.tamanho = 0;
    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {

            if (j == dados.colunas - 1 - i)
            {
                dados.diagonalSecundaria[dados.tamanho] = dados.matriz[i][j];
                dados.tamanho++;
            }
        }
    }

    return dados;
}

void metodo_03(void)
{

    printf("\nObs: Para mostrar uma diagonal Secundaria, a matriz deve ser quadrada\n\n");

    MATRIZ dados = leMatriz();

    printf("\nMatriz inserida: \n\n");

    mostrarMatriz(dados);

    if (dados.linhas == dados.colunas)
    {
        printf("\nSua diagonal secundaria:\n");

        dados = diagonalS(dados);

        for (int i = 0; i < dados.tamanho; i++)
        {
            printf("%.0lf ", dados.diagonalSecundaria[i]);
        }
        free(dados.diagonalSecundaria);
    }
    else
    {
        printf("Nao foi possivel mostrar a diagonal secundaria porque a matriz nao e quadrada.\n");
    }
    liberaMatrizDouble(dados.matriz, dados.linhas);
    free(dados.diagonalSecundaria);
}

double determinanteRecursivo(double **matriz, int n)
{
    if (n == 1)
    {
        return matriz[0][0];
    }
    if (n == 2)
    {
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }

    double det = 0;
    double **submatriz = inicializaMatriz(n - 1, n - 1);

    for (int x = 0; x < n; x++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                    continue;
                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * determinanteRecursivo(submatriz, n - 1);
    }

    liberaMatrizDouble(submatriz, n - 1);

    return det;
}

MATRIZ determinante(MATRIZ dados)
{
    dados.determinante = determinanteRecursivo(dados.matriz, dados.linhas);
    return dados;
}

void metodo_04(void)
{
    printf("Obs: Para calculo do determinante, a matriz deve ser quadrada.\n");
    MATRIZ dados = leMatriz();

    printf("\nMatriz Inserida: \n\n");

    mostrarMatriz(dados);

    if (dados.linhas != dados.colunas)
    {
        printf("A matriz deve ser quadrada para calcular o determinante.\n");
    }
    else
    {
        dados = determinante(dados);

        printf("\nDeterminante da matriz: ");
        printf("%.2lf ", dados.determinante);
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);
}

double **cofator(double **matriz, int p, int q, int n)
{
    int i = 0, j = 0;
    double **temp = inicializaMatriz(n, n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matriz[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }

    return temp;
}

MATRIZ matrizAdjunta(MATRIZ dados)
{
    dados.adjunta = inicializaMatriz(dados.linhas, dados.colunas);
    if (dados.linhas == 1)
    {
        dados.adjunta[0][0] = 1;
        return dados;
    }

    int sinal = 1;
    double **temp;

    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            temp = cofator(dados.matriz, i, j, dados.linhas);
            sinal = ((i + j) % 2 == 0) ? 1 : -1;
            dados.adjunta[j][i] = sinal * determinanteRecursivo(temp, dados.linhas - 1);
            liberaMatrizDouble(temp, dados.linhas - 1);
        }
    }
    return dados;
}

void metodo_05(void)
{
    printf("Obs: Para calcular a matriz adjunta, a matriz deve ser quadrada.\n");
    MATRIZ dados = leMatriz();

    printf("Matriz Inserida: \n\n");
    mostrarMatriz(dados);

    if (dados.linhas != dados.colunas)
    {
        printf("A matriz deve ser quadrada para calcular a adjunta.\n");
    }
    else
    {
        dados = matrizAdjunta(dados);

        printf("Matriz adjunta: \n\n");
        for (int i = 0; i < dados.linhas; i++)
        {
            for (int j = 0; j < dados.colunas; j++)
            {
                printf("%.2lf\t", dados.adjunta[i][j]);
            }
            printf("\n");
        }
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados.adjunta, dados.linhas);
}

double **gaussJordan(double **matriz, int n)
{
    double **temp = inicializaMatriz(n, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = matriz[i][j];
        }
    }

    double **identidade = inicializaMatriz(n, n);

    for (int i = 0; i < n; i++)
    {
        identidade[i][i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        double pivô = temp[i][i];

        for (int j = 0; j < n; j++)
        {
            temp[i][j] /= pivô;
            identidade[i][j] /= pivô;
        }

        for (int k = 0; k < n; k++)
        {
            if (i != k)
            {
                double fator = temp[k][i];
                for (int j = 0; j < n; j++)
                {
                    temp[k][j] -= fator * temp[i][j];
                    identidade[k][j] -= fator * identidade[i][j];
                }
            }
        }
    }

    liberaMatrizDouble(temp, n);

    return identidade;
}

MATRIZ matrizInversa(MATRIZ dados)
{
    dados.inversa = gaussJordan(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados.inversa, dados.linhas);

    return dados;
}

void metodo_06(void)
{
    printf("\n\nObs: Para calcular a matriz inversa, a matriz deve ser quadrada.\n");
    printf("\nCaso a matriz inversa mostre inf/-inf como elementos, o determinante da mesma = zero.\n");

    MATRIZ dados = leMatriz();

    printf("Matriz Inserida: \n\n");
    mostrarMatriz(dados);

    if (dados.linhas != dados.colunas)
    {
        printf("A matriz deve ser quadrada para calcular a inversa.\n");
    }
    else
    {
        dados = matrizInversa(dados);

        printf("Matriz inversa: \n\n");
        for (int i = 0; i < dados.linhas; i++)
        {
            for (int j = 0; j < dados.colunas; j++)
            {
                printf("%.2lf\t", dados.inversa[i][j]);
            }
            printf("\n");
        }

        liberaMatrizDouble(dados.inversa, dados.linhas);
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados.inversa, dados.linhas);
}

MATRIZ matrizEscalada(MATRIZ dados)
{
    dados.escalada = inicializaMatriz(dados.linhas, dados.colunas);

    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            dados.escalada[i][j] = dados.matriz[i][j] * dados.escalar;
        }
    }

    return dados;
}
void metodo_07(void)
{
    MATRIZ dados = leMatriz();

    printf("\nInsira um escalar para multiplicar sua matriz:\n");
    scanf("%lf", &dados.escalar);

    printf("Matriz inserida: \n\n");

    mostrarMatriz(dados);

    MATRIZ dados2 = matrizEscalada(dados);
    printf("Matriz escalada por %.0lf: \n\n", dados2.escalar);

    for (int i = 0; i < dados2.linhas; i++)
    {
        for (int j = 0; j < dados2.colunas; j++)
        {
            printf("%.0lf\t", dados2.escalada[i][j]);
        }
        printf("\n");
    }

    liberaMatrizDouble(dados2.escalada, dados2.linhas);
}

MATRIZ multiplicarMatrizes(MATRIZ dados, MATRIZ dados2)
{
    MATRIZ dados3;
    dados.x = false;
    if (dados.colunas != dados2.linhas)
    {
        return dados;
    }
    else
    {
        dados.x = true;
        dados3.matrizProduto = (double **)malloc(dados.linhas * sizeof(double *));

        for (int i = 0; i < dados.linhas; i++)
        {
            dados3.matrizProduto[i] = (double *)malloc(dados2.colunas * sizeof(double));
        }
        for (int i = 0; i < dados.linhas; i++)
        {

            for (int j = 0; j < dados2.colunas; j++)
            {
                dados3.matrizProduto[i][j] = 0;
                for (int k = 0; k < dados.colunas; k++)
                {
                    dados3.matrizProduto[i][j] += dados.matriz[i][k] * dados2.matriz[k][j];
                }
            }
        }
        dados3.linhas = dados.linhas;
        dados3.colunas = dados2.colunas;
    }

    return dados3;
}
void metodo_08(void)
{
    printf("\nObs: Para multiplicacao entre matrizes, e necessario que a segunda tenha o numero de linhas igual ao numero de colunas da primeira matriz\n");
    MATRIZ dados;
    MATRIZ dados2;
    MATRIZ dados3;
    printf("\nPrimeira Matriz:\n");
    dados = leMatriz();
    printf("\nSegunda Matriz:\n");
    dados2 = leMatriz();
    printf("\n\nMatriz 1:\n\n");
    mostrarMatriz(dados);
    printf("\n\nMatriz 2:\n\n");
    mostrarMatriz(dados2);
    if (dados.colunas != dados2.linhas)
    {
        printf("\n\nA matriz nao pode ser multiplicada pois o numero de colunas da primeira e diferente do numero de linhas da segunda.\n\n");
    }
    else
    {
        printf("\nMatriz resultante da multiplicacao (%dx%d): \n\n", dados.linhas, dados2.colunas);

        dados3 = multiplicarMatrizes(dados, dados2);

        for (int i = 0; i < dados3.linhas; i++)
        {
            for (int j = 0; j < dados3.colunas; j++)
            {
                printf("%.0lf ", dados3.matrizProduto[i][j]);
            }
            printf("\n");
        }
    }
    liberaMatrizDouble(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados2.matriz, dados2.linhas);
    liberaMatrizDouble(dados3.matrizProduto, dados3.linhas);
}

MATRIZ matrizSomada(MATRIZ dados, MATRIZ dados2)
{

    dados.resultanteSomada = inicializaMatriz(dados.linhas, dados.colunas); // função em biblioteca propria
    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            dados.resultanteSomada[i][j] = dados.matriz[i][j] + dados2.matriz[i][j];
        }
    }
    return dados;
}
void metodo_09(void)
{
    printf("\nObs: Para somar duas matrizes, ambas devem ter as mesmas dimensoes\n\n");

    MATRIZ dados = leMatriz();
    printf("\nAgora insira uma segunda matriz.\n\n");
    MATRIZ dados2 = leMatriz();
    printf("\nMatriz A:\n");
    mostrarMatriz(dados);
    printf("\nMatriz B:\n");
    mostrarMatriz(dados2);

    MATRIZ dados3 = matrizSomada(dados, dados2);

    if (dados.linhas == dados2.linhas && dados.colunas == dados2.colunas)
    {
        printf("\nMatriz resultante (A + B):\n\n");
        for (int i = 0; i < dados3.linhas; i++)
        {
            for (int j = 0; j < dados3.colunas; j++)
            {
                printf("%.0lf\t", dados3.resultanteSomada[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nNao foi possivel somar as matrizes porque elas tem dimensoes diferentes.\n\n");
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados2.matriz, dados2.linhas);
    liberaMatrizDouble(dados3.resultanteSomada, dados3.linhas);
}

MATRIZ matrizSubtraida(MATRIZ dados, MATRIZ dados2)
{
    dados.resultanteSubtraida = inicializaMatriz(dados.linhas, dados.colunas); // função em biblioteca propria

    for (int i = 0; i < dados.linhas; i++)
    {
        for (int j = 0; j < dados.colunas; j++)
        {
            dados.resultanteSubtraida[i][j] = dados.matriz[i][j] - dados2.matriz[i][j];
        }
    }
    return dados;
}
void metodo_10(void)
{
    printf("\nObs: Para subtrair duas matrizes, ambas devem ter as mesmas dimensoes\n\n");

    MATRIZ dados = leMatriz();
    printf("\nAgora insira uma segunda matriz.\n\n");
    MATRIZ dados2 = leMatriz();
    printf("\nMatriz A:\n");
    mostrarMatriz(dados);
    printf("\nMatriz B:\n");
    mostrarMatriz(dados2);

    MATRIZ dados3 = matrizSubtraida(dados, dados2);

    if (dados.linhas == dados2.linhas && dados.colunas == dados2.colunas)
    {
        printf("\nMatriz resultante (A - B):\n\n");
        for (int i = 0; i < dados3.linhas; i++)
        {
            for (int j = 0; j < dados3.colunas; j++)
            {
                printf("%.0lf\t", dados3.resultanteSubtraida[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n\nNao foi possivel subtrair as matrizes porque elas tem dimensoes diferentes.\n\n");
    }

    liberaMatrizDouble(dados.matriz, dados.linhas);
    liberaMatrizDouble(dados2.matriz, dados2.linhas);
    liberaMatrizDouble(dados3.resultanteSomada, dados3.linhas);
}

int main(void) // main - inicio do funcionamento do programa
{
    int opcao = 0;
    
    printf("\t\tVamos comecar selecionando abaixo o que deseja fazer!\n\n");

    do
    {

        printf("\nOpcoes:\n");
        printf("\n 0 - Sair");
        printf("\n 1 - Mostrar matriz e sua transposta");
        printf("\n 2 - Mostrar matriz e sua diagonal principal");
        printf("\n 3 - Mostrar matriz e sua diagonal secundaria");
        printf("\n 4 - Mostrar matriz e determinante");
        printf("\n 5 - Mostrar matriz e adjunta");
        printf("\n 6 - Mostrar matriz e inversa");
        printf("\n 7 - Multiplicar por escalar.");
        printf("\n 8 - Multiplicar por outra matriz.");
        printf("\n 9 - Somar com outra matriz.");
        printf("\n10 - Subtrair de outra matriz.");

        printf("\n");
        printf("\nDigite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            metodo_00();
            break;
        case 1:
            metodo_01();
            break;
        case 2:
            metodo_02();
            break;
        case 3:
            metodo_03();
            break;
        case 4:
            metodo_04();
            break;
        case 5:
            metodo_05();
            break;
        case 6:
            metodo_06();
            break;
        case 7:
            metodo_07();
            break;
        case 8:
            metodo_08();
            break;
        case 9:
            metodo_09();
            break;
        case 10:
            metodo_10();
            break;
        default:
            printf("\nERRO: Valor invalido.\n");
        }

    } while (opcao != 0);

    printf("\nApertar ENTER para terminar.\n");

    getchar(); // aguardar por ENTER

    system("Pause");

    return (0);
}
