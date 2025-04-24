#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct {
	char nome_sala[50];
	int horario_abertura;
	int horario_fechamento;
	int cadeiras;
	int reservas;
}Sala;

typedef struct{
	char nome[50];
	int matricula;
	char materia[50];
	int opcao;
}Pessoa;

typedef struct {
    Pessoa pessoa;
    Sala sala;
} Reserva;


int main (void){
	setlocale(LC_ALL, "Portuguese");
	Pessoa pessoa;
	Reserva reservas[100];
	Sala sala;
	int qtd_reservadas = 0;
	Sala salas[] = {
    	{"LAB. Ciência", 10, 20, 30, 0},
   		{"LAB. TI", 10, 20, 30, 0},
    	{"LAB. Medicina", 10, 20, 30, 0}
		};
	int QTD_SALAS = sizeof(salas) / sizeof(salas[0]);
	
	while(1){
		
		printf("======= RESERVA DE SALAS ======\n\n");
	
		printf("Digite seu nome: ");
		fgets(pessoa.nome, 50, stdin);
		printf("\n");
		printf("Digite sua matricula: ");
		scanf("%d", &pessoa.matricula);
		getchar();
		printf("\n");
		printf("Digite qual materia você estuda: ");
		fgets(pessoa.materia, 50, stdin);
	
		printf("\n\n");
	
		int i;
		printf("Salas disponíveis:\n");
		for (i = 0; i < QTD_SALAS; i++) {
    		printf("%d - %s (Horario de Abertura %dAM / Horario de fechamento %dPM) Reservas: %d\n\n", i + 1, salas[i].nome_sala, salas[i].horario_abertura, salas[i].horario_fechamento, salas[i].reservas);
		}
		printf("Digite o número da sala que você quer escolher (0 para sair): ");
		scanf("%d", &pessoa.opcao);
		if (pessoa.opcao == 0){
			break;
		}
		printf("\n");
		printf("Digite o horario de inicio da reserva: ");
		scanf("%d", &sala.horario_abertura);
		printf("\n");
		printf("Digite o horario de termino da reserva: ");
		scanf("%d", &sala.horario_fechamento);
		printf("\n\n");
		if (pessoa.opcao > 0 && pessoa.opcao <= QTD_SALAS){
			if(sala.horario_abertura >= salas[pessoa.opcao -1].horario_abertura
		 && salas[pessoa.opcao - 1].horario_fechamento >= sala.horario_fechamento){
			int conflito = 0;
			int j;
			for (j = 0; j < qtd_reservadas; j++){
				if (reservas[j].sala.horario_fechamento > sala.horario_abertura && sala.horario_fechamento > reservas[j].sala.horario_abertura){
					printf("A sala já está reservada para este horario.");
					conflito = 1;
				}
			}
			if (!conflito){
				reservas[qtd_reservadas].pessoa = pessoa;
				reservas[qtd_reservadas].sala = salas[pessoa.opcao - 1];
				reservas[qtd_reservadas].sala.horario_abertura = sala.horario_abertura;
				reservas[qtd_reservadas].sala.horario_fechamento = sala.horario_fechamento;
				qtd_reservadas++;
				
				printf("reserva confirmada, sala %s de %d até %d.\n\n", reservas[qtd_reservadas-1].sala.nome_sala, reservas[qtd_reservadas-1].sala.horario_abertura, reservas[qtd_reservadas-1].sala.horario_fechamento);
			}
		}else{
            printf("Horário fora do intervalo permitido para esta sala.\n");
		}
		
		}else {
			printf("Opção invalida!");
			
		}
		
	
	}
}
	int a;
	printf("====== RESERVAS ======\n\n");
	for (a = 0; a < qtd_reservadas; a++){
		printf("Sala reservada: %s\nEm nome de: %s\nHorario de inicio da reserva: %d. Horario de fim da reserva: %d", reservas[a].sala.nome_sala, reservas[a].pessoa.nome, reservas[a].sala.horario_abertura, reservas[a].sala.horario_fechamento);
		printf("\n\n");
	}
	return 0;

}
