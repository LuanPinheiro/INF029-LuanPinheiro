//****************** Menu das disciplinas, redireciona para todas as funções de cadastro e relatório de disciplinas
int menu_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof);
int cadastro_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof);
int insert_Disciplina(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof);
void ProfessorDisc(disciplinas, professores, qtd_disciplina, qtd_prof);
int exclude_Disciplina(ficha_disciplina disciplinas[], int qtd);
void listar_disciplinas(ficha_disciplina disciplinas[], int qtd);