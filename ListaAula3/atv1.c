#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fd;

    struct endereco
    {
        char nome[15];
        char sobrenome[15];
        char rua[26];
        int numero;
    }ts;

    fd = fopen("fixo.dad", "r+b");

    if(!fd)
    {
        printf("nao foi possivel abrir o arquivo;");
        return 0;
    }

    while(fread(&ts, sizeof(ts), 1, fd))
    {
        printf("\nNome: %s", ts.nome);
        printf("\nSobrenome: %s", ts.sobrenome);
        printf("\nRua: %s", ts.rua);
        printf("\nNumero: %d", ts.numero);
        getchar();
    }

    printf("\n...Pesquisa...");
    printf("\nNumero do registro: ");
    int reg;
    scanf("%d", &reg);
    fseek(fd, sizeof(ts) * (reg - 1), 0);
    fread(&ts, sizeof(ts), 1, fd);
    printf("\n%s %s %s %d", ts.nome, ts.sobrenome, ts.rua, ts.numero);

    fclose(fd);

    return 0;
}