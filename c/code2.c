/*Write a function that receives marks received by a student in 3 subjects
and returns the total and percentage of these marks. Call this function from
main( ) and print the results in main( ).*/

//Edited By: Het Shah


#include<stdio.h>
struct result
    {                               //structure with 2 data types
        float percentage;
        int total;
    };


struct result result(int,int,int);      //function declaration
int main()     //main method starts
    {
        int sub1,sub2,sub3;
        struct result t;    
        printf("Enter marks of 3 subjects\n");
        scanf("%d %d %d",&sub1,&sub2,&sub3);
        t=result(sub1,sub2,sub3);       //function calling
        printf("\n\nTotal marks= %d\nPercentage= %f",t.total,t.percentage);

	return 0;
    }
struct result result(int a,int b,int c)     //function to calculate total and percentage
    {
        struct result s;
        s.total=a+b+c;
        s.percentage=((float)a+b+c)/3;
        return s;       //returning stucture type varaiable
    }

