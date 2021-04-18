# Stack e Queue

Universidade Federal do Rio Grande do Norte

Instituto Metrópole Digital

DIM0119 - ESTRUTURA DE DADOS BÁSICAS I - T02 (2020.2)

Docente: Guilherme Fernandes de Araujo

Alunos: Frank Laércio da Costa Santos Júnior e Ohanna de Macena Dezidério

## Resumo

Este trabalho irá comparar dois algoritmos de estruturas de dados a Pilha (*stack*) e Fila (*queue*). Na pilha iremos executar duas operações de empilhar (no último índice do nó) e desempilhar (no último índice do nó) e na fila serão feitas as operações de enfileirar (no último índice do nó) e desenfileirar (no primeiro índice do nó). Vale ressaltar que todas essas operações possuem complexidade de O (1) e que os gráficos foram gerados no Google Sheets com os dados obtidos pelo CSV gerado.

## Stack

A pilha surge da ideia de irmos adicionando objetos um atrás do outro. A definição de um pilha é dada pelo seu *capacity* (quantidade de elementos que essa pilha pode possuir), *top* (último elemento) e *array* (que é um ponteiro de todos os elementos).

```cpp
class Stack {
  private:
    int *arr;
    int top;
    int capacity;
  public:
    Stack(int size);
    ~Stack();

    void push(int number);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();  
};
```

No exemplo acima, é possível perceber que existem algumas operações principais:

- **Stack(int size)**: construtor padrão de uma pilha, é aqui que definimos o seu tamanho, instanciamos e definimos o elemento ao topo como -1.

    ```cpp
    array = new int[size];
    capacity = size;
    top = -1;
    ```

- **~Stack()**: construtor padrão que apaga a pilha.

    ```cpp
    delete[] array;
    ```

- **push()**: função responsável por adicionar um novo número a pilha.

    ```cpp
    if(isFull()) {
      cout << "Stack overflow" << endl;
      exit(EXIT_FAILURE);
    }

    array[++top] = number;
    ```

- **pop()**: função responsável por remover um elemento da pilha.

    ```cpp
    if(isEmpty()) {
      cout << "Stack underflow" << endl;
      exit(EXIT_FAILURE);
    }

    return array[top--];
    ```

- **peek()**: função responsável por exibir o último elemento da pilha.

    ```cpp
    if (!isEmpty()) {
       return array[top];
    } else {
       exit(EXIT_FAILURE);
    }
    ```

- **size()**: retorna o tamanho da pilha.

    ```cpp
    return top + 1;
    ```

- **isEmpty()**: verifica se a pilha está vazia().

    ```cpp
    return top == -1;
    ```

- **isFull():** verifica se a pilha está cheia().

    ```cpp
    return top == capacity - 1;
    ```

## Queue

A ideia da fila é que um elemento seja adicionado no "fundo" dela e que o elemento que saia dela é o primeiro que entrou, comportamento parecido com uma fila indiana. Uma fila é definida por:

- front: primeiro elemento da fila.
- back: último elemento da fila.
- size: tamanho da fila.
- capacity: capacidade dessa fila.
- array: ponteiro para armazenar todos os elementos da fila.

```cpp
class Queue {
  private:
    int front;
    int back;
    int size;
    int *array;
    int capacity;
  public:
    Queue(int capacity);
    ~Queue();

    bool isFull();
    bool isEmpty();

    void enqueue(int item);
    void dequeue();
};
```

No exemplo acima, é possível perceber que existem algumas operações principais:

- Queue: construtor padrão de uma fila, aqui são definidos os parâmetros iniciais.

    ```cpp
    this->capacity = capacity;
    this->front = size = 0;
    this->back = capacity - 1;
    this->array = new int[capacity];
    ```

- ~Queue: destrutor padrão de uma fila, aqui todos os elementos são apagados.

    ```cpp
    delete[] array;
    ```

- isFull(): verifica se o tamanho da fila já atingiu a capacidade dela.

    ```cpp
    return this->size == this->capacity;
    ```

- isEmpty(): verifica se a fila está vazia, ou seja, se o tamanho dela é igual a 0.

    ```cpp
    return this->size == 0;
    ```

- Enqueue(): função responsável  por adicionar um novo elemento a fila.

    ```cpp
    if (isFull()) {
      return;
    }

    this->back = (back + 1) % capacity;
    this->array[back] = item; 
    this->size = size + 1;
    ```

- Dequeue(): função responsável  por remover um elemento da fila.

    ```cpp
    if(isEmpty()) {
      return;
    }

    this->front = (front + 1) % capacity;
    this->size -= 1;
    ```

## Gráficos de execução da Stack e Queue

Para comparar os dois algoritmos foram utilizadas as instâncias de quantidade de operações de 450, 900, 1800, 3600, 7200, 14400, 28800, 57600, 115200 e 230400. Além disso, dividiu-se em dois casos de testes, um sendo a comparação entre a inserção e o outro sendo a remoção. 

![Stack%20e%20Queue%207f477175a61141fdbb7becea3561ab29/Insero_na_Stack_e_Queue.png](Stack%20e%20Queue%207f477175a61141fdbb7becea3561ab29/Insero_na_Stack_e_Queue.png)

Imagem 1: gráfico comparativo da inserção na Stack e Queue.

![Stack%20e%20Queue%207f477175a61141fdbb7becea3561ab29/Remoo_na_Stack_e_Queue.png](Stack%20e%20Queue%207f477175a61141fdbb7becea3561ab29/Remoo_na_Stack_e_Queue.png)

Imagem 2: gráfico comparativo de remover na Stack e Queue.
