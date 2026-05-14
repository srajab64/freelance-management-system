#ifndef FREELANCER_H
#define FREELANCER_H
#include<iostream>
#include<fstream>
#include<string>
#include "user.h"
class Freelancer:public User//Derived Class
{
    private:
    string expertise;
    double hourlyRate;
    public:
    //Constructor
    Freelancer(string n="",string e="",string ex="",double hr=0.0 ):User(n,e),expertise(ex),hourlyRate(hr){}
    void input() //FUNCTION FOR FREELANCER INPUT
    {
        User::input();
        cout<<"ENTER FREELANCER DETAILS:"<<endl;
        cout<<"ENTER EXPERTISE :"<<endl;
        getline(cin,expertise);
        do
        {
            cout<<"ENTER FREELANCER RATE(HOURLY) :"<<endl;
            cin>>hourlyRate;
            if(hourlyRate<0)
            {
                cout<<"INVALID RATE!,KINDLY ENTER A POSITIVE NUMBER"<<endl;
            }
            cin.clear();
            cin.ignore(1000,'\n');
        } 
        while (hourlyRate<0);
    }
        void show()const
        {
            User::show();
            cout<<"FREELANCER DETAILS :"<<endl;
            cout<<"EXPERTISE :  "<<expertise<<endl;
            cout<<"RATE(HOURLY)$:"  << hourlyRate<<"$"<<endl;
        }    
        double getHourlyrate()const 
        {
            return hourlyRate;
        }
        //GETTER FUNCTIONS FOR FREELANCER DETAILS FOR FILE HANDLING
        string getExpertise()const
        {
            return expertise;
        }
        double getHourlyRate()
        {
            return hourlyRate;
        }
};
#endif