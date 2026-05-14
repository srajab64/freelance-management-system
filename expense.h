#ifndef EXPENSE_H
#define EXPENSE_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Expense
{
    private:
    string description; //description of expense
    double amount; //amount of expense
    string date; //date of expense
    public:
    //CONSTRUCTOR
   Expense(string des="",double am=0.0,string da=""):description(des),amount(am),date(da){}
   void getExpense() //FUNCTION FOR GETTING EXPENSE DETAILS
   {
    ofstream outfile("output.txt",ios::app);

    cout<<"DESCRIPTION:"<<endl;
    getline(cin,description);
    cout<<"AMOUNT :"<<endl;
    cin>>amount;
    cin.ignore(); //TO CLEAR THE NEWLINE AFTER AMOUNTS INPUT
    cout<<"DATE :"<<endl;
    getline(cin,date);
   }
   void show()const //FUNCTION FOR SHOWING EXPENSE DETAILS
   {
    ofstream outfile("output.txt",ios::app);
    cout<<"EXPENSE"<<endl;
    cout<<"DESCRIPTION:"<<description<<endl;
    cout<<"AMOUNT: "<<amount<<"$"<<endl;
    cout<<"DATE: "<<date<<endl;
   }
   //GETTER FUNCTIONS FOR DESCRIPTION,AMOUNT,DATE TO RETRIEVE INDIVIDUAL DETAILS
   string getdescription()const
   {
    ofstream outfile("output.txt",ios::app);
    return description;
   }
   double getamount()const
   {
    ofstream outfile("output.txt",ios::app);
    return amount;
   }
   string getdate()const
   {
    ofstream outfile("output.txt",ios::app);
    return date;
   }
};
#endif