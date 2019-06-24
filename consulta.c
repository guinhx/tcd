#include <stdio.h>
#include <string.h>
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

void porNum(v *voo);
void porOrigem(v *voo);
void porDestino(v *voo);

void consulta(v *voo){
    int op = 0;
    do{
        printf("1 – Por número de voo\n2 – Por origem\n3 – Por destino\nEscolha uma opção: ");
        scanf("%d", &op);
    }while(op < 1 && op > 3);
    switch(op){
        case 1:
        porNum(voo);
        break;
        case 2:
        porOrigem(voo);
        break;
        case 3:
        porDestino(voo);
        break;
    }
}
void porNum(v *voo){
    int num;
    printf("Informe o número do voo: ");
    scanf("%d", &num);
    int i;
    int aux = 0;
    for(i=0; i < 4; i++){
        if(voo[i].numero == num){
            aux++;
            printf("--- VOO ENCONTRADO ---\nNúmero: %d\nOrigem: %s\nDestino: %s.\nVagas: %d/180 disponiveis.\nData: %02d/%02d/2019 - Horário: %02d:%02d\nValor: R$%.2f\n------------------\n", voo[i].numero, voo[i].origem, voo[i].destino, voo[i].poltronas.disponiveis, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m, voo[i].valor);
            break;
        }
    }
    if(aux == 0){
        printf(" - Não existe nenhum voo com o número informado.\n");
    }
}
void porOrigem(v *voo){
    char origem[30];
    printf("Informe a origem do voo: ");
    scanf("%s", origem);
    int i;
    int aux = 0;
    printf("\n--- ENCONTRADO(s) ---\n");
    for(i=0; i < 4; i++){
        if(strcmp(voo[i].origem, origem) == 0 && strlen(voo[i].origem) == strlen(origem)){
            aux++;
            printf("Número: %d\nOrigem: %s\nDestino: %s.\nVagas: %d/180 disponiveis.\nData: %02d/%02d/2019 - Horário: %02d:%02d\nValor: R$%.2f\n------------------\n", voo[i].numero, voo[i].origem, voo[i].destino, voo[i].poltronas.disponiveis, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m, voo[i].valor);
        }
    }
    if(aux == 0){
        printf(" - Não existe nenhum voo com a origem informada.");
    }
}
void porDestino(v *voo){
    char destino[30];
    printf("Informe o destino do voo: ");
    scanf("%s", destino);
    int i;
    int aux = 0;
    printf("\n--- ENCONTRADO(s) ---\n");
    for(i=0; i < 4; i++){
        if(strcmp(voo[i].destino, destino) == 0 && strlen(voo[i].destino) == strlen(destino)){
            aux++;
            printf("Número: %d\nOrigem: %s\nDestino: %s.\nVagas: %d/180 disponiveis.\nData: %02d/%02d/2019 - Horário: %02d:%02d\nValor: R$%.2f\n------------------\n", voo[i].numero, voo[i].origem, voo[i].destino, voo[i].poltronas.disponiveis, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m, voo[i].valor);
        }
    }
    if(aux == 0){
        printf(" - Não existe nenhum voo com o destino informado.");
    }
}
