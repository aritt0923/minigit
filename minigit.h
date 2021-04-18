//
// Created by Andrew Rittenhouse on 4/18/21.
//

#ifndef MINIGIT_MINIGIT_H
#define MINIGIT_MINIGIT_H

#include <iostream>
#include <filesystem>

struct singlyNode
{
    std::string fileName;
    std::string fileVersion; // Name of file in .minigit folder
    singlyNode *next;
};

struct doublyNode
{
    int commitNumber;
    singlyNode *head;
    doublyNode *previous;
    doublyNode *next;
};


class minigit
{

public:
    doublyNode *doubleHead;

private:


};


#endif //MINIGIT_MINIGIT_H
