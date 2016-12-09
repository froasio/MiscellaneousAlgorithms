#include "SkipList.h"

SkipNode::SkipNode (int k, const std::string& v, int level)
    :  key(k), value(v), forward(level)
{
    for (int i = 0; i < level; ++i) {
        forward[i]  = nullptr;
    }
} 

SkipList::SkipList()
    : probability(0.5), maxLevel(16)
{

    int headKey = std::numeric_limits<int>::min();
    head = new SkipNode(headKey, "HEAD", maxLevel);

    int nilKey = std::numeric_limits<int>::max();
    NIL = new SkipNode(nilKey, "NIL", maxLevel);

    for (size_t i = 0; i < head->forward.size(); ++i) {
        head->forward[i] = NIL;
    }
}

SkipList::~SkipList () {
    delete head;
    delete NIL;
}

int SkipList::randomLevel () {
    int v = 1;

    while ((((double)std::rand() / RAND_MAX)) < probability && 
           std::abs(v) < maxLevel) {

        v += 1;
    }
    return abs(v);
}

/*
    Function: nodeLevel()
    Use: Implicitly in most of the member functions.

    It returns the number of non-null pointers
    corresponding to the level of the current node.
    (the node that contains the checked vector of 
    forward pointers)

    If list empty returns 1.
*/
int SkipList::nodeLevel (const std::vector<SkipNode*>& v) {
    int currentLevel = 1;
    // last element's key is the largest
    int nilKey = std::numeric_limits<int>::max();

    if (v[0]->key == nilKey) {
        return currentLevel;
    }

    for (size_t i = 0; i < v.size(); ++i) {

        if (v[i] != nullptr && v[i]->key != nilKey) {
            ++currentLevel;
        } else { 
            break;
        }
    }
    return currentLevel;
}

std::string SkipList::toString () {
    SkipNode* list = head;

    std::string s;
    s += "(";

    while (list->forward[0] != nullptr and list->forward[0]->key != std::numeric_limits<int>::max()) {

        s+= "(" + std::to_string(list->forward[0]->key) + "," + list->forward[0]->value + ")";

        list = list->forward[0];

        if (list->forward[0] != nullptr and list->forward[0]->key != std::numeric_limits<int>::max()) 
            s += ",";
    }
    s += ")";
    return s;
}
/*
    Function: find()
    Use: SkipNode* found = skip_list_obj.find(searchKey);

    It searches the skip list and
    returns the element corresponding 
    to the searchKey; otherwise it returns
    failure, in the form of null pointer.
*/
SkipNode* SkipList::find(int searchKey) {
    SkipNode* x = head;
    unsigned int currentMaximum = nodeLevel(head->forward);

    for (unsigned int i = currentMaximum; i-- > 0;) {
        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {
            x = x->forward[i];
        }   
    }
    x = x->forward[0];

    if (x->key == searchKey) {
        return x;
    } else {
        return nullptr;
    }
} 

// Modifying member functions
/*
    Function: makeNode ()
    Use: Implicitly in member function insert().

    It wraps the SkipNode constructor which creates
    a node on the heap and returns a pointer to it. 
*/
SkipNode* SkipList::makeNode (int key, std::string val, int level) {
    return new SkipNode(key, val, level);
}

/*
    Function: insert();
    Use: void insert(searchKey, newValue);

    It searches the skip list for elements
    with seachKey, if there is an element
    with that key its value is reassigned to the 
    newValue, otherwise it creates and splices
    a new node, of random level.
*/
void SkipList::insert(int searchKey, std::string newValue) {
    // reassign if node exists 
    SkipNode* x = nullptr;
    x = find(searchKey);
    if (x) {
        x->value = newValue;
        return;
    }

    // vector of pointers that needs to be updated to account for the new node
    std::vector<SkipNode*> update(head->forward);
    unsigned int currentMaximum = nodeLevel(head->forward);
    x = head;

    // search the list 
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {

            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    // create new node
    int newNodeLevel = 1;
    if (x->key != searchKey) {

        newNodeLevel = randomLevel();
        int currentLevel = nodeLevel(update);

        if (newNodeLevel > currentLevel) {

            for (int i = currentLevel + 1; i < newNodeLevel; ++i) {

                update[i] = head;
            }   
        }
        x = makeNode(searchKey, newValue, newNodeLevel);
    }

    // connect pointers of predecessors and new node to successors
    for (int i = 0; i < newNodeLevel; ++i) {

        x->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = x;
    }
}

/*
    Function: delete_node()
    Use: skip_list_obj.erase(searchKey)

    It deletes the element containing 
   searchKey, if it exists.
*/
void SkipList::erase (int searchKey) {
    // vector of pointers that needs to be updated to account for the deleted node
    std::vector<SkipNode*> update(head->forward);
    SkipNode* x = head;
    unsigned int currentMaximum = nodeLevel(head->forward);

    // search and update pointers
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forward[i] != nullptr && x->forward[i]->key < searchKey) {

            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    // update pointers and delete node 
    if (x->key == searchKey) {
        for (size_t i = 0; i < update.size(); ++i) {

            if (update[i]->forward[i] != x) {

                break;
            }
            update[i]->forward[i] = x->forward[i];
        }
        delete x;        
    }    
}