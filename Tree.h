#ifndef TREE_H
#define TREE_H
#include "Node.h"

using namespace std;

class Tree{
    private:
    vector<vector<int>> recordOfValue;
    vector<int> goalState;

    public:
    Tree();
    Node *root;

    void insert(vector<int>&, Node* );
    void moveBlankTile(Node* );
    bool duplicatedState(vector<int>&);
    void printRecordOfValue() const;
    int findgScoreOfNode(Node* );
    Node* findSmallestDepthLeaf(Node* );
};

#endif 
