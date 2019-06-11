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
int existe(v *voo, int num);
void reservar(v *voo){
    int n, n2;
    printf("\n--- RESERVAR PASSAGEM ---\n");
    printf("Informe o n�mero de voo:");
    scanf("%d", &n);
    int index = existe(voo, n);
    if(index != -1){
        printf("Informe o n�mero da poltrona: ");
        scanf("%d", &n2);
        if(voo[index].poltronas.lugares[(n2/6)][(n2/30)] == 1){
            printf(" - A poltrona n�o est� disponivel!\n");
            return;
        }
    }else{
        printf(" - N�o existe nenhum voo com o n�mero informado!");
    }
}
