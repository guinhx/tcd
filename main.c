#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int menu();
void consulta(v *voo);
void reservar(v *voo);

void cadastro();
int pos[2];
int * GetPos(int value){
    pos[2];
    if(value > 30 && value <= 60){
        pos[0] = 1;
        pos[1] = value - 31;
    }else if(value > 60 && value <= 90){
        pos[0] = 2;
        pos[1] = value - 61;
    }else if(value > 90 && value <= 120){
        pos[0] = 3;
        pos[1] = value - 91;
    }else if(value > 120 && value <= 150){
        pos[0] = 4;
        pos[1] = value - 121;
    }else if(value > 150 && value <= 180){
        pos[0] = 5;
        pos[1] = value - 151;
    }else{
        pos[0] = 0;
        pos[1] = value - 1;
    }
    return pos;
}

int main()
{
    setlocale(LC_ALL, "");
    v voo[4];
    cadastro(&voo);
    int op = 0;
    op = menu();
    do
    {
        switch(op)
        {
        case 1:
            consulta(&voo);
            break;
        case 2:
            reservar(&voo);
            break;
        }
        op = menu();
    }
    while(op != 3);
    return 0;
}
