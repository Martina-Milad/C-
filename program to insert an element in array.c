#include <stdio.h>
#define MAXSIZE 100

int main()
{
    int arr[MAXSIZE] ,i , x ,elment , position ;
	printf("enter size of array ");
	scanf("%d" , &x);
	printf("Input array elements: ");
	for(i = 0 ; i<x ;i++){
		scanf("%d", &arr[i]);
	}

	printf("Input element to insert: ");
	scanf("%d" , &elment);
	printf("Input position where to insert: ");
	scanf("%d" , &postion);
	

	if(pos > size+1 || pos <= 0)
    {
        printf("Wrong position");
    }
    else
    {
        for(i=size; i>=pos; i--)
        {
            arr[i] = arr[i-1];
        }
        
        /* Insert new element at given position and increment size */
        arr[pos--1] = num;
        size++; 
	
	printf("Array elements after insertion : ");
	for(i=0 ;i<x ; i++)
	{
		printf("%d\n", arr[i]);
	}


}
