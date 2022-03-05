#include<stdio.h>
void enque(char [],int*,int*,char,int);
char deque(char [],int*,int*);

void main()
    {
        int front,rear,n,ch;
        front=rear=0;
        char queue[n+1],e;
        printf("Enter number\n");
        scanf("%d",&n);
    }
void enque( char queue[],int *front,int *rear, char e,int n)
        {
            if(*rear>=n)
                printf("Queue Overflow\n");
            else if(*front==0 & *rear==0)
                {
                    *rear=*rear+1;
                    queue[*rear]=e;
                    *front=*front+1;
                }
            else
                {
                    *rear=*rear+1;
                    queue[*rear]=e;
                }
        }
char deque(char queue[],int *front,int *rear)
    {
            int k;
            if(*front==0 && *rear==0)
                {
                   printf("Queue underflow\n");
                    return 32;
                }
               
            else if(*front==*rear && *front!=0)
                {
                    k=*front;
                    *front=*rear=0;
                    return queue[k];
                }
            else
                {
                   
                    *front=*front+1;
                    return queue[*front-1];
                }
               
               
    }
