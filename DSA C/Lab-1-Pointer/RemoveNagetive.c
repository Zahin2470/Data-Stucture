#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, *p, i;
    printf("Enter Number of Size : ");
    scanf("%d",&n);
    p = (int*) malloc(n*sizeof(int));
    printf("Enter Element : ");
    for(i = 0; i < n; i++)
        scanf("%d",p+i);

    int j =0;
    for(i = 0; i < n; i++){
        int val = *(p+i);
        if(val >= 0){
            *(p+j) =*(p+i);
            j++;
        }
    }
    n = j;
    p = realloc(p,n*sizeof(int));
    printf("Final Array : ");
    for(i = 0; i < n; i++)
        printf("%d ",*(p+i));
}