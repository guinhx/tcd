#include <stdio.h>
#include <time.h>

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
int pos[2];
int existe(v *voo, int num);
int * GetPos(int value);

/*
    Função usada para retornar a quantidade de dias entre uma data e outra.
    Primeiro e segundo parametro é referente a data inicial (dia/mes).
    Terceiro e quarto parametro é referente a data final (dia/mes).
*/

int GetDifference(int day, int mon, int day2, int mon2){
    time_t t;
	time(&t);

	struct tm local;
	local = *localtime(&t);

	local.tm_mday = day;
	local.tm_mon = mon - 1;
	local.tm_year = 2019 - 1900;

	int time1 = mktime(&local);

    local.tm_mday = day2;
	local.tm_mon = mon2 - 1;
	local.tm_year = 2019 - 1900;

	int time2 = mktime(&local);

	double sec = difftime(time2, time1);
	int df = sec/(60*60*24);

	return df;
}

void reservar(v *voo){
    int n, n2;
    printf("\n--- RESERVAR PASSAGEM ---\n");
    printf("Informe o número de voo: ");
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
            char nome[64];
            printf("Para finalizar a reserva preencha os seguintes dados: \n");
            printf(" - Nome completo: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", nome);
            setbuf(stdin, NULL);
            int cpf;
            printf(" - CPF: ");
            scanf("%d", &cpf);
            int poltrona = n2;
            time_t mytime;
            mytime = time(NULL);
            struct tm tm = *localtime(&mytime);
            float valor = 0.0;
            int dias = GetDifference(tm.tm_mday, tm.tm_mon+1, voo[index].data.dia, voo[index].data.mes);
            int aux = dias/30;
            if(aux >= 1){
                valor = voo[index].valor - (voo[index].valor * (0.05 * aux));
            }
            printf("\n===----------- COMPROVANTE -----------===\n");
            printf("    Nome: %s\n", nome);
            printf("    CPF: %08d\n", cpf);
            printf("    Origem: %s - Destino: %s\n", voo[index].origem, voo[index].destino);
            printf("    Data: %02d/%02d/2019 - Horario: %02d:%02d\n", voo[index].data.dia, voo[index].data.mes, voo[index].horario.h, voo[index].horario.m);
            printf("    Poltrona: %d [C%d|L%d]\n", poltrona, GetPos(poltrona)[0], GetPos(poltrona)[1]);
            printf("    Compra realizada em: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
            printf("    Valor: R$%.2f\n", valor);
            printf("===-----------------------------------===\n\n");
        }
    }else{
        printf(" - Não existe nenhum voo com o número informado!\n");
    }
}
