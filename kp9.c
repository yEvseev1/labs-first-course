#include <stdio.h>

void VisualTable(int table[][2],int n){
    printf("  key: ");
    for (int i = 0; i < n;i++){
        printf("%d ",table[i][0]);
    }
    printf("\n");
    printf("value: ");
    for (int i = 0; i < n;i++){
        printf("%d ",table[i][1]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void BinSearch(int keys[][2],int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key == keys[mid][0]) {
            printf("Value = %d",keys[mid][1]);
            return;
        }
        if (key < keys[mid][0]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("No value for this key.");
    return;
}
int main() {
    int n;
    printf("enter numb elements.\n");
    scanf("%d",&n);
    int table[n][2];
    printf("Enter elements. Key - value.\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&table[i][0],&table[i][1]);
    }
    VisualTable(table,n);
    printf("\n");

    int keys[n];          // вектор ключей , который будет сортироваться
    
    for (int i = 0;i<n;i++) {
        keys[i] = table[i][0]; 
    }

    printf("\n");
    mergeSort(keys,0,n-1);
    for (int i = 0; i < n;i++) {
        if (table[i][0]==keys[i]) {
            continue;
        } else {
            for (int j = 0; j < n;j++) {
                if (table[j][0] == keys[i]) {
                    int tmpk, tmpv;
                    tmpk = table[i][0];
                    tmpv = table[i][1];
                    table[i][0] = table[j][0];
                    table[i][1] = table[j][1];
                    table[j][0] = tmpk;
                    table[j][1] = tmpv;
                }
            }
        }
    }
    VisualTable(table,n);
    printf("\n");
    int flag = 1;

    while (flag) {
            int var, keyy;
        printf("1.Search value for key. 2.Exit\n");
        scanf("%d",&var);
        if(var == 1){
            printf("Enter key: ");
            scanf("%d",&keyy);
            BinSearch(table,n,keyy);
        }
        if(var == 2){
            flag = 0;
        }
        printf("\n");
    }
}