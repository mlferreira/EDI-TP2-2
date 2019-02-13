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

#include <iostream>
#include "TFila.h"
using namespace std;


TFila* TFila_Inicia(){
	TFila * pFila = new TFila;
	(*pFila).ultimo = NULL;
	(*pFila).primeiro = (*pFila).ultimo;
	(*pFila).tamanho = 0;
	return pFila;	
}

bool TFila_EhVazia(TFila* pFila){
	if(pFila->tamanho == 0){
		return true;
	}else{
		return false;
	}	
}

void Enfileira(TFila* pFila, TItem x){
	TCelula * temp = new TCelula;
	(*temp).item = x;
	temp->prox = NULL;
	if(TFila_EhVazia(pFila)){
		pFila->primeiro = temp;
	}else{
		(*pFila).ultimo->prox = temp;
	}
	pFila->ultimo = temp;
	pFila->tamanho++;	
}

int Desenfileira(TFila* pFila, TItem *pX){
	if(TFila_EhVazia(pFila)){
		return 1;
	}else{
		TItem temp;
		temp = pFila->primeiro->item;
		*pX = temp;
		pFila->primeiro = pFila->primeiro->prox;
		pFila->tamanho--;
		if(TFila_EhVazia(pFila)){
			(*pFila).ultimo = NULL;
			(*pFila).primeiro = (*pFila).ultimo;
		}
		return 0;
	}	
}

