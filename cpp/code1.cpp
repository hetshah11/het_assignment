/*Write a program by creating an &#39;Employee&#39; class having the following functions and print the
final salary.
1 - &#39;getInfo()&#39; which takes the salary, number of hours of work per day of employee as
parameters
2 - &#39;AddSal()&#39; which adds $10 to the salary of the employee if it is less than $500.
3 - &#39;AddWork()&#39; which adds $5 to the salary of the employee if the number of hours of work per
day is more than 6 hours.*/

//Edited by: Het Shah




#include <iostream>

using namespace std;

class Employee      //class Employee starts
    {
        int salary,h_p_d;       //private member,here h_p_d means "hours per day"
        
        public:             //public methods that accesses private members
        void getInfo(int x,int y)       //getinfo() method
            {
                salary=x;
                h_p_d=y;
                cout << "employee's salary is "<<salary <<" and hours per day are "<<h_p_d<<endl;
            }
        void addSal()       //addSal() method to increase salary based on current salary
            {
                if(salary<500)
                    {
                    salary+=10;
                    cout << "Congratulations! Your salary us increased by 10$. Your new salary is "<< salary<<"$"<< endl;
                    }
                else
                    cout << "No salary increment based on your current salary" << endl;
            }
        void addWork()      //addWork() method that increases salary based on current hours per day
            {
                if(h_p_d>6)
                    {
                        salary+=5;
                        cout << "Congratulations! Your salary us increased by 5$. Your new salary is "<<salary<<"$"<< endl;
                    }
                else
                    cout << "No salary increment based on your current hours per day" << endl;
              
            }
    };      //class Employee ends

int main()      //main method starts
{
    int x,y;
    cout<<"Enter salary and hours per day" << endl;
    cin >> x >> y;
    Employee e;     //creating object of Employee
    e.getInfo(x,y);     //Invoking methods of class Employee through object e
    e.addSal();
    e.addWork();
    

    return 0;
}       //main method ends here
