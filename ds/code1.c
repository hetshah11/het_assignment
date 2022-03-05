/*In-place merge two sorted arrays.
Given two sorted arrays, X[ ] and Y[ ] of size m and n each, merge elements of X[ ] with elements of
array Y[ ] by maintaining the sorted order, i.e., fill X[ ] with the first m smallest elements and fill Y[ ]
with remaining elements.
For example,
Input:
X[] = { 1, 4, 7, 8, 10 }
Y[] = { 2, 3, 9 }
Output:
X[] = { 1, 2, 3, 4, 7 }

Y[] = { 8, 9, 10 }*/



//Edited By: Het Shah




#include<stdio.h>

void main()         //main method starts
    {
        int m,n;
        printf("Enter elements to be inserted in array x and array y respectively\n");
        scanf("%d %d",&m,&n);
        int x[m],y[n],z[m+n],i,j,temp,k;    //Initializing x,y and z array
        printf("Insert elements in array x\n");
        for(i=0;i<m;i++)
            {                           //taking input into array x
                scanf("%d",&x[i]);
            }
        printf("Insert elements in array y\n");
        for(i=0;i<n;i++)
            {                       //taking input into array x
                scanf("%d",&y[i]);
            }
        
        for(i=0;i<m;i++)
            {                   //storing array x into empty array z
                z[i]=x[i];
            }
            j=0;
        for(i=5;i<m+n;i++)
            {
                                //appending elements of array y after elements of array x into array z
                z[i]=y[j];
                j++;
            }
    for(k=0;k<m+n-1;k++)
        {                               //sorting array z using bubble sort
        for(i=0;i<m+n-1;i++)
            {
                if(z[i]>z[i+1])
                    {
                        temp=z[i];
                        z[i]=z[i+1];
                        z[i+1]=temp;
                    }
            }
        }
        for(i=0;i<m;i++)
            {               //storing first m elements of sorted array z into array x
                x[i]=z[i];
            }
            j=0;
        for(i=5;i<m+n;i++)
            {               //storing remaining elements of sorted array z into array y
                
                y[j]=z[i];
                j++;
            }
            
            
        printf("\n\n\nAfter sorting\n");
        printf("Array x= ");
        for(i=0;i<m;i++)
            {                   //printing array x
                printf("%d ",x[i]);
            }
            printf("\n");
        printf("Array y= ");
        for(i=0;i<n;i++)
            {               //printing array y
                printf("%d ",y[i]);
            }
        
    }       //main method starts
    
