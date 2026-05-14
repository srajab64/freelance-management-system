#ifndef PAYMENT_H
#define PAYMENT_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Payment
{
    private:
    double amount;
    string method;
    string date;
    public:
    //CONSTRUCTOR
    Payment(double am=0.0,string me="",string da=""):amount(am),method(me),date(da){}
    void getPayment()
    {
        ofstream outfile("output.txt",ios::app);
        cout<<"PAYMENT OF $:"<<endl;
        cin>>amount;
        cout<<"METHOD(PAYPAL, CASH, BANK TRANSFER):"<<endl;
        cin.ignore();
        getline(cin,method);
        cout<<"TRANSACTION DATE: "<<endl;
        getline(cin,date);
    }
    void show()const
    {
        ofstream outfile("output.txt",ios::app);
         cout<<"PAYMENT OF $:"<<amount<<"$"<<"  ,"<<"METHOD: "<< method<<", DATE: "<<date<<endl;
    }
    //getter functions for payment
    double getAmount()const
    {
        ofstream outfile("output.txt",ios::app);
        return amount;
    }
    string getMethod()const
    {
        ofstream outfile("output.txt",ios::app);
        return method;
    }
    string getDate()const
    {
        ofstream outfile("output.txt",ios::app);
        return date;
    }
};
#endif // PAYMENT_H