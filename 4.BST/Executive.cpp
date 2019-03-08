/*
/ @file: Executive.cpp
/ @author: Lu Yin
/ @date: Feb 12, 2018
*/
#include "BinaryNode.h"
#include "Executive.h"
#include "BST.h"


#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

//constructor
Executive::Executive()
{
	B=new BST <int> ();
}
Executive::~Executive()
{
	delete B;
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
      B->Insert(node);
    }
    inp.close(); //close the file
    
    int opt=0; //options
    while (opt!=10)
    {
        cout<<". . . . . . . . . . . . . . . . . . . . . . . ."<<endl;
        cout<<"Please choose one of the following commands:"<<endl;
        cout<<"1 - Insert"<<endl;
        cout<<"2 - DeleteMin"<<endl;
        cout<<"3 - DeleteMax"<<endl;
        cout<<"4 - Delete"<<endl;
        cout<<"5 - FindMin"<<endl;
        cout<<"6 - FindMax"<<endl;
        cout<<"7 - Preorder"<<endl;
        cout<<"8 - Inorder"<<endl;
        cout<<"9 - Postorder"<<endl;
        cout<<"10 - Exit"<<endl;
       
        cin>>opt;

         if (opt==1) //Insert a number
        {
            int num;
            cout<<"Please Enter a number to be inserted: "<<endl;
            cin>>num;
            
            B->Insert(num);
        
            cout<<num<<" has been inserted"<<endl;
        }

        if (opt==2) //delete the minmum node
        {
            
            cout<<B->FindMin()->getItem()<<" has been deleted."<<endl;
            B->DeleteMin();
        }
        

        if (opt==3) //delete the maximum node
        {
            
            cout<<B->FindMax()->getItem()<<" has been deleted."<<endl;
            B->DeleteMax();
        }

        if (opt==4) //delete a target node
        {   
            int num;
            cout<<"Enter a number to be deleted : "<<endl;
            cin>>num;

            if(B->Search(num) == false) //the numer is not exist.
            {
                cout<<num<<" doesn't exist in the tree. "<<endl;
            }
            else
            {
                B->Delete(num);
                cout<<num<<" has been deleted "<<endl;
            }
        }
        
        if(opt == 5)  //find min
        {
            cout<<B->FindMin()->getItem()<<" is the smallest element. "<<endl;
        }

        if(opt == 6) //find max
        {
             cout<<B->FindMax()->getItem()<<" is the largest element. "<<endl;
        }

        if(opt == 7)  //preorder
        {
            B->PreorderTraverse();
            cout<<". "<<endl;
        }

        if(opt == 8)  //inorder
        {
            B->InorderTraverse();
            cout<<". "<<endl;
        }

        if(opt == 9)  //posterorder
        {
            B->PostorderTraverse();
            cout<<". "<<endl;
        }

        if (opt==10) //Exit
        {
            cout<<"Bye bye!"<<endl;
            cout<<"______________________________________"<<endl;
        }

    }
}
