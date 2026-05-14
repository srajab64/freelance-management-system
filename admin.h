#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<string>
#include "user.h"
class Admin:public User //DERIVED CLASS WILL INHERIT PUBLICLY FROM USER CLASS
{
    //PRIVATE DATA MEMBERS
    private:
    string ID;
    public:
    //Constructor
    Admin(string n="",string e="",string id=""):User(n,e),ID(id){}
    void input() // FUNCTION FOR ADMIN INPUT
    { 
        
        User::input(); //FOR CALLING INPUT FUNCTIO  FROM USER CLASS
        ofstream outfile("output.txt",ios::app);
        cout << "ENTER ADMIN ID: " <<endl;
        cin.ignore(); // Clear the input buffer
        getline(cin, ID);
    }
    void show()const
    {

        User::show();
        ofstream outfile("output.txt",ios::app);
        cout << "ADMIN ID: "<< ID <<endl;
    }
    //Getter Functions
    string getID() const  //getter function for file handling
    {
        return ID;
    }
    void getname()
    {
        return User::getname();
    }
    void getemail()
    {
        return User::getemail();
    }

};
#endif