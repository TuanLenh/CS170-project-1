#include "Tree.h"
#include <iostream>
#include <string>

using namespace std;

Tree::Tree(){
    root = nullptr;
    recordOfValue = {};
    goalState = {1,2,3,4,5,6,7,8,0};
}

void Tree::insert(vector<int>& newValue, Node * parentNodeToExpand){
    if(parentNodeToExpand == nullptr){
        recordOfValue.push_back(newValue);
        Node *newNode = new Node(newValue);
        this->root = newNode;     
    }
    else{
        if(parentNodeToExpand->firstChild == nullptr){
            Node *newNode = new Node(newValue);
            parentNodeToExpand->firstChild = newNode;
            newNode->parentNode = parentNodeToExpand;
            newNode->setgScore(findgScoreOfNode(newNode));
        }
        else if(parentNodeToExpand->secondChild == nullptr){
            Node *newNode = new Node(newValue);
            parentNodeToExpand->secondChild = newNode;
            newNode->parentNode = parentNodeToExpand;
            newNode->setgScore(findgScoreOfNode(newNode));
        }
        else if(parentNodeToExpand->thirdChild == nullptr){
            Node *newNode = new Node(newValue);
            parentNodeToExpand->thirdChild = newNode;
            newNode->parentNode = parentNodeToExpand;
            newNode->setgScore(findgScoreOfNode(newNode));
        }
        else if(parentNodeToExpand->fourthChild == nullptr){
            Node *newNode = new Node(newValue);
            parentNodeToExpand->fourthChild = newNode;
            newNode->parentNode = parentNodeToExpand;
            newNode->setgScore(findgScoreOfNode(newNode));
        }
    }
}

int Tree::findgScoreOfNode(Node* currNode){
    int i = 0;
    Node * tranverseNode = currNode;
    while(tranverseNode->parentNode != nullptr){
        tranverseNode = tranverseNode->parentNode;
        ++i;
    }

    return i;
}



void Tree::moveBlankTile(Node* currNode){
    vector<int> currState = currNode->getData();
    if(currState.at(0) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(0), tempState.at(1));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(0) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(0), tempState.at(3));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 1, 3 op
    if(currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(0));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(2));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(1) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(1), tempState.at(4));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 2, 2 op
    if(currState.at(2) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(2), tempState.at(1));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(2) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(2), tempState.at(5));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 3, 3 op
    if(currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(0));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(4));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(3) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(3), tempState.at(6));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 4, 4 op
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(1));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(3));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(5));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if(currState.at(4) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(4), tempState.at(7));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 5, 3 op
    if(currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(2));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(4));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(5) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(5), tempState.at(8));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 6, 2 op
    if(currState.at(6) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(6), tempState.at(7));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(6) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(6), tempState.at(3));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 7, 3 op
    if(currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(6));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(8));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(7) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(7), tempState.at(4));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }

    // blank tile is at 8, 2 op
    if(currState.at(8) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(8), tempState.at(5));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
    if (currState.at(8) == 0){
        vector<int> tempState = currState;
        swap(tempState.at(8), tempState.at(7));
        if(!duplicatedState(tempState)){
            this->insert(tempState, currNode);
        }
    }
}

bool Tree::duplicatedState(vector<int>& tempState){
    for(int i = 0; i < recordOfValue.size(); ++i){
        if(recordOfValue.at(i) == tempState){
            return true;
        }
    }
    recordOfValue.push_back(tempState);

    return false;
}

void Tree::printRecordOfValue() const{
    cout << endl << "Below are all the value we have so far:" << endl;
    for(int i = 0; i < recordOfValue.size(); ++i){
        for(int j = 0; j < 3; ++j){
            cout << recordOfValue[i][j] << " ";
        }
        cout << endl;
        for(int j = 3; j < 6; ++j){
            cout << recordOfValue[i][j] << " ";
        }
        cout << endl;
        for(int j = 6; j < 9; ++j){
            cout << recordOfValue[i][j] << " ";
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
