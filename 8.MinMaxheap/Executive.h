/**
*	@file : Executive.h
*	@author :Lu Yin
*	@date : March 30, 2018
*	@brief: A header file for Executive class.
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "MaxMinHeap.h"
#include "MinMaxHeap.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
using namespace std;
class Executive
{
    public:
    Executive(char*file);
	~Executive();

    //main methods with UI
    void run(string name);

    private:
    int option;

};
#endif
