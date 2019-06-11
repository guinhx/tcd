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
        menu();
    }
    while(op != 3);
    return 0;
}
