#ifndef TREE_H
#define TREE_H
#include "Node.h"

using namespace std;

class Tree{
    private:
    vector<vector<int>> recordOfState;
    vector<int> goalState;

    public:
    Tree();
    Node *root;
    // void printState();
    void insert(vector<int>&);

    void moveBlankTile(Node*);
    bool duplicatedState(vector<int>&);
    void printRecordOfState() const;

    bool goalStateCheck(vector<int>&);
};

#endif 
