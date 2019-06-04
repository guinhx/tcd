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
    int aux = -1;
    for(i=0; i < 4; i++){
        if(voo[i].numero == num){
            aux = 1;
            printf("--- VOO ENCONTRADO ---\nVoo de número (%d)\nOrigem: %s\nDestino: %s\nData: %02d/%02d/2019 - Horário: %02d:%02d\n------------------\n", num, voo[i].origem, voo[i].destino, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m);
            break;
        }else{
            aux = 0;
        }
    }
    if(aux == 0){
        printf("Não existe nenhum voo com o número informado.");
    }
}
void porOrigem(v *voo){
    char origem[30];
    printf("Informe a origem do voo: ");
    scanf("%s", origem);
    int i;
    int aux = -1;
    printf("\nVOO(s) encontrado: ");
    for(i=0; i < 4; i++){
        if(strcmp(voo[i].origem, origem)){
            aux = 1;
            printf("Voo de número (%d)\nOrigem: %s\nDestino: %s\nData: %02d/%02d/2019 - Horário: %02d:%02d\n", voo[i].numero, voo[i].origem, voo[i].destino, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m);
        }else{
            aux = 0;
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
    int aux = -1;
    printf("\nVOO(s) encontrado: \n");
    for(i=0; i < 4; i++){
        if(strcmp(voo[i].destino, destino)){
            aux = 1;
            printf("Voo de número (%d)\nOrigem: %s\nDestino: %s\nData: %02d/%02d/2019 - Horário: %02d:%02d\n", voo[i].numero, voo[i].origem, voo[i].destino, voo[i].data.dia, voo[i].data.mes, voo[i].horario.h, voo[i].horario.m);
        }else{
            aux = 0;
        }
    }
    if(aux == 0){
        printf(" - Não existe nenhum voo com o destino informado.");
    }
}
