/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: Jan 30, 2018
*/
#include "Executive.h"
#include "List.h"
#include "Hashing.h"

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


//run method
void Executive::run(string file)
{
    //read data from the input file data.txt
    ifstream inp;
    inp.open(file);//open file
    int numb;  //new variables stands for the numbers
    inp>>numb; //get the size of the array
    Hashing <int>* H = new Hashing <int> (numb); //set the size to the array (using constructer to create an array with empty list in each bucket)
    //cout<<"size:"<<numb<<endl;
    while(!inp.eof()) //read through the whole file till it ends
    {
      inp>>numb;
      //H->isFoundB4Imp(numb); //no duplicate value allows.
      H->Insert(numb);
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
            cout<<"Please Enter a number to be inserted: "<<endl;
            cin>>num;

            if(H->Find(num) == true) // the number is already exist
            {
                cout<<num<<" is duplicated, can't be added to the hash table. "<<endl;
            }
            else
            {
                H->Insert(num);
                cout<<num<<" is inserted to the hash table. "<<endl;
            }
        }

        if (opt==2) //delete a target value
        {
            int num;
            cout<<"Enter a number to be deleted : "<<endl;
            cin>>num;

            if(H->Find(num) == false) //the numer is not exist.
            {
                cout<<num<<" doesn't exist in the hash table. "<<endl;
            }
            else
            {
                H->Delete(num);
                cout<<num<<" is deleted from the hash table. "<<endl;
            }
        }
        

        if (opt==3) //Find a target value
        {
                int num;
                cout<<"Enter a number to be found: "<<endl;
                cin>>num;

                if(H->Find(num) == false) //the numer is not exist.
                {
                    cout<<num<<" can't be found in the hash table. "<<endl;
                }
            else
            {
                cout<<num<<" exists in the hash table."<<endl;
            }
            
        }

        if (opt==4) //Print the whole list
        {
         
            H->Print();
        
        }

        if (opt==5) //Exit
        {
            cout<<"Thank you!"<<endl;
            cout<<"______________________________________"<<endl;
            opt=5;
            delete H;
        }

    }
}
