#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node{
    private:
    vector<int> currState;
    vector<vector<int>> recordOfState;
    
    public:
    Node *firstChild;
    Node *secondChild;
    Node *thirdChild;
    Node *fourthChild;

    Node();
    Node(vector<int>);
    vector<int> getData() const;
    void setData(const vector<int>&);

    //test function
    void printState() const;
};

#endif