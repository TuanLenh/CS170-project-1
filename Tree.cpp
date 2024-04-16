#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

Tree::Tree(){
    root = nullptr;
    recordOfState = {};
    goalState = {1,2,3,4,5,6,7,8,0};
}

// void Tree::printState(){
//     if(root == nullptr){
//         cout << "Nothing to print!" << endl;
//     }
//     else{
//         root->printState();
//     }
// }

void Tree::insert(vector<int>& newState){
    if(root == nullptr){
        recordOfState.push_back(newState);
        Node *newNode = new Node(newState);
        this->root = newNode;     
    }
    else{
        if(root->firstChild == nullptr){
            Node *newNode = new Node(newState);
            root->firstChild = newNode;
        }
    }
}

void Tree::moveBlankTile(Node* currNode){
    vector<int> currState = currNode->getData();
    if(currState.at(0) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(0), tempState.at(1));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(0) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(0), tempState.at(3));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 1, 3 op
    if(currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(0));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(2));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(4));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 2, 2 op
    if(currState.at(2) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(2), tempState.at(1));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(2) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(2), tempState.at(5));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 3, 3 op
    if(currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(0));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(4));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(6));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 4, 4 op
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(1));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(3));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(5));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(7));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 5, 3 op
    if(currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(2));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(4));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(8));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 6, 2 op
    if(currState.at(6) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(6), tempState.at(7));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(6) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(6), tempState.at(3));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 7, 3 op
    if(currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(6));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(8));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(4));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }

    // blank tile is at 8, 2 op
    if(currState.at(8) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(8), tempState.at(5));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
    if (currState.at(8) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(8), tempState.at(7));
        if(!duplicatedState(tempState)){
            cout << "Added new state successfully!" << endl;
        }
    }
}

bool Tree::duplicatedState(vector<int>& tempState){
    for(int i = 0; i < recordOfState.size(); ++i){
        if(recordOfState.at(i) == tempState){
            return true;
        }
    }
    recordOfState.push_back(tempState);

    return false;
}

void Tree::printRecordOfState() const{
    for(int i = 0; i < recordOfState.size(); ++i){
        for(int j = 0; j < 3; ++j){
            cout << recordOfState[i][j] << " ";
        }
        cout << endl;
        for(int j = 3; j < 6; ++j){
            cout << recordOfState[i][j] << " ";
        }
        cout << endl;
        for(int j = 6; j < 9; ++j){
            cout << recordOfState[i][j] << " ";
        }
        cout << endl << endl;
    }
}

bool Tree::goalStateCheck(vector<int>& currState){
    if(currState == goalState){
        return true;
    }
    return false;
}