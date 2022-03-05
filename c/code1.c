/*Write a menu driven program that depicts the working of a library. The menu
options should be:
1. Add book information
2. Display book information
3. List all books of given author
4. List the title of specified book
5. List the count of books in the library
6. List the books in the order of accession number
7. Exit
Create a structure called library to hold accession number, title of the book, author
name, price of the book, and flag indicating whether the book is issued or not.*/


//Edited By: Het Shah







#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct library					//creating global user defined data type(structure)
            {
                int acc_num;
                char title[50];
                char author[50];
                int price;
                char flag;
            }*b[10];			//creating array of pointer of structure
    int count=0;

struct library* addBook(int,char[],char[],int,char);		//addBook() function declaratio
void display();							//display() function declaration
void findbook(char[]);						//findbook() function declaration
void listbook(int);						//listbook() function declaartion
int findcount();						//findcount() function declaration
void sort();							//sort() function declaration


int main()			//main method starts
    {
        int acc_num;
        char title[50];
        char author[50];
        int price;
        char flag;
        int ch,n;
        char temp_author[50];
        
        while(ch!=7)		//while loop starts
        {
        printf("\n\n\n\nWelcome to Library\n\nPlease choose appropriate option\n\n1. Add book information\n2. Display book information\n3. List all books of given author\n4. List the title of specified book\n5. List the count of books in the library\n6. List the books in the order of accession number\n7. Exit\n");
        scanf("%d",&ch);
        printf("\n\n");
        switch(ch)
            {						//Menu driven programme
                case 1:     					
                            b[count+1]=(struct library*)malloc(sizeof(struct library));
                            printf("Enter accesion number\n");
                            scanf("%d",&acc_num);
                            printf("Enter title\n");
                            scanf("%s",title);
                            printf("Enter author\n");
                            scanf("%s",author);
                            printf("Enter price\n");
                            scanf("%d",&price);
                            printf("Enter status\n");
                            scanf(" %c",&flag);
                            b[count+1]=addBook(acc_num,title,author,price,flag);
                            count++;
                            break;
                            
                    case 2: display();
                            break;
                            
                    case 3: printf("Enter Author name\n");
                            scanf("%s",temp_author);
                            findbook(temp_author);
                            break;
                            
                    case 4: printf("Enter accesion number\n");
                            scanf("%d",&n);
                            listbook(n);
                            break;
                            
                    case 5: printf("\nNo. of books=%d ",findcount());
                            break;
                            
                    case 6: sort();
                            break;
                    
                            
                            
            }		//switch statement ends here
        }		//whilw loop ends here


	return 0;

    }		//main function ends here
struct library* addBook(int acc_num,char title[],char author[],int price,char flag)		//returning structure pointer

    {
        struct library *temp;				//creating pointer of struct library type
        temp=(struct library*)malloc(sizeof(struct library));		//dynamic memory allocation to new pointer
        temp->acc_num=acc_num;
        strcpy(temp->title,title);
        strcpy(temp->author,author);
        temp->price=price;
        temp->flag=flag;
        return temp;
    }
    
void display()				//display function to display books
    {
        int i;

	printf("Accesion number\t\tTitle\t\tAuthor\t\tprice\t\tstatus\n");
        for(i=1;i<=count;i++)
            {
               // printf("%d",i);
                printf("%d\t\t\t",b[i]->acc_num);
                printf("%s\t\t",b[i]->title);
                printf("%s\t\t",b[i]->author);
                printf("%d\t\t",b[i]->price);
                printf("%c\n",b[i]->flag);
                
            }
	printf("\n\n\n\n");
    }
    
void findbook(char temp_author[])
    {							//function to find books of given author
        int i,sign=0;
        for(i=1;i<=count;i++)
            {
                if(strcmp(temp_author,b[i]->author)==0)
		{
                    printf("\n%s\n",b[i]->title);
		    sign=1;
		}
            }
	 if(sign==0)
		{
			printf("\nBook not available\n");
		}
    }
void listbook(int n)
    {				//function to find book with accesion number
        int i,sign=0;
        for(i=1;i<=count;i++)
            {
                if(b[i]->acc_num==n)
		{
                    printf("Book associated with %d is %s",n,b[i]->title);
		    int sign=1;
		}
		 
            }
	 if(sign==0)
		{
			printf("\nBook not available\n");
		}
    }
int findcount()				//function to count booksa
    {
        return count;
    }
void sort()			//function to sort library database in ascending order
    {
        struct library temp;
        for(int k=0;k<count-1;k++)
        {                               //sorting array z using bubble sort
        for(int i=1;i<count;i++)
            {
                if(b[i]->acc_num > b[i+1]->acc_num)
                    {
                        temp=*b[i];
                        *b[i]=*b[i+1];
                        *b[i+1]=temp;
                    }
            }
        }
        display();		//display() function to display sorted database
    }
