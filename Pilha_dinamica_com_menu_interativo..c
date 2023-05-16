#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node node;

node *top;

void push()
{
    int element;

    printf("\n\nInforme o numero a ser empilhado: ");
    scanf("%d", &element);
    printf("\n");

    node *aux = top;

    top = (node *) malloc(sizeof(node));

    if (top == NULL) /*Esse If serve para verificar se a memória foi alocada corretamente evitando possíveis erros.*/
    {
        printf("Falha ao alocar memória.\n"); 
        return;
    }

    top->number = element;
    top->next = aux;
}

void pop()
{
    if (top == NULL) /*Esse If serve para evitar que erros ocorram se o usuário tentar desempilhar uma pilha vazia.*/
    {
        printf("\nA pilha esta vazia. Impossivel desempilhar.\n"); 
        return;
    }

    node *aux = top;
    top = top->next;

    free(aux);
}

void display()
{

    node *aux = top;

     if (aux == NULL)
    {
        printf("\n|-----------------------------------|");
        printf("\n|---------> Pilha Vazia! <----------|\n");
        printf("|-----------------------------------|\n\n");
    }
    else
    {
        while (aux != NULL)
        {
            {
                printf("|   %d   |\n", aux->number);
                aux = aux->next;
            }   
        }
            
    }
}

void clear() /*Função para limpar a pilha inteira de uma única vez.*/
{
    while (top != NULL)
    {
        pop();
    }
}

void menu()
{
    printf("\n--- MENU ---\n\n");
    printf("1 - Empilhar um numero\n");
    printf("2 - Desempilhar um número\n");
    printf("3 - Exibir pilha\n");
    printf("4 - Limpar a pilha\n");
    printf("5 - Sair do programa\n");
}

void hubFunction(int option)
{
    do
    {

    menu();
    printf("\n--> ");
    scanf(" %d", &option);
    printf("\n");
    
    switch (option)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        clear();
        break;
    case 5:
        printf("\nSaindo do Programa...\n");
        break;
    default:
        printf("\nOpcao invalida\n\n");
        break;
    }
    }while(option != 5);
}

int main(int argc, char const *argv[])
{
    top = NULL;

    int option = 0;
    
    hubFunction(option);

    clear(); /*A função clear está aqui para limpar toda a pilha antes de sair do programa.*/

    return 0;
}