#include <iostream>  /*Preprocessor directive with the header files from C++ libraries*/
#include <iomanip> 
#include <string>
using namespace std; 

void readinput(string items[], int quantities[], double prices[], int amount); //Declared modular functions
void InvoiceOutput(string items[], int quantity[], double price[], int totalitems);

/*Main fucntion below*/
int main() 
{
    int totalitems, r; //Declaring variables with their data types

    string items[totalitems]; //Declaring arrays with their data types
    double price[totalitems];
    int quantity[totalitems];

    cout<< " --- Invoice Generation System --- "<<endl<<endl;
    cout<<"Enter the number of items: ";
    cin>>totalitems;
    cout<<endl<<endl;
    for(r=0;r<totalitems;r++)
    {
        readinput(items, quantity, price, r); //calls function
    }

    InvoiceOutput(items, quantity, price, totalitems); //calls function

    return 0;
}

void readinput(string items[], int quantity[], double price[],  int amount)//function definition that reads the user input
{
    cout << "Item #" << (amount + 1) << ":" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, items[amount]);
    cout << "Quantity: ";
    cin >> quantity[amount];
    cout << "Price per unit: $";
    cin >> price[amount];
    cin.ignore();
    cout<<endl;
}

void InvoiceOutput(string items[], int quantity[], double price[], int totalitems) //function definition that prints out the final invoice
{
    double totalAmount = 0.0; //double data type declaration must be in decimal points

    cout << endl << " --- Invoice --- " << endl<< endl<< endl;
    cout << "Item" << setw(15) << "Quantity"<< setw(20) << "Price Per Unit";
    cout << setw(10) << "Total" << endl;
   
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < totalitems; i++)
    {
        double itemTotal = quantity[i] * price[i];
        totalAmount += itemTotal;

        cout << items[i]<< setw(30) <<"$"<<quantity[i]<< setw(30) <<"$"<< price[i]<< setw(30) <<"$"<< itemTotal << endl;
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "Total:" << setw(50) <<"$"<< totalAmount << endl;
}
