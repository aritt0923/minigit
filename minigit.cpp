//
// Created by Andrew Rittenhouse on 4/18/21.
//

#include "minigit.h"

bool searchSLL(std::string filename, singlyNode *head);
void addSLL(std::string filename, singlyNode *&head);



minigit::minigit()
{
    doublyNode *commit0 = new doublyNode;
    commit0->next = nullptr;
    commit0->previous = nullptr;
    commit0->head = nullptr;
    commit0->commitNumber = 0;
    doubleHead = commit0;
    currVersion = doubleHead;
    lateVersion = doubleHead;
}

bool minigit::gitInit()
{
    fs::create_directory("../.minigit");
}

bool minigit::gitAdd(std::string filename, bool debug)
{
    std::string ogFilename = filename;
    if (debug)
    {
        std::string parentDir = "../";
        filename = parentDir + filename;
    }

    if (fs::exists(filename) == 0)
    {
        return false;
    }
    if(searchSLL(ogFilename, currVersion->head))
    {
        std::cout << filename + " already added to repo." << std::endl;
        return false;
    }
    addSLL(filename, currVersion->head);

}


void addSLL(std::string filename, singlyNode *&head)
{
    singlyNode *newFile = new singlyNode;
    newFile->fileName = filename;
    newFile->fileVersion = filename + "_000";
    newFile->next = nullptr;

    if(head == nullptr)
    {
        head = newFile;
        return;
    }
    singlyNode *crawl = head;
    while (crawl->next)
    {
        crawl = crawl->next;
    }
    crawl->next = newFile;
}

bool searchSLL(std::string filename, singlyNode *head)
{
    singlyNode *crawl = head;
    while(crawl)
    {
        if (crawl->fileName == filename)
        {
            return true;
        }
        crawl = crawl->next;
    }
    return false;
}

