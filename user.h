#ifndef USER_H //GUARDS TO PREVENT MULTIPLE INCLUSIONS OF HEADER FILE
#define USER_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class User //BASE CLASS
{
    //PRIVATE DATA MEMBERS
    private:
    string name;
    string email;
    public:
    //Constructor with default parameters to allow for initialization of data
    User(string n="",string e=""):name(n),email(e){}
    void input() //FUNCTION FOR USER INPUT
    {
        ofstream outfile("output.txt",ios::app);
        cout<<"ENTER USERNAME :"<<endl;
        getline(cin,name);
        cout<<"ENTER USER EMAIL: "<<endl;
        getline(cin,email);
    }
    void show()const //FUNCTION TO DISPLAY USER DETAILS
    {
        ofstream outfile("output.txt",ios::app);
        cout<<"USER NAME : "<<name<<endl;
        cout<<"USER EMAIL :"<<email<<endl;
    }
    //Getter Functions
    void getname()
    {
        cout<<name<<endl;
    }
    void getemail()
    {
        cout<<email<<endl;
    }
};
#endif