#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
} d;

typedef struct
{
    int h;
    int m;
} h;
typedef struct
{
    int disponiveis, total;
    int lugares[30][6];
} p;
typedef struct
{
    int numero;
    char origem[30];
    char destino[30];
    d data;
    h horario;
    float valor;
    p poltronas;
} v;
void cadastro(v *voo)
{
    printf("--- CADASTRO DE VOO ---\n");
    int i;
    char r[1];
    for(i = 0; i < 4; i++)
    {
        printf("Deseja pular o cadastro? (s/n)\n");
        scanf("%s", &r);
        char cidades[30][10] = {{"Brasilia"}, {"Unai"}, {"Brasilandia"}, {"Paracatu"}, {"Salvador"}, {"Uberlândia"} , {"Patos de Minas"}, {"Juazeiro"}, {"Feira de Santana"}};
        if(strcmp(r, "s") == 0)
        {
            voo[i].numero = rand() % 10;
            int j;
            int randPos = rand() % 9;
            for(j = 0; j < 30; j++){
                voo[i].origem[j] = cidades[j][randPos];
            }
            randPos = rand() % 9;
            for(j = 0; j < 30; j++){
                voo[i].destino[j] = cidades[j][randPos];
            }
            voo[i].data.dia = (rand() % 30) + 1;
            voo[i].data.mes = (rand() % 12) + 1;
            voo[i].horario.h = rand() % 24;
            voo[i].horario.m = rand() % 60;
            voo[i].valor = rand() % 1000;
            int x, y;
            for(x = 0; x <= 5; x++)
            {
                for(y = 0; y <= 29; y++)
                {
                    voo[i].poltronas.lugares[y][x] = 0;
                }
            }
            voo[i].poltronas.disponiveis = 180;
            voo[i].poltronas.total = 180;
            printf("Voo de número %d cadastrado.\n", voo[i].numero);
        }
        else
        {
            printf("Número do voo: ");
            scanf("%d", &voo[i].numero);
            printf("Origem: ");
            scanf("%s", &voo[i].origem);
            printf("Destino: ");
            scanf("%s", &voo[i].destino);
            printf("Data: ");
            scanf("%d%*c%d", &voo[i].data.dia, &voo[i].data.mes);
            printf("Horário: ");
            scanf("%d%*c%d", &voo[i].horario.h, &voo[i].horario.m);
            printf("Valor: ");
            scanf("%f", &voo[i].valor);
            int x, y;
            for(x = 0; x <= 5; x++)
            {
                for(y = 0; y <= 29; y++)
                {
                    voo[i].poltronas.lugares[y][x] = 0;
                }
            }
            voo[i].poltronas.disponiveis = 180;
            voo[i].poltronas.total = 180;
            printf("Voo de número %d cadastrado.\n\n", voo[i].numero);
        }
    }
}
int existe(v *voo, int num)
{
    int i;
    for(i = 0; i <= 3; i++)
    {
        if(voo[i].numero == num)
        {
            return i;
        }
    }
    return -1;
}
