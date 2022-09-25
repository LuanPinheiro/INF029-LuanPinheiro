int menu_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof);
int cadastro_Disciplinas(ficha_disciplina disciplinas[], ficha_pessoa alunos[], ficha_pessoa professores[], int qtd_disciplina, int qtd_alunos, int qtd_prof);
int insert_Disciplina(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof);
void ProfessorDisc(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof);
int exclude_Disciplina(ficha_disciplina disciplinas[], int qtd);
void update_Disciplina(ficha_disciplina disciplinas[], ficha_pessoa professores[], int qtd_disciplina, int qtd_prof);
void insert_AlunoDisc(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int qtd_disciplina, int qtd_aluno);
void exclude_AlunoDisc(ficha_disciplina disciplinas[], ficha_pessoa alunos[], int qtd_disciplina, int qtd_alunos);
int codigoRepetido(ficha_disciplina disciplinas[], int index);