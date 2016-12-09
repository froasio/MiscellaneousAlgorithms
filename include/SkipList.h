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

    SkipNode (int k, const std::string& v, int level)
      :  key(k), value(v), forward(level+1)
    {
        for (int i = 0; i <= level; ++i) {
            forward[i]  = nullptr;
        }
    } 

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
    SkipNode* tail;
    float probability;
    int maxLevel;
    int currentLevel;

    int randomLevel (); 

};

#endif
