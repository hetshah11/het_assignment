/*Generate binary numbers between 1 to `n` using a queue.
Given a positive number n, efficiently generate binary numbers between 1 and n using the queue data
structure in linear time.
For example, for n = 16, the binary numbers are:
Input :
1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000
Output:
1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000*/

//Edited By; Het Shah




#include <stdio.h>
#include <string.h>

#define MAX 30
char queue[MAX][MAX], temp[MAX];
int front = -1, rear = -1;

				//inserting an elements into queue
void enqueue(char *ptr)
{
    if (rear == MAX - 1)
    {
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear = rear + 1;
    strcpy(queue[rear], ptr);
}


				//deleting an elements from queue
char *dequeue()
{
    if (front == -1)
        printf("\nEmpty Queue");
    else
    {
        strcpy(temp, queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = front + 1;
        return temp;
    }
}

void binary_numbers_using_queue()		//function to implementing binary numbers using queue.
{
    char temp2[MAX];
    strcpy(temp, dequeue());
    printf("%s ", temp);
    strcpy(temp2, temp);
    strcat(temp, "0");
    enqueue(temp);
    strcat(temp2, "1");
    enqueue(temp2);
} 			

int main()
{				//main function
    int i, n;
    printf("Enter the end value : ");
    scanf("%d", &n);
    char temp[2] = "1";
    enqueue(temp);
    printf("\nBinary numbers from 1 to %d : \n", n);
    for (i = 1; i <= n; i++)
    {
        binary_numbers_using_queue();
    }
    printf("\n");
    return 0;
}   //end of main function


