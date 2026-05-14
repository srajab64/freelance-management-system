#ifndef TASK_H
#define TASK_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Task
{
    private:
    string title;
    string description;
    string dueDate;
    string status;
    int esthours;    //ESTIMATED HOURS
    int acthours;   //ACTUAL HOURS
    double HourlyRate;
    public:
    //Constructor
    Task() : esthours(0), acthours(0), HourlyRate(0.0), status("Pending") {}
    void setTask(string t, string d, string dd,int ah, double rate)
    {
        title = t;
        description = d;
        dueDate = dd;
        acthours = ah;
        HourlyRate = rate;
    }
    string getTask() const{return title;}
    string getStatus()const {return status;}
    int getActualHours(){return acthours;}
    double getHourlyRate(){return HourlyRate;}
    //For updating Methods
    void logHours(int hours)
     {
        acthours += hours;
    }

    void completeTask()
     {
        status = "Completed";
    }

    double getCost() const 
    {
        return acthours * HourlyRate;
    }
    void show()const
    {
        ofstream outfile("output.txt",ios::app);
        cout<<"TITLE :"<<title<<endl;
        cout<<"DESCRIPTION :"<<description<<endl;
        cout<<"DUE DATE :"<<dueDate<<endl;
        cout<<"ESTIMATED HOURS :"<<esthours<<endl;
        cout<<"ACTUAL HOURS :"<<acthours<<endl;
        cout<<"HOURLY RATE :"<<HourlyRate<<"$"<<endl;
        cout<<"STATUS: "<<status<<endl;
    }
};
#endif