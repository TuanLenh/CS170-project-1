#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CompareUCSNode{
    bool operator()(const Node* node1, const Node* node2) const{
        return node1->gScore > node2->gScore;
    }
};

struct CompareAStarNode{
    bool operator()(const Node* node1, const Node* node2) const{
        return (node1->gScore + node1->hScore) > (node2->gScore + node2->hScore);
    }
};

class Tree{
    public:
    vector<int> startState;
    vector<int> goalState;

    Tree(const vector<int>& startState, const vector<int>& goalState);

    vector<vector<int>> generateNextStates(const vector<int>& currentState);
    string changeTypeOfState(const vector<int>& state);

    void printSolutionPath(Node* node);
    void printState(const vector<int>& state);

    void uniformCostSearch();

    void misplacedTile();
    int calcMisplacedTiles(const vector<int>& state);

    void euclideanDistance();
    int calcEuclideanDistance(const vector<int>& state);
};

#endif 
