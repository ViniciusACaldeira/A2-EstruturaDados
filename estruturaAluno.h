#include <stdio.h>

//ESTRUTURA DO ALUNO

struct notasAlunos
{
	float nVetorNotas[3] = {0,0,0};
};

struct Aluno
{
	char strNome[30] = "";
	int  nRA = 0;
	char strDisciplina[30] = "";
	int  nDisciplina;
	notasAlunos ntAlunos;
};

struct fila
{
	Aluno aluno;
	struct fila *ptr;
};
