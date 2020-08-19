#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int NUMBUCKS = 8;

struct node{
    char* string; struct node* next;
};

struct bucket{
    int minInitial;
    int maxInitial;
    int numWords;
    struct node* chainHead;
};

struct bucket list[NUMBUCKS] = {
        'a', 'b', 0, NULL,
        'c', 'c', 0, NULL,
        'd', 'f', 0, NULL,
        'g', 'k', 0, NULL,
        'l', 'o', 0, NULL,
        'p', 'r', 0, NULL,
        's', 's', 0, NULL,
        't', 'z', 0, NULL
};

void swap(struct node* node1, struct node* node2)
{
    char* temp = node1->string;
    node1->string = node2->string;
    node2->string = temp;
}

void createNode(struct node* node1, char* str, int index)
{
    char* aWord = (char*)malloc(strlen(str)+1);
    strcpy(aWord, str);

    node1 = (struct node*) malloc(sizeof(node1));
    node1->string = str;
    node1->next = NULL;

    struct node* temp = list[index].chainHead;
    if(list[index].numWords == 0) {
        list[index].chainHead = node1;
    }

    else
    {
        struct node* aux = list[index].chainHead;

        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node1;
    }

    list[index].numWords++;
}

void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->string, ptr1->next->string) > 0)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


int main() {

    char* inputString;
    struct node* newNode = NULL;

    while(1) {

        printf("Insert a word:\n");
        scanf("%s", inputString);

        char* aWord = (char*)malloc(strlen(inputString) + 1);
        strcpy(aWord, inputString);

        if(strcmp(aWord, "EOF") == 0) break;

        switch (aWord[0]) {
            case 'a':
            case 'b':
                createNode(newNode, aWord, 0);
                break;
            case 'c':
                createNode(newNode, aWord, 1);
                break;
            case 'd':
            case 'e':
            case 'f':
                createNode(newNode, aWord, 2);
                break;
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
                createNode(newNode, aWord, 3);
                break;
            case 'l':
            case 'm':
            case 'n':
            case 'o':
                createNode(newNode, aWord, 4);
                break;
            case 'p':
            case 'q':
            case 'r':
                createNode(newNode, aWord, 5);
                break;
            case 's':
                createNode(newNode, aWord, 6);
                break;
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                createNode(newNode, aWord, 7);
                break;
            default:
                break;
    }

}

struct node* n = NULL;

    printf("Sorted words: ");
    for(int i = 0; i < NUMBUCKS; i++) {
        n = list[i].chainHead;
        bubbleSort(n);
        while (n != NULL) {
            printf("%s ", n->string);
            n = n->next;
        }
    }

    return 0;
}