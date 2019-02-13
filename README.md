# Validação de Agrupamento

Trabalho prático de Estrutura de Dados I, com o objetivo principal de fundamentar os conceitos de listas encadeadas, filas e pilhas promovendo a utilização correta dos espaços de memória.

## Definição do Problema

Implementação de um programa que, dada uma serie de operações matemáticas, determine se elas possuem ou não erro de agrupamento. 

O programa irá validar se a operação está escrita com símbolos de agrupamento de forma correta, tais como ( ), [ ], ou { } para indicar a ordem em que as operações aritméticas são executadas. 

### Exemplo

Operação válida: 
```
[a(x+y)+c]d+(b(c+d))
```

Operações inválidas: 
```
[a+b)
```
```
(a
```
```
(b))
```
```
([a+b)c]
```

Isto é, cada sinal que "abre" deve ter um sinal correspondente que o "fecha", e também os signos não podem se sobrepor.


### Entrada

Cada operação deve estar separada pelo símbolos: `< **operação** >`, e a entrada deve ser colocada no arquivo `test/entrada.txt`


## Instalação e Execução


### Linux

```
make all
```

```
make run
```

### Windows

```
g++ -o tp2ex2 src/main.cpp src/TFila.h src/TFila.cpp
```

```
tp2ex2
```