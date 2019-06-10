#include <stdio.h>
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
void cadastro(v *voo){
    printf("--- CADASTRO DE VOO ---\n");
    int i;
    for(i = 0; i < 4; i++){
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
        voo[i].poltronas.disponiveis = 180;
        voo[i].poltronas.total = 180;
        printf("Voo de número %d cadastrado.\n\n", voo[i].numero);
    }
}
