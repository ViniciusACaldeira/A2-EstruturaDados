# A2-EstruturaDados
Sistema de Gerenciamento de Escola para atividade 2 de Estrutura de Dados

#COMPONENTE DA EQUIPE:
  Vinicius Araujo Caldeira.
  RA: 3481716
  
#FUNÇÕES UTILIZADAS:

Para ficar mais didático, separados de acordo com o Menu Principal:
[1] cadastrarAluno( )
    - telaSucesso( )
    - adicionar( )
  
[2] e [3] alterarAluno( )
             - buscarAluno( )
             - pegaRA( )
             - lancaNota( )
             - alteraNota( )
  
[4] relatorioAluno( )
      - montaMatriz( )
      - procuraConceito( )
  
 [5] cadastrarDisciplina( )

#ESTRUTURAS UTILIZADAS:
Foi utilizado nesse trabalho as seguintes estruturas: Vetor, Matriz e Fila.


#Explicação de funcionalidades.

MENU SISTEMA GERENCIAMENTO ESCOLAR
 [1] Cadastrar Novo Aluno.
  Somente rodará o sistema de cadastro caso haja anteriormente cadastrado a Disciplina pelo processo [5].
  [1.1] Nome do Aluno.
  [1.2] RA do aluno.
  [1.3] Disciplina, o sistema tem a inteligencia de indentificar qual o selecionado pelo usuário (Código ou nome) e atribuir os valores cadastrados. 
 [2] Lançar nota aluno.
  Deverá ser informado o RA ou NOME do aluno, o sistema já possui inteligencia para interpretar, porém deve ser precisamente igual o nome ou RA.
  [2.1] Lança a nota para todas as avaliações sem mostrar as mesmas.
 [3] Alterar nota aluno.
  Deverá ser informado o RA ou NOME do aluno, o sistema já possui inteligencia para interpretar, porém deve ser precisamente igual o nome ou RA.
  [3] Exibe os valores das notas já cadastradas, se não houver cadastrado será 0.
  [3.1] Altera a nota da Primeira Avaliação. 
  [3.2] Altera a nota da Segunda Avaliação.
  [3.3] Altera a nota da Avaliação Final.
 [4] Relatorio Aluno. 
  Existem 2 opções a serem escolhidos, a Primeira gera como um relatório mais ordenado, já o segundo como descrito na atividade. (Recomendo a primeira para melhor visualização).
  [4.1] Exemplo:
            ALUNO Vinicius
    CÓDIGO (RA) :1
    NOME: Vinicius
    DISCIPLINA:
    AVAL.1: 0,000000
    AVAL.2: 0,000000
    AVAL.3: 0,000000
    MÉDIA: 0,000000
    CONCEITO: F
  [4.2] Exemplo:
    CÓDIGO (RA) ! NOME ! DISCIPLINA ! AVAL.1 ! AVAL.2 ! AVAL.3 ! MÉDIA ! CONCEITO
    3481716 Vinicius        Matematica      0,000000        0,000000        0,000000        0,000000        F

    64856   Felipe  Geografia       0,000000        0,000000        0,000000        0,000000        F
    OBS: Meu teclado não possui barra reta (pippe) nem barra invertida o que dificultou um pouco.
 [5] Cadastrar Disciplina.
    [5.1] Nome da Disciplina.
    [5.2] Código da Disciplina.
    [5.3] Descobrir o significado sobre o CONCEITO, deve ser inserido a letra pertinente ao CONCEITO a ser analisado.
    
    
#Explicação do código:
Cada estrutura é dividido por um .h no sistema há dois (estruturaDisciplina e estruturaAluno) para facilitar na alteração do código, assim como cada funcionalidade.
Para cadastro existe o header para cadastro, onde se encontra tanto o cadastro o aluno quanto da disciplina (VETOR).
Para as notas existe o header para alteração, nele encontra-se a lógica de alteração das notas, tanto de lançamento quanto o de alteração.
Para relatório existe o header para relatório, nele está a lógica utilizada para ler e exibir a FILA e A MATRIZ com os conceitos e seus respectivas significados.
