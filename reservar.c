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
typedef struct{
    char nome[48];
    int cpf;
    int voo;
    int poltrona;
    d data;
    h horario;
    float valor;
} g;
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
int pos[2];
int existe(v *voo, int num);
int * GetPos(int value);

void reservar(v *voo){
    int n, n2;
    printf("\n--- RESERVAR PASSAGEM ---\n");
    printf("Informe o número de voo:");
    scanf("%d", &n);
    int index = existe(voo, n);
    if(index != -1){
        printf("Informe o número da poltrona: ");
        scanf("%d", &n2);
        if(voo[index].poltronas.lugares[GetPos(n2)[0]][GetPos(n2)[1]] == 1){
            printf(" - A poltrona não está disponivel!\n");
        }else{
            printf(" - Reserva confirmada.\n");
            voo[index].poltronas.disponiveis--;
            voo[index].poltronas.lugares[GetPos(n2)[0]][GetPos(n2)[1]] = 1;
        }
    }else{
        printf(" - Não existe nenhum voo com o número informado!\n");
    }
}
