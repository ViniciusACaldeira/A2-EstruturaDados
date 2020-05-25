char procuraConceito( float fNota )
{
	char cConceito;
	
	if( fNota < 4 )
		cConceito = 'F';
	else if( fNota >= 4 && fNota < 6 )
		cConceito = 'D';
	else if( fNota >= 6 && fNota < 7 )
		cConceito = 'C';
	else if( fNota >= 7 && fNota < 8.5 )
		cConceito = 'B';
	else
		cConceito = 'A';
	
	return cConceito;
}

char *matriz[5][2];

void montaMatriz( )
{
	matriz[0][0] = "A\0";
	matriz[0][1] = "MÉDIA ARITMÉTICA Entre 10 e 8,5 ";
	
	matriz[1][0] = "B\0";
	matriz[1][1] = "MÉDIA ARITMÉTICA Entre 8,4 e 7,0";
	
	matriz[2][0] = "C\0";
	matriz[2][1] = "MÉDIA ARITMÉTICA Entre 6,9 e 6,0";
	
	matriz[3][0] = "D\0";
	matriz[3][1] = "MÉDIA ARITMÉTICA Entre 5,9 e 4 ";
	
	matriz[4][0] = "F\0";
	matriz[4][1] = "MÉDIA ARITMÉTICA Menor que 3,9**";
	
}

void relatorioAluno( )
{
	
	Aluno aluno;
	
	montaMatriz( );
	float fMedia = 0;
	char *cConceito;
	int op;
	
	struct fila *nodo, *head;
	
	if (!Fila) {
		fprintf (stderr, "Fila está vazia\n");
		return;
	}
	
	head = nodo = Fila -> ptr;
	
	int i = 1;
	
	printf("Qual modelo Utilizar? Simplificado (1), Atividade (2): ");
	scanf("%d", &op);
	
	if(	op == 2	)
		printf("CÓDIGO (RA) ! NOME ! DISCIPLINA ! AVAL.1 ! AVAL.2 ! AVAL.3 ! MÉDIA ! CONCEITO ");
	
	do {
		printf("\n");
		if(op == 2)
		{
			printf("%d", nodo -> aluno.nRA);
			printf("\t%s", nodo -> aluno.strNome);
			printf("\t%s", nodo -> aluno.strDisciplina);
			for( int i = 0; i < 3; i++)
			{
				printf("\t%f", nodo -> aluno.ntAlunos.nVetorNotas[i]);
				fMedia += nodo -> aluno.ntAlunos.nVetorNotas[i];
			}
			fMedia = fMedia/3;
			printf("\t%f", fMedia);
			printf("\t%c", procuraConceito( fMedia ));	
		}
		else
		{
			printf("\tALUNO %s", nodo -> aluno.strNome);
			printf("\nCÓDIGO (RA) :%d", nodo -> aluno.nRA);
			printf("\nNOME: %s", nodo -> aluno.strNome);
			printf("\nDISCIPLINA: %s", nodo -> aluno.strDisciplina);
			for( int i = 0; i < 3; i++)
			{
				printf("\nAVAL.%d: %2.f", i+1, nodo -> aluno.ntAlunos.nVetorNotas[i]);
				fMedia += nodo -> aluno.ntAlunos.nVetorNotas[i];
			}
			fMedia = fMedia/3;
			printf("\nMÉDIA: %2.f", fMedia);
			printf("\nCONCEITO: %c", procuraConceito( fMedia ));
				
		}
		
		fMedia = 0;	
		nodo = nodo -> ptr;
		i++;
		
	} while ( nodo != head );
	printf("\n");
	
	printf("DEFINIÇÃO SOBRE CONCEITO (DIGITE A LETRA PERTINENTE em MAIUSCULO): ");
	fflush(stdin);
	gets( cConceito );
	
	int bExisteConceito = 0;
	for(int i = 0; i < 5; i++)
	{	
		if(strcmp( cConceito, matriz[i][0]) == 0)
		{
			printf("\nCONCEITO %s: %s", matriz[i][0], matriz[i][1]);
			bExisteConceito = 1;	
		}
	}
	
	printf("\nAbaixo de 6, reprovado por nota");
	printf("\nNão há o conceito E, sendo o conceito F reprovação por falta.");

	
	if(bExisteConceito == 0 )
		printf("\nConceito não existe");
	
	printf("\n");
}
