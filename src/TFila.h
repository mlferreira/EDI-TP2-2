/**********************************************************************/
/*                                                                    */
/*                        Estrutura de Dados I                        */
/*                         Trabalho Pratico 2                         */
/*                                                                    */
/*                             Exercicio 2                            */
/*                                                                    */
/*                        Melina Lopes Ferreira                       */
/*                              15.2.4002                             */
/*                                                                    */
/**********************************************************************/

#ifndef TFila_h
#define TFila_h

#include <iostream>
using namespace std;

typedef struct{
	string operacao;
	int tamanho;
}TItem;

typedef struct celula{
	TItem item;
	struct celula * prox;
}TCelula;

typedef struct{
	TCelula *primeiro;
	TCelula *ultimo;
	int tamanho;
}TFila;


TFila* TFila_Inicia();

bool TFila_EhVazia(TFila* pFila);

void Enfileira(TFila* pFila, TItem x);

int Desenfileira(TFila* pFila, TItem *pX);


#endif /* TFila_h */
