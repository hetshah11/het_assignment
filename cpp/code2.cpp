/*Create a class called &#39;Matrix&#39; containing a constructor that initialises the number of rows and the
number of columns of a new Matrix object. The Matrix class has the following information:
1 - number of rows of matrix
2 - number of columns of matrix
3 - elements of matrix (You can use 2D vector)
The Matrix class has functions for each of the following:

1 - get the number of rows
2 - get the number of columns
3 - set the elements of the matrix at a given position (i,j)
4 - adding two matrices.
5 - multiplying the two matrices
You can assume that the dimensions are correct for the multiplication and addition.*/


//Edited By: Het Shah




#include<iostream>
using namespace std;
class Matrix        //class Matrix starts
    {
        int row;
        int col;        //private members
        
        
        public:
            Matrix()        //default constructor
                {
                    row=2;
                    col=2;
                    
                }
        private:
            int m[2][2];        //declaring 2D array
        public:
             int getrow()
                {
                    return row;     //getrow() method
                }
            int getcol()
                {                   //getcol() method
                    return col;
                }
            void setElement(int x,int y,int z)
                {               //setElement() method
                    m[x][y]=z;
                }
            
            Matrix add(Matrix obj1,Matrix obj2)
                {               //Addition of matrix
                Matrix obj3;        //creating object of class
                
                   for(int i=0;i<row;i++)
                    {
                        for(int j=0;j<col;j++)
                            {
                                obj3.m[i][j]=obj1.m[i][j]+obj2.m[i][j];
                            }
                    }
                    return obj3;        //returning object
                }
            Matrix mul(Matrix obj1,Matrix obj2)     //multiplication of matrix
                {
                    Matrix obj3;    //creating object of class
                    for(int i=0;i<row;i++)
					{
						for(int j=0;j<col;j++)
							{
							   obj3.m[i][j]=0;
								for(int k=0;k<col;k++)
								{
									obj3.m[i][j]+=obj1.m[i][k]*obj2.m[k][j];
								}

							}
						
					}
				
                    return obj3;        //returning object
                }
            void display()      //display() function to print matrix on console
                {
                    for(int i=0;i<row;i++)
                        {
                            for(int j=0;j<col;j++)
                                {
                                    cout << m[i][j]<<" ";
                                }
                                cout << endl;
                        }
                }
    };      //class Matrix ends here
int main()
    {
        Matrix obj1,obj2,obj3,obj4;     //creating 4 objects of class Matrix
        obj1.setElement(0,0,1); 
        obj1.setElement(0,1,2);
        obj1.setElement(1,0,3);     //Invoking setElement() method for obj1
        obj1.setElement(1,1,4);
        
        obj2.setElement(0,0,5);
        obj2.setElement(0,1,6);     //Invoking setElement() method for obj2
        obj2.setElement(1,0,7);
        obj2.setElement(1,1,8);
        
        cout << "First matrix" << endl;
        obj1.display();     //displaying 1st matrix
        
        cout << "Second matrix" << endl;
        obj2.display();     //displaying 2nd matrix
        
        
        obj3=obj1.add(obj1,obj2);       //Invoking add() method
        obj4=obj1.mul(obj1,obj2);       //Invoking mul() method
        
        cout <<endl<<endl<< "Addition of matrix" << endl;
        obj3.display();         //displaying Addition of matrix
        cout << endl<<endl;
        cout << "Multiplication of matrix" << endl;
        obj4.display();         //displaying Multiplication of matrix
        
    }       //main method ends here
