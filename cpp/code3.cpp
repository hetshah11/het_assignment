/*Suppose you have a Piggie Bank with an initial amount of Rs.50 and you have to add some
more amount to it. Create a class &#39;AddAmount&#39; with a data member named &#39;amount&#39; with an
initial value of Rs. 50. Now make two constructors of this class as follows:
1 - without any parameter - no amount will be added to the Piggie Bank
2 - having a parameter which is the amount that will be added to the Piggie Bank
Create an object of the &#39;AddAmount&#39; class and display the final amount in the Piggie Bank.*/


//Edited By: Het Shah



#include<iostream>
using namespace std;

class AddAmount         //class AddAmount begins
    {                   
        int balance=50; //private member
        
        public:         //public methods
            AddAmount()     //default constructor
                {
                    cout << "with default constructor------ current balance is " <<balance << endl; 
                }
            AddAmount(int x)
                {       //parameterized constructor
                    balance+=x;
                    cout << "with parameterized constructor------ current balance is " <<balance << " (50+" << x <<")" << endl; 
                }
    };      //class AddAmount ends here
    
int main()
    {       //main method starts
        AddAmount obj1;     //creating object with default constructor
        AddAmount obj2(30);     // creating object with parameterized constructor
        
        return 0;
        
    }       //main method ends
