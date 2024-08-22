#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{

    FILE *fd = fopen("campo_var_reg_fixo.dad", "r+b");

    if (!fd)
    {
        printf("\nNao foi possivel abrir o arquivo");
        return 1;
    }

    char reg[60];
    int numero_reg;
    char *ptrchar;

    while (fread(&reg, sizeof(reg), 1, fd))
    {
        ptrchar = strtok(reg, "|");

        while (ptrchar != NULL)
        {
            printf("\n%s", ptrchar);
            ptrchar = strtok(NULL, "|");
        }
        printf("\n");
    }

    printf("\n------Pesquisa------");
    printf("\nEscolha um numero: ");
    scanf("%d", &numero_reg);
    fseek(fd, sizeof(reg) * (numero_reg - 1), 0);

    fread(&reg, sizeof(reg), 1, fd);
    ptrchar = strtok(reg, "|");
    while (ptrchar != NULL)
    {
        printf("\n%s", ptrchar);
        ptrchar = strtok(NULL, "|");
    }
    printf("\n");
}