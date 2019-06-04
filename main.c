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

void consulta();

void cadastro();

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
        }
        menu();
    }
    while(op != 3);
    return 0;
}
