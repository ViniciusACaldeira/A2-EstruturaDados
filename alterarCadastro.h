int buscarAluno( char *strNome )
{
	int bExiste = 0;
	
	struct fila *nodo, *head;
	
	if (!Fila) {
		fprintf (stderr, "Fila está vazia\n");
		return bExiste;
	}
	
	head = nodo = Fila -> ptr;
	
	int i = 1;
	
	do
	{	
		if ( (strcmp(strNome, nodo -> aluno.strNome) ) == 0 or nodo -> aluno.nRA == atoi( strNome ) )
		{
			bExiste = 1;
			break;
		}
		
		nodo = nodo -> ptr;
		i++;
		
	} while ( nodo != head );
	
	return bExiste;

}

int pegaRA( char *strNome )
{
	int nRA = 0;
	
	struct fila *nodo, *head;
	
	if (!Fila) {
		fprintf (stderr, "Fila está vazia\n");
		return nRA;
	}
	
	head = nodo = Fila -> ptr;
	
	do
	{	
		if ( ((strcmp(strNome, nodo -> aluno.strNome) ) == 0) or nodo -> aluno.nRA == atoi( strNome ) )
			nRA = nodo -> aluno.nRA;
		
		nodo = nodo -> ptr;
		
	} while ( nodo != head );
	
	return nRA;
}

void lancaNota( int nRA )
{
	
	struct fila *nodo, *head;
	
	if (!Fila) {
		fprintf (stderr, "Fila está vazia\n");
		return;
	}
	
	head = nodo = Fila -> ptr;
	
	int i = 1;
	
	do
	{	
		if ( nodo -> aluno.nRA == nRA )
		{
			for(int i = 0; i < 3; i++)
			{
				printf("\nDigite a nota da %d° avaliação: ", i+1);
				scanf("%f", &nodo -> aluno.ntAlunos.nVetorNotas[i] ); 
			}
			break;
		}
		
		nodo = nodo -> ptr;
		i++;
		
	} while ( nodo != head );

}

void alteraNota( int nRA )
{
	
	int op = 0;
	struct fila *nodo, *head;
	
	if (!Fila) {
		fprintf (stderr, "Fila está vazia\n");
		return;
	}
	
	head = nodo = Fila -> ptr;
	
	int i = 1;
	do
	{	
		if ( nodo -> aluno.nRA == nRA )
		{
			printf("\nALTERAR NOTA");
			printf("\n[1] Primeira Avaliação: %f", nodo -> aluno.ntAlunos.nVetorNotas[0]);
			printf("\n[2] Segunda Avaliação: %f", nodo -> aluno.ntAlunos.nVetorNotas[1]);
			printf("\n[3] Avaliação Final: %f", nodo -> aluno.ntAlunos.nVetorNotas[2]);
			printf("\n ");
			scanf("%d", &op);
			
			printf("Insira a nova nota: ");
			scanf("%f", &nodo -> aluno.ntAlunos.nVetorNotas[op-1]);
		}
		
		nodo = nodo -> ptr;
		i++;
		
	} while ( nodo != head );

}

void alterarAluno( int nTipo )
{
	fila filaAluno;
	
	char strNomeAluno[30];
	int op = 99;
	int ra = 0;
	int bExiste = 0;
	
	printf("\nMENU NOTA ALUNO ");
	printf("\nDigite o RA ou Nome do aluno: ");
	fflush( stdin );
	gets( strNomeAluno );
	
	bExiste = buscarAluno( strNomeAluno );
	
	if( bExiste == 1 )
	{
		ra = pegaRA( strNomeAluno );
		
		if( nTipo == 2 )
			lancaNota( ra );
		else
			alteraNota( ra );
			
	}
	else
		printf("Aluno não encontrado.\n");	

}
