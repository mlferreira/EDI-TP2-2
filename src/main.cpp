/**********************************************************************/
/*                                                                    */
/*                        Estrutura de Dados I                        */
/*                         Trabalho Pratico 2                         */
/*                                                                    */
/*                             Exercicio 2                            */
/*                               2016.1                               */
/*                                                                    */
/*                        Melina Lopes Ferreira                       */
/*                              15.2.4002                             */
/*                                                                    */
/**********************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include "TFila.h"
using namespace std;

int main(){

	char aux;
	string ultimoAberto;
	int cPar, cCol, cChav, n=1;
	bool agrupamento;

	TFila* fila = TFila_Inicia();
	TItem processo;


	fstream entrada;

	entrada.open ("test/entrada.txt", ios::in);  

	while(!(entrada.eof())){

		cPar = 0;
		cCol = 0;
		cChav = 0;
		processo.tamanho = 0;

		do{
			entrada >> aux;
			processo.operacao += aux;
			processo.tamanho++;
		}while(aux != '>');

		Enfileira(fila, processo);

		(processo.operacao).clear();
		processo.tamanho = 0;

	}

	entrada.close();



	while(fila->tamanho > 1){

		Desenfileira(fila, &processo);

		cout << processo.operacao << endl;

		cPar = 0;
		cCol = 0;
		cChav = 0;
		int k = 0;

		for(int i=0; i<=processo.tamanho; i++){
			
			if(processo.operacao[i] == '('){
				cPar++;
				ultimoAberto += '(';
				k++;
			}
			else if(processo.operacao[i] == ')'){
				k--;
				cPar--;
				if(ultimoAberto[k] != '('){
					agrupamento = false;
					break;
				}
				ultimoAberto.erase(k);
			}
			else if(processo.operacao[i] == '['){
				cCol++;
				ultimoAberto += '[';
				k++;
			}
			else if(processo.operacao[i] == ']'){
				k--;
				cCol--;
				if(ultimoAberto[k] != '['){
					agrupamento = false;
					break;
				}
				ultimoAberto.erase(k);
			}
			else if(processo.operacao[i] == '{'){
				cChav++;
				ultimoAberto += '{';
				k++;
			}
			else if(processo.operacao[i] == '}'){
				k--;
				cChav--;
				if(ultimoAberto[k] != '{'){
					agrupamento = false;
					break;
				}
				ultimoAberto.erase(k);
			}

		}

		if((cPar != 0) || (cCol != 0) || (cCol != 0)){
			agrupamento = false;
		}else{
			agrupamento = true;
		}

		cout << "P" << n++ << ": ";
		if(agrupamento){
			cout << "aceito" << endl;
		}else{
			cout << "rejeitado, erro de agrupamento" << endl;
		}

		ultimoAberto.clear();
		
	}

	return 0;
}