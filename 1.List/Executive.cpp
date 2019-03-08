/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: Jan 22, 2018
*/
#include "Executive.h"
#include "List.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

//constructor
Executive::Executive()
{

}

//descructor
Executive::Executive()
{

}



//run method
void Executive::run(char* name)
{
    //create a new list L
    List<int>* L=new List<int>();

    //read data from the input file data.txt
    ifstream inp;
    inp.open(filename);//open file
    int numb;  //new variables stands for the numbers
    while(!inp.eof()) //read through the whole file till it ends
    {
      inp>>numb;
    }
    inp.close(); //close the file



    int opt=0; //options
    while (opt!=5)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Insert"<<endl;
        cout<<"2 - Delete"<<endl;
        cout<<"3 - Find"<<endl;
        cout<<"4 - Print"<<endl;
        cout<<"5 - Exit"<<endl;

        cin>>opt;
         if (opt==1) //Insert a number
        {
            int num;
            cout<<"Please Enter a number to be inserted into the list: "<<endl;
            cin>>num;
            
            if(isFoundB4Imp(num) == true) // the number is already exist
            {
                cout<<" Entered number exists in the list. "<<endl;
            }
            else
            {
                L->insert(L, num);
                cout<<num+" is inserted to the list. "<<endl;
            }
        }

        if (opt==2) //delete a number
        {
            if (isEmpty() == true)
            {
                cout<<"The list is empty. "<<endl;
            }
            else
            {
                int num;
                cout<<"Enter a number to be deleted from the list: "<<endl;
                cin>>num;

                if(isFoundB4Imp(num) == false) //the numer is not exist.
                {
                    cout<<" Entered number doesn't exist in the list. "<<endl;
                }   
                else
                {
                    E.erase(L, num);
                }
            }
        }

        if (opt==3) //Find a target value
        {
            if (isEmpty() == true)
            {
                cout<<"The list is empty. "<<endl;
            }
            else
            {
                int num;
                cout<<"Enter a number to be found: "<<endl;
                cin>>num;

                if(isFoundB4Imp(num) == false) //the numer is not exist.
                {
                    cout<<" Entered number doesn't exist in the list. "<<endl;
                }   
                else
                {
                    cout<<" Entered number exists in the list."<<endl;
                }
            }
        }

        if (opt==4) //Print the whole list
        {
            if (isEmpty() == true) 
            {
                cout<<"The list is empty. "<<endl;
            }
            else
            {
                E.print(L);
            }
        }

        if (opt==5) //Exit
        {
            cout<<"Thank you!"<<endl;
            cout<<"______________________________________"<<endl;
            opt=5;
        }
    }
}
