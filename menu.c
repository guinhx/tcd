#include <stdio.h>
int menu(){
	int op = 0;
	do{
        printf("Sistema Internacional de Voo's.\n");
        printf("1 – Consultar\n2 – Efetuar Reserva\n3 – Sair\nEscolha uma opção: ");
		scanf("%d", &op);
	}while(op < 1 && op > 3);
	return op;
}
