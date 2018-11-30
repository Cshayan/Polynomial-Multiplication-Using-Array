#include <stdio.h>
#include <stdlib.h>

int *polyMul(int a[], int b[], int m, int n)
{
    int *mul;
    mul= (int*)malloc((m+n-1)*sizeof(int));
    int i;
    for(i=0; i<(m+n-1); i++)
    {
        mul[i]=0;
    }
    int j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            mul[i+j]+= a[i]*b[j];
        }
    }
    return mul;
}
void printPoly(int sum[], int large)
{
    int i;

    for(i=0; i<large; i++)
    {
        printf("%dx^%d ",sum[i],i);
        if(i!= large-1)
            printf(" + ");
    }
}
int main()
{
    int *a, *b, *mul;
    int m, n, i;

    printf("\nEnter the size of the 1st polynomial:- ");
    scanf("%d", &m);
    a=(int *) malloc(m*sizeof(int));
    printf("\nEnter the 1st polynomial:- ");
    for(i=0; i<m; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the size of the 2nd polynomial:- ");
    scanf("%d", &n);
    b=(int *) malloc(n*sizeof(int));
    printf("\nEnter the 2nd polynomial:- ");
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);

    printPoly(a, m);
    printPoly(b, n);

     mul= polyMul(a, b, m, n);

     printPoly(mul, (m+n-1));

     return 0;
}
