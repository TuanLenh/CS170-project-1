#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node{
    private:
    vector<int> currValue;
    int gScore;
    
    public:
    Node *parentNode;
    Node *firstChild;
    Node *secondChild;
    Node *thirdChild;
    Node *fourthChild;

    Node();
    Node(vector<int>);
    vector<int> getData() const;
    void setData(const vector<int>&);

    void setgScore(int);
    int getgScore() const;
};

#endif