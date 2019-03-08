/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : April 16, 2018
*/

#include "Executive.h"
#include "MinSkewHeap.h"
#include "MinLeftistHeap.h"

using namespace std;

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

Executive::Executive()
{

}
Executive::~Executive()
{

}

//run method
void Executive::run(string name)
{
    MinLeftistHeap<int>* L = new MinLeftistHeap<int> ();
    MinSkewHeap<int>* S = new MinSkewHeap<int> ();
    int h=0;
    while (h!=3)
    {
        cout<<"-----------------------------------------"<<endl;
        cout<<"1- Min Leftist Heap"<<endl;
        cout<<"2- Min Skew Heap"<<endl;
        cout<<"3- Exit"<<endl;
        cin>>h;

        if (h==1)
        {
            L->buildheap("data.txt");
            int opt=0; 
            while (opt!=6)
            {
                cout<<"............................................."<<endl;
                cout<<"Please choose one of the following commands: "<<endl;
                cout<<"1-	insert"<<endl;
                cout<<"2-	deleteMin"<<endl;
                cout<<"3-	preorder"<<endl;
                cout<<"4-	inoder"<<endl;
                cout<<"5-	levelOrder"<<endl;
                cout<<"6-	end"<<endl;
                cin>>opt;
                if (opt==1)  //insert
                {
                    int num;
                    cout<<"Enter a value to be inserted:"<<endl;
                    cin>>num;
                    L->insert(num);
                    cout<<" "<<endl;
                    
                }
                else if (opt==2)  //deletemin
                {
                    if (L->deletemin()==false)
                    {
                        cout<<"There is no minmum to delete. "<<endl;
                    }
                    else
                    {
                       cout<<"Minimum is deleted."<<endl;
                    }
                }
                else if(opt==3) //preorder
                {
                    cout<<"Preorder: "<<endl;
                    L->Preorder();
                    cout<<" "<<endl;
                }
                else if(opt==4)  //inoder
                {
                    cout<<"Inorder: "<<endl;
                    L->Inorder();
                    cout<<" "<<endl;
                }
                else if(opt==5)  //levelOrder
                {
                    cout<<"LevelOrder"<<endl;
                    L->levelorder();
                    cout<<" "<<endl;
                }
            }
        }
        else if (h==2)
        {
            S->buildheap("data.txt");
            int opt=0; 
            while (opt!=6)
            {
               cout<<"............................................."<<endl;
                cout<<"Please choose one of the following commands: "<<endl;
                cout<<"1-	insert"<<endl;
                cout<<"2-	deleteMin"<<endl;
                cout<<"3-	preorder"<<endl;
                cout<<"4-	inoder"<<endl;
                cout<<"5-	levelOrder"<<endl;
                cout<<"6-	end"<<endl;
                cin>>opt;
                if (opt==1)  //insert
                {
                    int num;
                    cout<<"Enter a value to be inserted:"<<endl;
                    cin>>num;
                    S->insert(num);
                    cout<<" "<<endl;
                }
                else if (opt==2)  //deletemin
                {
                    if (S->deletemin()==false)
                    {
                        cout<<"There is no minmum to delete. "<<endl;
                    }
                    else
                    {
                        cout<<"Minimum is deleted."<<endl;
                    }
                }
                else if(opt==3) //preorder
                {
                    cout<<"Preorder: "<<endl;
                    S->Preorder();
                    cout<<" "<<endl;
                }
                else if(opt==4)  //inoder
                {
                    cout<<"Inorder: "<<endl;
                    S->Inorder();
                    cout<<" "<<endl;
                }
                else if(opt==5)  //levelOrder
                {
                    cout<<"LevelOrder: "<<endl;
                    S->levelorder();
                    cout<<" "<<endl;
                }   
            } 
        }
        else
        {
            cout<<"Byebye!"<<endl;
        }
    }
    delete L;
    delete S;
}