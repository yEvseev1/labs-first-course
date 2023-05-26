#include <stdio.h>

int main(){
    int n, m;
    printf("Enter matrix size(NxM).\n");
    scanf("%d %d",&n,&m);
    int matr[n][m];
    printf("Enter elements.\n");
    int counter = 0;
    for(int i = 0; i< n;i++){
        for(int j = 0; j<m;j++){
            scanf("%d",&matr[i][j]);
            if(matr[i][j] != 0){
                counter++;
            }
        }
    }
    int M[n];
    for(int i = 0;i<n;i++){
        M[i] = 0;
    }
    int A[counter][3];
    int ind = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matr[i][j] != 0){
                A[ind][0] = j;
                A[ind][1] = matr[i][j];
                A[ind][2] = ind + 1;
                ++ind;
                if(M[i] == 0){
                    M[i] = ind;
                }
            }
        }
        if(A[ind - 1][2] != 0){
            A[ind - 1][2] = 0;
        }
    }
    printf("M output:\n");
    for(int i = 0; i < n; i++){
        printf("%d ",M[i]);
    }
    printf("\n");
    printf("A output:\n");
    for(int i = 0; i < counter; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    int k;
    printf("Enter size vector.\n");
    scanf("%d",&k);
    if(k != n){
        printf("error size");
        return 1;
    } else {
        int vector[k];
        printf("Enter elements.\n");
        for(int i = 0; i < k; i++){
            scanf("%d", &vector[i]);
        }
        int ResMatr[m];
        for (int i = 0; i < m; i++)
            ResMatr[i] = 0;
        
        for(int j = 0;j<m;j++){
            for(int i = 0; i < n; i++){
                ResMatr[j] += matr[i][j] * vector[i];
            }
        }
        printf("Result matr.\n");
        for(int i = 0; i<m;i++){
            printf("%d ", ResMatr[i]);
        }
        printf("\n");
        int counter1;
        for(int i = 0;i<m;i++){
            if(ResMatr[i] != 0){
                counter1++;
            }
        }
        printf("Elements != 0 : %d",counter1);
    }
}