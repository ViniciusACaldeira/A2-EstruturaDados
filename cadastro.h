
void adicionar( Aluno aluno )
{
	struct fila *nodo;
	
	if ( (nodo = (struct fila *) malloc (sizeof (struct fila*))) == NULL )
	{
		perror ("malloc");
		exit (1);
	}
			
	nodo -> aluno = aluno;
	
	if (Fila == NULL) {
		nodo -> ptr = nodo;
	}
	else
	{
		nodo -> ptr = Fila -> ptr;
		Fila -> ptr = nodo;
	}
	
	Fila = nodo;	
}

void telaSucesso( Aluno aluno )
{
	printf("\n Aluno %s Cadastrado com Sucesso.", aluno.strNome );
	printf("\n\n DADOS CADASTRADOS: ");
	printf("\n Nome: %s", aluno.strNome);
	printf("\n Ra: %d", aluno.nRA);
	printf("\n Disciplina: %s", aluno.strDisciplina );

}

void cadastrarAluno( )
{
	Aluno aluno;
	int op = 99;
	int nDisciplina = 0;
	int bExisteDisciplina = 0;
	char strDisciplina[30];
	
	for(int i = 0; i < 10; i++)
	{
		bExisteDisciplina = aluno.nDisciplina = m_Disciplina[i].codDisciplina;
		if(bExisteDisciplina != 0)
			break;
	}
	
	
	if( bExisteDisciplina == 0 )
	{
		printf("\nNão existe matéria cadastrada");
		return;	
	}
	
	printf("\nDigite o Nome do Aluno: ");
	fflush(stdin);
	gets(aluno.strNome);
	
	printf("Digite o RA do %s: ", aluno.strNome);
	scanf("%d", &aluno.nRA );
	
	while( op != 0 )
	{
		
		printf("Digite o código ou nome da matéria: ");
		fflush( stdin );
		gets( strDisciplina );
		
		for(int i = 0; i < 10; i++)
		{
			if( ((strcmp(strDisciplina, m_Disciplina[i].strNomeDisciplina) ) == 0 ) or atoi(strDisciplina) == m_Disciplina[i].codDisciplina )
			{
				aluno.nDisciplina = m_Disciplina[i].codDisciplina;
				strcpy (aluno.strDisciplina, m_Disciplina[i].strNomeDisciplina);
				i = 11;
				if( aluno.nDisciplina == 0 )
					op = 1;
				else
				op = 0;
				
			}
		}
		
		if( op != 0 )
			printf("Matéria não encontrada\n");
			
	}
	
	telaSucesso( aluno );
	
	printf("\n");
	
	adicionar( aluno );
}

void cadastrarDisciplina( )
{
	Disciplina disciplina;
	
	if( m_nDisciplina == 9 )
	{
		printf("Todas as Disciplinas da Escola foram preenchidas!!");
		return;
	}
	
	printf("Digite o Nome da Matéria: ");
	fflush(stdin);
	gets( m_Disciplina[m_nDisciplina].strNomeDisciplina);
	
	printf("Digite o código da Matéria (%s): ", m_Disciplina[m_nDisciplina].strNomeDisciplina ); 
	scanf("%d", &m_Disciplina[m_nDisciplina].codDisciplina);
	
	m_nDisciplina++;
}
