/*
/ @file: Executive.h
/ @author: Lu Yin
/ @date: Jan 22, 2018
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Node.h"
#include "List.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

using namespace std;

class Executive
{
    public:
    //constructor
    Executive();
    //descructor
    ~Executive();
    //main methods with UI
    void run(char* name);

    private:
    //Node<int>*L;
};
#endif
