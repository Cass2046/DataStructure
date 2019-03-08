/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : April 16, 2018
*	@brief: A header file for Executive class.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "LeftistNode.h" 
#include "SkewNode.h"
#include "MinLeftistHeap.h"
#include "MinSkewHeap.h"

#include "Queue.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
using namespace std;
class Executive
{
    public:
    Executive();
	~Executive();

    //main methods with UI
    void run(string name);

    private:
    //int option;

};
#endif
