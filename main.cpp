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
    currTree.insert(startState);
    currTree.moveBlankTile(currTree.root);
    currTree.printRecordOfState();


    return 0;
}