#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "estruturaDisciplina.h"
#include "estruturaAluno.h"
struct fila *Fila;
struct Disciplina m_Disciplina[10]; 
int m_nDisciplina = 0;
#include "cadastro.h"
#include "alterarCadastro.h"
#include "relatorio.h"

void iniciar_fila (void)
{
	Fila = NULL;
}


int main( )
{
	setlocale(LC_ALL, "Portuguese");
	int op = 99;
	iniciar_fila( );
	
	while( op != 0 )
	{
		printf("\nMENU SISTEMA GERENCIAMENTO DE ALUNO");
		printf("\n [1] Cadastrar Novo Aluno ");
		printf("\n [2] Lançar nota aluno");
		printf("\n [3] Alterar nota aluno");
		printf("\n [4] Relatorio Aluno");
		printf("\n [5] Cadastrar Disciplina");
		printf("\n ");
		
		scanf("%d", &op);
		
		switch( op )
		{
			case 1:
				system("cls");
				cadastrarAluno( );
				break;
			case 2:
			case 3:
				system("cls");
				alterarAluno( op );
				break;
			case 4:
				system("cls");
				relatorioAluno( );
				break;
			case 5:
				system("cls");
				cadastrarDisciplina( );
				break;
			default:
				op == 0;
				break;
		}	
	}
	
}
