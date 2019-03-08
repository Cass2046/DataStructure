/*
/ @file: Executive.h
/ @author: Lu Yin
/ @date: Feb 12, 2018
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

#include "BinaryNode.h"
#include "Executive.h"
#include "BST.h"

using namespace std;

class Executive
{
    public:
    //constructor
    Executive();
	~Executive();
    //main methods with UI
    void run(char* name);

    private:
	BST <int>* B;

};
#endif
