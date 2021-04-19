//
// Created by Andrew Rittenhouse on 4/18/21.
//

#ifndef MINIGIT_MINIGIT_H
#define MINIGIT_MINIGIT_H

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

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
    minigit(); //creates commit0 doublyNode, sets it to doubleHead
    ~minigit(); //

    bool gitInit();
    bool gitAdd(std::string filename, bool debug = 0);





private:
    doublyNode *doubleHead{};
    doublyNode *currVersion;
    doublyNode *lateVersion;

};


#endif //MINIGIT_MINIGIT_H
