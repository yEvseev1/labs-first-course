/*На ввод поступает кол-во вершин и пары father - son*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct tree{
    int value;
    struct tree* left; //Старший брат
    struct tree* right; //Младшие братья
};

//Создание дерева и вершин(father-son)
struct tree* CreateNode(struct tree* tree, int father, int son, int CheckFather){
    if(tree == NULL){
        if(CheckFather == 1){
            tree = (struct tree*) malloc (sizeof(struct tree));
            tree -> value = son;
            tree -> left = NULL;
            tree -> right = NULL;
            CheckFather = 2;
        }
    } else if ((father == tree -> value) && (CheckFather == 0)){
        CheckFather = 1;
        tree -> left = CreateNode(tree -> left, father, son, CheckFather); //Создание старшего
    } else if (CheckFather == 1) {
        tree -> right = CreateNode(tree -> right, father, son, CheckFather); // Создание младшего 
    } else if (CheckFather == 0) {
        //Поиск нужного узла, чтобы было value == father 
        tree -> left = CreateNode(tree -> left, father, son, CheckFather);//проверка всех старших братьев
        tree -> right = CreateNode(tree -> right, father, son, CheckFather);//проверка всех младших братьев
    }
    return (tree);
}

//Распечатка дерева
void PrintTree(struct tree* tree, int counter){
    if(tree != NULL){
        for(int i = 0; i < counter;++i){
            printf("-");
        } 
        counter++;
        printf("%d\n", tree -> value);
        PrintTree(tree -> left, counter);
        counter--;
        PrintTree(tree -> right, counter);
    }
}

//Функция для нахождения степени вершины
int degree(struct tree* tree){
    if (tree == NULL || tree -> left ==NULL){
        return 0;
    }
    int i = 1;
    tree = tree -> left;
    while (tree -> right != NULL){
        tree = tree -> right;
        i++;
    }
    return i;   
}

//Найти кол-во вершин со степенью равной значению вершины
void task(struct tree* tree, int* counter){
    if(degree(tree)==tree->value){
        *counter+=1;
    }
    if(tree->left !=NULL){
        task(tree->left,counter);
    }
    if(tree->right != NULL) {
        task(tree->right, counter);
    }
}


int main(){
    struct tree* root;
    root = NULL;
    int kolvo;
    printf("Enter numb nodes.\n");
    scanf("%d", &kolvo);
    int father, son;
    printf("Enter pairs father - son.\n");
    scanf("%d %d", &father, &son);
    int CheckFather = 1;
    root = CreateNode(root, father, son, CheckFather);
    for (int i = 0; i < kolvo-1; i++) {
        scanf("%d %d", &father, &son);
        CheckFather = 0;
        root = CreateNode(root, father, son, CheckFather);
    }
    printf("Visual tree\n");
    PrintTree(root,0);
    int counter = 0;
    task(root,&counter);
    printf("answer: %d\n",counter);
    return 0;
}

