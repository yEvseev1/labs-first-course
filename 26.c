#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} node;

typedef struct Deque {
    int size;
    node* head;
    node* tail;
} deque;

deque* CreateDeq() {
    deque* deq = (deque*)malloc(sizeof(deque));
    deq -> size = 0;
    deq -> head = deq -> tail = NULL;
    return deq;
}

int DeqSize(deque* deq){
    return deq -> size;
}

int DeqIsEmpty(deque* deq){
    if(deq->size == 0)
        return 1;
    else{
        return 0;
    }
}

void PushFront(deque* deq, int val){
    node* tmp = (node*)malloc(sizeof(node));
    tmp -> value = val;
    tmp -> next = deq -> head;
    tmp -> prev = NULL;
    if (deq -> head != NULL) {
        deq -> head -> prev = tmp;
    }
    deq -> head = tmp;
    if (deq -> tail == NULL) {
        deq -> tail = tmp; 
    }
    ++deq -> size;
}

int PopFront(deque* deq) {
    node* prev;
    int tmp;
    prev = deq -> head;
    deq -> head = deq -> head -> next;
    if (deq -> head) {
        deq -> head -> prev = NULL;
    }
    if (prev == deq -> tail) {
        deq -> tail = NULL;
    }
    tmp = prev -> value;
    free(prev);
    --deq -> size;
    return tmp;
}

void PushBack(deque* deq, int val) {
    node* tmp = (node*) malloc(sizeof(node));
    tmp -> value = val;
    tmp -> next = NULL;
    tmp -> prev = deq -> tail;
    if (deq -> tail) {
        deq -> tail -> next = tmp;
    }
    deq -> tail = tmp;

    if (deq -> head == NULL) {
        deq -> head = tmp;
    }
    ++deq -> size;
}

int PopBack(deque* deq) {
    node* next;
    int tmp;
    next = deq -> tail;
    deq -> tail = deq -> tail -> prev;
    if (deq -> tail) {
        deq -> tail -> next = NULL;
    }
    if (next == deq -> head) {
        deq -> head = NULL;
    }
    tmp = next -> value;
    free(next);
    --deq -> size;
    return tmp;
}

void PrintDeque(deque* deq) {
    node* tmp = deq -> head;
    while (tmp != NULL) {
        printf("%d ", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\n");
}

int main() {
    int n, val;
    deque* deq = CreateDeq();
    printf("Enter numb back elements.\n");
    scanf("%d", &n);
    printf("Enter back elements.\n");
    for (int i = 0; i < n;i++) {
        scanf("%d",&val);
        PushBack(deq,val);
    }
    printf("Enter numb front elements.\n");
    scanf("%d", &n);
    printf("Enter front elements.\n");
    for (int i = 0; i < n;i++) {
        scanf("%d",&val);
        PushFront(deq,val);
    }
    printf("Deque output.\n");
    PrintDeque(deq);
    int size = deq -> size;
    int mass[size];
    int element;
    printf("Array before sort.\n");
    for (int i = 0; i < size; i++) {
        element = PopFront(deq);
        mass[i] = element;
        PushBack(deq,element);
    }
    for (int i = 0; i < size; i++) {
        printf("%d ",mass[i]);
    }
    printf("\n");
    int min, bble;
    for (int i = 0; i < size; i++){
        min = i;
        for (int j = i + 1;j<size; j++){
            if(mass[min] > mass[j]){
                min = j;
            }
        }
        if(mass[i] != mass[min]){
            bble = mass[i];
            mass[i] = mass[min];
            mass[min] = bble;
        }
    }
    printf("Array after sort.\n");
    for (int i = 0; i < size; i++) {
        printf("%d ",mass[i]);
    }
    printf("\n");
    printf("Maximum value: %d\n",mass[size-1]);
    deque* deq2 = CreateDeq();
    int elem;
    for(int i = 0; i< size;i++){
        elem = PopFront(deq);
        if(elem == mass[size-1]){
            continue;
        } else {
            PushBack(deq2,elem);
        }
    }
    printf("Deque output without max elem.\n");
    PrintDeque(deq2);
}
