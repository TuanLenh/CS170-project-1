#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> startState(9, 0);
    cout << "Please enter the puzzle with 0 is represents the blank tile" << endl;
    for(int i = 0; i < 9; ++i){
        int number = 0;
        cin >> number;
        startState.at(i) = number;
    }

    Tree currTree;
    currTree.insert(startState, currTree.root);
    currTree.moveBlankTile(currTree.root);
    currTree.moveBlankTile(currTree.root->firstChild);
    currTree.printRecordOfValue();

    //testing
    cout << endl << "Testing First Child Node with gScore: " << currTree.root->firstChild->getgScore() << endl;
    vector<int> goalState = currTree.root->firstChild->getData();
    for(int j = 0; j < 3; ++j){
        cout << goalState.at(j) << " ";
    }
    cout << endl;
    for(int j = 3; j < 6; ++j){
        cout << goalState.at(j) << " ";
    }
    cout << endl;
    for(int j = 6; j < 9; ++j){
        cout << goalState.at(j) << " ";
    }
    cout << endl << endl;

    cout << endl << "Testing Second Child Node with gScore: " << currTree.root->secondChild->getgScore() << endl;
    vector<int> goalState2 = currTree.root->secondChild->getData();
    for(int j = 0; j < 3; ++j){
        cout << goalState2.at(j) << " ";
    }
    cout << endl;
    for(int j = 3; j < 6; ++j){
        cout << goalState2.at(j) << " ";
    }
    cout << endl;
    for(int j = 6; j < 9; ++j){
        cout << goalState2.at(j) << " ";
    }
    cout << endl << endl;

    cout << endl << "Testing First Child of the First Child Node with gScore: " << currTree.root->firstChild->firstChild->getgScore() << endl;
    vector<int> goalState3 = currTree.root->firstChild->firstChild->getData();
    for(int j = 0; j < 3; ++j){
        cout << goalState3.at(j) << " ";
    }
    cout << endl;
    for(int j = 3; j < 6; ++j){
        cout << goalState3.at(j) << " ";
    }
    cout << endl;
    for(int j = 6; j < 9; ++j){
        cout << goalState3.at(j) << " ";
    }
    cout << endl << endl;

    cout << endl << "Testing Second Child of the First Child Node with gScore: " << currTree.root->firstChild->secondChild->getgScore() << endl;
    vector<int> goalState4 = currTree.root->firstChild->secondChild->getData();
    for(int j = 0; j < 3; ++j){
        cout << goalState4.at(j) << " ";
    }
    cout << endl;
    for(int j = 3; j < 6; ++j){
        cout << goalState4.at(j) << " ";
    }
    cout << endl;
    for(int j = 6; j < 9; ++j){
        cout << goalState4.at(j) << " ";
    }
    cout << endl << endl;

    return 0;
}