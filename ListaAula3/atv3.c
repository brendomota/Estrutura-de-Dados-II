#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanho_reg(FILE *fd, char *registro)
{
    char byte;

    if (!fread(&byte, sizeof(char), 1, fd))
    {
        return 0;
    }
    else
    {
        fread(registro, byte, 1, fd);
        registro[byte] = '\0';
        return byte;
    }
}

void pesquisa(FILE *fd, int num, char *registro)
{

    int aux = 0;

    for (int i = 0; i < num; i++)
    {
        int byte = tamanho_reg(fd, registro);
        aux += byte;
    }

    fseek(fd, aux, 0);

    char *ptrchar = strtok(registro, "|");
    while (ptrchar != NULL)
    {
        printf("\n%s", ptrchar);
        ptrchar = strtok(NULL, "|");
    }
}

int main()
{
    FILE *fd = fopen("campo_var_reg_var.dad", "r+b");

    if (!fd)
    {
        printf("\nNao foi possivel abrir o arquivo");
        return 0;
    }

    char registro[90];
    char *ptrchar;

    int tam = tamanho_reg(fd, registro);
    while (tam > 0)
    {
        printf("\nTamanho: %d", tam);
        ptrchar = strtok(registro, "|");
        while (ptrchar != NULL)
        {
            printf("\n%s", ptrchar);
            ptrchar = strtok(NULL, "|");
        }
        tam = tamanho_reg(fd, registro);
        getchar();
    }

    printf("\n-----Pesquisa-----");
    printf("\nDigite um numero: ");
    int num;
    scanf("%d", &num);
    rewind(fd);

    pesquisa(fd, num, registro);

    fclose(fd);
    return 0;
}