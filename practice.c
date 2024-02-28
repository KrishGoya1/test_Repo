// program to check if matrix is symmetric or not

#include<stdio.h>
int main(){
    int m,n;
    printf("Enter matrix dimensions : ");
    scanf("%d %d",&m,&n);
    
    int a[m][n];
    
    printf("Enter the matrix elements : \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=a[j][i])
                return printf("\nThe matrix is not symmetric");
        }
    }
    
    printf("\nThe matrix is symmetric");
    return 0;
}