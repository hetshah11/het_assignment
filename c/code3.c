/*Search and Sequence
Consider an integer array ‘a’ of size 10, where the value of the array elements are
{1,5,4,8,9,2,0,6,11,7}. Write a program to
▪ Find whether the given element exists in an array or not. If the element exists in an
array, display YES else NO.
▪ To print a number following a sequence of elements in an array i.e., 15489206117.*/

//Edited By:Het Shah



#include<stdio.h>
void main()
    {
        int arr[10]={1,5,4,8,9,2,0,6,11,7},n,flag=0,i;  //declaring array of size 10
        printf("Enter number to be searched\n");
        scanf("%d",&n);
        for(i=0;i<10;i++)
            {                   //for loop starts to find number
                if(arr[i]==n)
                    {
                        printf("Number found at %dth position\n",i+1);
                        flag=1;     //flag to be set if number found in array
                        break;
                    }
            }
            if(flag==0)
                printf("Number not found\n");       //Error to be displayed if number not found
            printf("\n\n");
            printf("Number following sequence: ");
            for(i=0;i<10;i++)
                {           //for loop for printing sequence following numbers in array
                    printf("%d",arr[i]);
                }
    }
