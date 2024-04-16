#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Node::Node(){
    currState = {};
    recordOfState = {};
    firstChild = nullptr;
    secondChild = nullptr;
    thirdChild = nullptr;
    fourthChild = nullptr;
}

Node::Node(vector<int> newState){
    currState = newState;
    recordOfState.push_back(newState);
    firstChild = nullptr;
    secondChild = nullptr;
    thirdChild = nullptr;
    fourthChild = nullptr;
}

vector<int> Node::getData() const{
    return currState;
}

void Node::setData(const vector<int>& newState){
    currState = newState;
}

//test function
void Node::printState() const{
    for(int j = 0; j < 3; ++j){
        cout << currState.at(j) << " ";
    }
    cout << endl;
    for(int j = 3; j < 6; ++j){
        cout << currState.at(j) << " ";
    }
    cout << endl;
    for(int j = 6; j < 9; ++j){
        cout << currState.at(j) << " ";
    }
    cout << endl << endl;
}
