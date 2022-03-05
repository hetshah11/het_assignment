#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct library
            {
                int acc_num;
                char title[50];
                char author[50];
                int price;
                char flag;
            }*b[10];
    int count=0;

struct library* addBook(int,char[],char[],int,char);
void display();
void findbook(char[]);
void listbook(int);
int findcount();
void sort();
void main()
    {
        int acc_num;
        char title[50];
        char author[50];
        int price;
        char flag;
        int ch,n;
        char temp_author[50];
        
        while(ch!=7)
        {
        printf("\nWelcome to Library\n\nPlease choose appropriate option\n\n1. Add book information\n2. Display book information\n3. List all books of given author\n4. List the title of specified book\n5. List the count of books in the library\n6. List the books in the order of accession number\n7. Exit\n");
        scanf("%d",&ch);
        printf("\n\n");
        switch(ch)
            {
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
                    
                            
                            
            }
        }




    }
struct library* addBook(int acc_num,char title[],char author[],int price,char flag)

    {
        struct library *temp;
        temp=(struct library*)malloc(sizeof(struct library));
        temp->acc_num=acc_num;
        strcpy(temp->title,title);
        strcpy(temp->author,author);
        temp->price=price;
        temp->flag=flag;
        return temp;
    }
    
void display()
    {
        int i;
        for(i=1;i<=count;i++)
            {
               // printf("%d",i);
                printf("Accesion number= %d\n",b[i]->acc_num);
                printf("title= %s\n",b[i]->title);
                printf("author= %s\n",b[i]->author);
                printf("price= %d\n",b[i]->price);
                printf("status= %c\n",b[i]->flag);
                printf("\n\n\n\n");
            }
    }
    
void findbook(char temp_author[])
    {
        int i;
        for(i=1;i<=count;i++)
            {
                if(strcmp(temp_author,b[i]->author)==0)
                    printf("\n%s\n",b[i]->title);
            }
    }
void listbook(int n)
    {
        int i;
        for(i=1;i<=count;i++)
            {
                if(b[i]->acc_num==n)
                    printf("Book associated with %d is %s",n,b[i]->title);
            }
    }
int findcount()
    {
        return count;
    }
void sort()
    {
        struct library temp;
        for(int k=0;k<count-1;k++)
        {                               //sorting array z using bubble sort
        for(int i=0;i<count-1;i++)
            {
                if(b[i]->acc_num > b[i+1]->acc_num)
                    {
                        temp=*b[i];
                        *b[i]=*b[i+1];
                        *b[i+1]=temp;
                    }
            }
        }
        display();
    }
