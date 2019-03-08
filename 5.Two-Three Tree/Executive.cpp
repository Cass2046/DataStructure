/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: Feb 12, 2018
*/
#include "TwoThreeTree.h"
#include "Executive.h"
#include "Node.h"


#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

//constructor
Executive::Executive()
{
	N=new TwoThreeTree<int> ();
}
Executive::~Executive()
{
	delete N;
}

//run method
void Executive::run(char* name)
{
    //read data from the input file data.txt
    ifstream inp;
    inp.open(name);//open file

    int node;

    while(!inp.eof()) //read through the whole file till it ends
    {
      inp>>node;
      N->Insert(node);
    }
    inp.close(); //close the file

    int opt=0; //options
    while (opt!=9)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Insert"<<endl;
        cout<<"2 - DeleteMin"<<endl;
        cout<<"3 - DeleteMax"<<endl;
        cout<<"4 - FindMin"<<endl;
        cout<<"5 - FindMax"<<endl;
        cout<<"6 - Find"<<endl;
        cout<<"7 - Delete"<<endl;
        cout<<"8 - Level order"<<endl;
        cout<<"9 - Exit"<<endl;

        cin>>opt;

        if (opt==1) //Insert a number
        {
            int num;
            cout<<"Please Enter a number to be inserted: "<<endl;
            cin>>num;

            N->Insert(num);

            cout<<num<<" has been inserted"<<endl;
        }

        if (opt==2) //delete the minmum node
        {
            if (N->FindMin()!=-1)
            {
                 cout<<N->FindMin()<<" has been deleted."<<endl;
                 N->DeleteMin();
            }
            else
            {
                cout<<"There is no minimum."<<endl;
            }
           
        }

        if (opt==3) //delete the maximum node
        {
            if (N->FindMax()!=-1)
            {
                 cout<<N->FindMax()<<" has been deleted."<<endl;
                 N->DeleteMax();
            }
            else
            {
                cout<<"There is no maximum."<<endl;
            }
        }

        if(opt == 4)  //find min
        {
            cout<<N->FindMin()<<" is the smallest element. "<<endl;
        }

        if(opt == 5) //find max
        {
             cout<<N->FindMax()<<" is the largest element. "<<endl;
        }

        if(opt == 6)  //find node
        {
            int a;
            cout<<"Enter a number to be found: "<<endl;
            cin>>a;
            if (N->Findnum(a) == false)
            {
                cout<<a<<" do not exist in the tree. "<<endl;
            }
            else
            {
                cout<<a<<" exist in the tree. "<<endl;
            }
            
        }
  
        if(opt == 7)  //delete a target node
        {
            int b;
            cout<<"Enter a number to be deleted: "<<endl;
            cin>>b;
            if ( N->Delete(b)==true)
            {
                cout<<b<<" has been deleted from the tree. "<<endl;
            }
            else
            {
                cout<<b<<" do not exist. "<<endl;
            }
        }

        if(opt == 8)  //level order
        {
            cout<<"Level Order:  ";
            N->levelOrderTraverse();
            cout<<". "<<endl;
        }

        if (opt == 9) //Exit
        {
            cout<<"Bye bye!"<<endl;
            cout<<"______________________________________"<<endl;
        }

     }
}
