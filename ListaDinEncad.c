#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os prototipos 

//Definição do tipo lista

struct elemento{
	struct aluno dados;		// campo do tipo aluno que recebe o dado a ser armazenado
	struct elemento *prox;		// ponteiro do tipo elemento que indica o proximo elemento 
};

typedef struct elemento Elem;		// definição de um nome padrão para a struct elemento
// ==========================================================

// FUNÇÃO DE CRIAÇÃO DA LISTA

Lista* criar_lista(){
	Lista *li = (Lista*) malloc(sizeof(Lista));		// alocação de memoria para a Lista
	
	if(li != NULL){		// confere se a lista foi criada
		*li = NULL;	// caso criada faz o ponteiro apontar para null
		printf("\nLISTA CRIADA\n"); // confirmação q a lista foi criada
	}
	return li;		// retorna o ponteiro li;
}
// ==========================================================

// FUNÇÃO QUE DESTROI A LISTA

void libera_lista(Lista* li){
	if(li!= NULL){		// verifica se a lista existe
		Elem* no;		// declaração de um ponteiro auxiliar
		while((*li)!=NULL){		// loop para percorrer a lista com condição de para ser o final da lista
			no = *li;		// ponteiro auxiliar recebe a posição atual do ponteiro li
			*li = (*li)->prox;		// li recebe a posição do proximo elemento 
			free(no);		// apaga o nó(elemento) da lista
		}
		free(li);	// libera o ponteiro	
	}	
}
// ==========================================================

// FUNAÇÃO QUE RETORNA O TAMANHO DA LISTA

int tamanho_lista(Lista* li){	
	if(li == NULL){		// confere se a lista existe
		return 0;		// caso não exista retorna -1 informando o erro
	}
	int cont = 0;		// declaração de variável local(contador) para armazenar a quantidade de elementos presentes na lista
	Elem* no = *li;		// declaração e atribuição do ponteiro auxiliar para percorrer a lista
	while(no != NULL){		// loop para percorrer a lista com condição de para ser o final da lista
		cont++;		// incremento do contador
		no = no->prox;		// ponteiro auxiliar recebe a proxima posição da lista
	}
	return cont;		// retorna o contador
}
// ==========================================================

// FUNÇÃO QUE RETORNA SE A LISTA ESTA CHEIA

int lista_cheia(Lista* li){		// função que retorna se a lista está cheia
	return 0;		// tendo em vista q a lista só estará cheia se nn houver mais memoria, ela sempre retorna 0
}
// ==========================================================

// FUNÇÃO QUE RETORNA SE A LISTA ESTA VAZIA OU NÃO

int lista_vazia(Lista* li){
	if(li == NULL){		// confere se a lista existe
		return 1;		// se a lista não existir retorna 1
	}
	if(*li == NULL){	// confere se a lista está vazia
		return 1;		// caso esteja retorna 1
	}
	return 0;		// caso ja exista algum elemento na lista retorna 0
}
// ==========================================================

// FUNÇÕES DE INSERÇÃO

int insere_lista_inicio(Lista* li, struct aluno al){		//  inserção no inicio da lista
	if(li == NULL){ 	// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* no;		// delcaração de um ponteiro auxiliar
	no = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(no == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}		// caso tenha ocorrido executa os comandos abaixo
	no->dados = al;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	no->prox = (*li);	// o ponteiro prox recebe endereço do elemento ja existente, ou seja, passa a apontar para o agora proximo elemento da lista
	*li = no;		// a posição inicial recebe o agora primeiro elemento
	return 1;
}

int insere_lista_final(Lista* li, struct aluno al){		//  inserção ao final da lista
	if(li == NULL){		// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* no;		// delcaração de um ponteiro auxiliar
	no = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(no == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}
	no->dados = al;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	no->prox = NULL;	// o ponteiro prox do novo elemento passa a apontar para null

	if((*li) == NULL){		// confere se é uma lista vazia
		*li = no;		// caso seja atribuimos o novo elemento ao inicio da lista
	} else {		// caso não seja percorremos a lista até encontrar o ultimo elemento
		Elem *aux;		// declaração de um outro ponteiro auxiliar
		aux = *li;		// ponteiro auxiliar recebe a posição inicial da lista
		while(aux->prox != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
			aux = aux->prox;		// ponteiro auxiliar recebe o endereço do proximo elemento
		}
		aux->prox = no;		// ao final do loop o ponteiro prox que antes apontava pra null passa a apontar para o novo elemento
	}
	return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){		//  inserção ordenada
	if(li == NULL){		// confere se a lista existe
		return 0;		// caso não exista não ocorre a inserção
	}
	Elem* no;		// delcaração de um ponteiro auxiliar
	no = (Elem*) malloc(sizeof(Elem));		// alocação de memoria para um novo elemento
	if(no == NULL){		// confere se ocorreu a alocação
		return 0;		// caso não tenha ocorrido retorna 0
	}
	no->dados = al;		// o campo dados do novo elemento recebe os dados digitados pelo usuário
	if((*li) == NULL){		// confere se é uma lista vazia
		no->prox == NULL;	// caso seja o ponteiro prox do novo elemento passa a apontar para null
		*li = no;		// atribui o novo elemento ao inicio da lista
		return 1;
	} else{		// se não for uma lista vazia, iremos percorre a lista até encontrar um numero de matricula maior que o cadastrado pelo usuário
		Elem *ant, *atual = *li;		// declaração de ponteiros auxiliares e atribuição do ponteiro atual recebendo a primeira posição da lista
		while(atual != NULL && atual->dados.matricula < al.matricula){		// loop para percorrer a lista tendo como ponto de parada o final da lista e a matricula do elemento presente na lista ser maior que a do elemento a ser inserido 
			ant = atual;		// atribui ao ponteiro ant a posição do elemento apontado por atual
			atual = atual->prox;		// atual recebe a posição do proximo elemento da lista
		}
		if(atual == *li){		// confere se a posição apontada por atual foi a primeira posição da lista 
			no->prox = (*li);		// caso seja o ponteiro prox do novo elemento passa a apontar para o antigo primeiro elemento da lista
			*li = no;		// li passa agora a apontar para o novo elemento
		} else{		// caso não seja o ponteiro executa os comando a baixo
			no->prox = atual;		// o ponteiro prox do novo elemento passa a apontar para a posição do atual(elemento que o ponteiro atual aponta)
			ant->prox = no;		// o ponteiro prox do elemento apontado por ant passa a apontar para a posição do novo elemento
		}
		return 1;
	}

}
// ==========================================================

// FUNÇÕES DE REMOÇÃO

int remove_lista_inicio(Lista* li){		//  remoção no inicio da lista
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*li) == NULL){		//confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *no = *li;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	*li = no->prox;		// ponteiro principal recebe o proximo elemento da lista
	free(no);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}

int remove_lista_final(Lista* li){		// remoção no final da lista
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*li) == NULL){		// confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}
	Elem *ant, *no = *li;		// declaração de ponteiros auxiliares e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(no->prox != NULL){		// loop para percorrer a lista tendo como condição de parada o final da lista
		ant = no;		// atribui ao ponteiro ant a posição do elemento apontado por no
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
	}

	if(no == (*li)){		// confere se o nó é igual ao inicio da lista
		*li = no->prox;		// se for o ponteiro li passa a apontar para o proximo elemento
	} else{
		ant->prox = no->prox;		// se não for o ponteiro prox do anterior passa a apontar para o proximo elemento
	}
	free(no);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}

int remove_lista(Lista* li, int mat){		// remoção de acordo com a matricula
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
		return 0;
	}
	if((*li) == NULL){		//confere se existe elementos na lista
		printf("\nLISTA NÃO POSSUI ELEMENTOS CADASTRADOS\n");		// caso não exista elementos informa que a operação não pode ser processada
		return 0;
	}

	Elem *ant, *no = *li;		// declaração de ponteiros auxiliares e atribuição do ponteiro no apontando para o primeiro elemento da lista
	while(no != NULL && no->dados.matricula != mat){		// loop para percorrer a lista tendo como ponte de parada o fim da lista ou ter encontrado a matricula procurada 
		ant = no;		// atribui ao ponteiro ant a posição do elemento apontado por no
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
	}
	if(no == NULL){		// caso o numero da matricula não seja encontrado 
		printf("\nA MATRICULA PROCURADA NÃO CONSTA NO CADASTRO\n");
		return 0;
	}
	if(no == *li){		// confere se o nó é igual ao inicio da lista
		*li = no->prox;		// se for o ponteiro li passa a apontar para o proximo elemento
	} else{
		ant->prox = no->prox;		// se não for o ponteiro prox do anterior passa a apontar para o proximo elemento
	}
	free(no);		// apaga o elemento (libera a memoria utilizada pelo elemento a ser apagado)
	return 1;
}
// ==========================================================

// FUNÇÕES DE BUSCA

int busca_lista_pos(Lista* li, int pos, struct aluno *al){		// busca de acordo com a posição
	if(li == NULL || pos <= 0){		// confere se a lista existe ou se a posição procurada é menor ou igual a 0
		return 0;
	}
	Elem *no = *li;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista
	int i = 1;		// declaração e inicialização de variável local que servirá como contador
	while(no != NULL && i<pos){		// loop para percorrer a lista tendo como condição de parada o fim da lista ou o contador ser maior que a posição procurada
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
		i++;		// incremento do contador
	}
	if(no == NULL){		// caso a posição desejada não seja encontrada
		printf("\nELEMENTO NÃO ENCONTRADO\n");	
		return 0;
	} else{		// caso seja encontrada
		*al = no->dados; 		// retorna o ponteiro para struct aluno onde serão guardadas as informações
		return 1;
	}
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al){		// busca de acordo com a matricula
	if(li == NULL){		// confere se a lista existe
		return 0;
	}
	Elem *no = *li;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista

	while(no != NULL && no->dados.matricula != mat){		// loop para percorrer a lista tendo como condição de parada o fim da lista ou ter encontrado a matricula procurada
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista		
	}

	if(no == NULL){		// caso a matricula desejada não seja encontrada
		printf("\nELEMENTO NÃO ENCONTRADO\n");		// caso não encontre o elemento informa que o mesmo não existe
		return 0;
	} else{
		*al = no->dados; 		// retorna o ponteiro para struct aluno onde serão guardadas as informações
	}
	return 1;
}
// ==========================================================

// FUNÇÃO DE IMPRESSÃO DA LISTA

void imprime_lista(Lista* li){
	if(li == NULL){		// confere se a lista existe
		printf("\nLISTA NÃO EXISTENTE\n");		// caso não exista informa que a operação não pode ser processada
	}
	Elem *no = *li;		// declaração e atribuição do ponteiro no apontando para o primeiro elemento da lista

	while(no != NULL){		// loop para deslocamento na lista 
		printf("\nAluno: %s", no->dados.nome);		// imprime o nome do aluno
		printf("Matricula: %d", no->dados.matricula);		// imprime a matricula do aluno
		printf("\nNota 1: %.1f", no->dados.n1);		// imprime a 1ª nota do aluno
		printf("\nNota 2: %.1f", no->dados.n2);		// imprime a 2ª nota do aluno
		printf("\nNota 3: %.1f", no->dados.n3);		// imprime a 3ª nota do aluno
		printf("\nMedia final: %.1f", no->dados.media);		// imprime a media entre as três notas do aluno
		printf("\n");		// quebra de linha
		no = no->prox;		// ponteiro no recebe a posição do proximo elemento da lista
	}

}


