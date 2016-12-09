#ifndef SKIP_LIST_H
#define SKIP_LIST_H 

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <utility> 

struct SkipNode {

    int key;
    std::string value;

    std::vector<SkipNode*> forward;

    SkipNode (int k, const std::string& v, int level); 

};

class SkipList {
public:
    SkipList ();
    ~SkipList ();

    std::string toString ();

    SkipNode* find (int searchKey);
    void insert (int searchKey, std::string newValue);
    void erase (int searchKey); 

private:
    // Pointer to first node
    SkipNode* head;
    // Pointer to Last node
    SkipNode* NIL;
    float probability;
    int maxLevel;

    int randomLevel (); 
    int nodeLevel(const std::vector<SkipNode*>& v);
    SkipNode* makeNode (int key, std::string val, int level);

};

#endif
