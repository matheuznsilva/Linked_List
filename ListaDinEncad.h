
//#define MAX 100 // define tamanho maximo da lista

// dado do tipo aluno
struct aluno{		// struct onde é guardada as informações de cada nó da lista
	int matricula;		// variável onde é guardado o numero de matricula do aluno
	char nome[100];		// variável onde é guardado o nome do aluno
	float n1, n2, n3, media;		// variáveis onde são guardadas as notas do aluno
};

typedef struct elemento* Lista; // padronização do nome do ponteiro tipo lista

Lista* criar_lista();	// criação da lista
void libera_lista(Lista* li);		// função de destruição da lista
int busca_lista_pos(Lista* li, int pos, struct aluno *al);		// função de busca do elemento pela posição
int busca_lista_mat(Lista* li, int mat, struct aluno *al);		// função de busca do elemento pela matricula
int insere_lista_final(Lista* li, struct aluno al);		// função de inserção ao final da lista
int insere_lista_inicio(Lista* li, struct aluno al);		// função de inserção no inicio da lista
int insere_lista_ordenada(Lista* li, struct aluno al);		// função de inserção de forma ordenada
int remove_lista(Lista* li, int mat);		// função de remoção de um elemento especifico
int remove_lista_inicio(Lista* li);		// função de remoção de um elemento no inicio da lista
int remove_lista_final(Lista* li);		// função de remoção de um elemento ao final da lista
int tamanho_lista(Lista* li);		// função que retorna o tamanho da lista
int lista_cheia(Lista *li);		// função que retorna se a lista esta cheia
int lista_vazia(Lista* li);		// função que retorna se a lista esta vazia
void imprime_lista(Lista* li);		// função que imprime a lista
