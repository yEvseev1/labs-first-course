#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} node;

typedef struct LinkedList{
    node* head;
} List;

node* CreateNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> value = data;
    newnode -> next = NULL;
    return newnode;
}

void InitList(List* list){
    list -> head = CreateNode(0);
}

void AddNode(List* list,int data){
    node* newnode = CreateNode(data);
    node* tmp = list->head;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = newnode;
}

void PrintList(List* list){
    node* tmp = list -> head;
    while(tmp != NULL){
        printf("%d ",tmp -> value);
        tmp = tmp -> next;
    }
}

void DeleteKElem(List* list, int k){
    node* current = list -> head -> next;
    node* prev = NULL;
    int count = 1;
    while (current != NULL) {
        if (count % k == 0) {
            node* tmp = current;
            current = current->next;
            if (prev == NULL) {
                list->head -> next = current;
            } else {
                prev->next = current;
            }
            free(tmp);
        } else {
            prev = current;
            current = current->next;
        }
        count++;
    }
}

int main() {
    List* Mylist;
    InitList(Mylist);
    int value, var;
    int flag = 1;
    while(flag){
        printf("1.Enter element for list. 2.End of list.\n");
        scanf("%d",&var);
        if(var == 1){
            printf("Enter value: ");
            scanf("%d",&value);
            AddNode(Mylist, value);
        }
        if(var == 2){
            flag = 0;
        }
    }
    PrintList(Mylist);
    printf("\n");
    printf("0 - barrier element.\n");
    int k;
    printf("Enter k for delete k-th element.\n");
    scanf("%d",&k);
    DeleteKElem(Mylist, k);
    printf("List after operation.\n");
    PrintList(Mylist);
    printf("\n");
    printf("0 - barrier element.\n");
    return 0;
}