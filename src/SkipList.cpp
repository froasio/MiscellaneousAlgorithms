#include "SkipList.h"

SkipList::SkipList()
    : probability(0.5), maxLevel(16), currentLevel(0)
{

    int headKey = std::numeric_limits<int>::min();
    head = new SkipNode(headKey, "HEAD", maxLevel);

    int tailKey = std::numeric_limits<int>::max();
    tail = new SkipNode(tailKey, "TAIL", maxLevel);

    for (size_t i = 0; i < head->forward.size(); i++) {
        head->forward[i] = tail;
    }
}

SkipList::~SkipList () {
    SkipNode* curr = head;
    while(curr != tail){
        SkipNode* tpm = curr->forward[0];
        delete curr;
        curr = tpm;
    }
    delete tail;
}

int SkipList::randomLevel () {
    int v = 0;

    while ((((double)std::rand() / RAND_MAX)) < probability && 
           std::abs(v) < maxLevel) {

        v += 1;
    }
    return abs(v);
}

std::string SkipList::toString () {
    SkipNode* list = head;

    std::string s;
    s += "(";

    while (list->forward[0] != tail) {

        s+= "(" + std::to_string(list->forward[0]->key) + "," + list->forward[0]->value + ")";

        list = list->forward[0];

        if (list->forward[0] != tail) 
            s += ",";
    }
    s += ")";
    return s;
}

SkipNode* SkipList::find(int searchKey) {
    SkipNode* x = head;

    for (int i = currentLevel; i >= 0; i--) {
        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {
            x = x->forward[i];
        }   
    }

    x = x->forward[0];

    return x->key == searchKey ? x : nullptr;

} 

void SkipList::insert(int searchKey, std::string newValue) {

    SkipNode* x = head;
    std::vector<SkipNode*> update(head->forward);

    for (int i = currentLevel; i >= 0; i--) {

        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {

            x = x->forward[i];

        }
        update[i] = x;
    }
    x = x->forward[0];

    if (x->key == searchKey) {

        x->value = newValue;
        return;

    } else {

        int newNodeLevel = randomLevel();
        if (newNodeLevel > currentLevel) {

            for (int i = currentLevel + 1; i < newNodeLevel; i++) {
                update[i] = head;
            }
            currentLevel = newNodeLevel;   

        }

        x = new SkipNode(searchKey, newValue, newNodeLevel);

        for (int i = 0; i <= currentLevel; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
        
    }
}

void SkipList::erase (int searchKey) {

    std::vector<SkipNode*> update(head->forward);
    SkipNode* x = head;

    for (int i = currentLevel; i >= 0; i--) {

        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {

            x = x->forward[i];
        }
        update[i] = x;
    }

    x = x->forward[0];

    if (x->key == searchKey) {
        for (size_t i = 0; i < update.size(); i++) {

            if (update[i]->forward[i] != x) {
                break;
            }
            update[i]->forward[i] = x->forward[i];
        }

        delete x;
  
        while ( currentLevel >= 0  && head->forward[currentLevel] == tail )
            currentLevel--;        
    }    
}