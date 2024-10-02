#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, *p, i;
    printf("Enter Number of Size : ");
    scanf("%d",&n);
    p = (int*) malloc(n*sizeof(int));
    printf("Enter Element : ");
        for(i = 0; i < n; i++)
        scanf("%d",p+i);

    int largest = p[0];

    for(i=0; i<n; i++){
        if(*(p+i) > largest){
            largest = *(p+i);
        }
    }
    printf("Largest : %d",largest);

}