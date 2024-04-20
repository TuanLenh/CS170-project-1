#include "Node.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Node::Node(){
    currValue = {};
    gScore = 0;
    parentNode = nullptr;
    firstChild = nullptr;
    secondChild = nullptr;
    thirdChild = nullptr;
    fourthChild = nullptr;
}

Node::Node(vector<int> newValue){
    currValue = newValue;
    gScore = 0;
    parentNode = nullptr;
    firstChild = nullptr;
    secondChild = nullptr;
    thirdChild = nullptr;
    fourthChild = nullptr;
}

vector<int> Node::getData() const{
    return currValue;
}

void Node::setData(const vector<int>& newValue){
    currValue = newValue;
}

void Node::setgScore(int updatedgScore){
    gScore = updatedgScore;
}

int Node::getgScore() const{
    return gScore;
}