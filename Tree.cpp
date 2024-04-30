#include "Tree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>

using namespace std;

Tree::Tree(const vector<int>& startState, const vector<int>& goalState) : startState(startState), goalState(goalState){}


void Tree::uniformCostSearch(){
    //inialize priority queue and unordered set
    priority_queue<Node*, vector<Node*>, CompareUCSNode> pq; 
    unordered_set<string> visited;

    //the puzzle is added to the queue
    pq.push(new Node(startState, 0, 0, nullptr));
    while(!pq.empty()){
        //the top node of the queue is removed; then it is compared with goal state
        Node* currentNode = pq.top();
        pq.pop();

        if(currentNode->state == goalState){
            printSolutionPath(currentNode);
            return;
        }

        //the state is then added the unordered_set visisted.
        //But first the state changes its type from int to string through the changeOfState function
    
        visited.insert(changeTypeOfState(currentNode->state));

        //nextStates is vector that store new expanded states
        vector<vector<int>> nextStates = generateNextStates(currentNode->state);
        
        //this loop loops through the vector nexStates and tranverse through the visited set
        //to find if the newstates are already in the set or not. If not, then the newstates are added to the queue
        for(const auto& nextState : nextStates){
            if(visited.find(changeTypeOfState(nextState)) == visited.end()){
                int updatedgScore = currentNode->gScore + 1;
                Node* nextNode = new Node(nextState, updatedgScore, 0, currentNode);
                pq.push(nextNode);
            }
        }
    }
    cout << "UwU, no solution" << endl;
}

//This function creates different states and add these states to a vector
vector<vector<int>> Tree::generateNextStates(const vector<int>& currentState){
    vector<vector<int>> newSetOfStates;
    
    // blank tile is at 0, 2 options
    if(currentState.at(0) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(0), tempState.at(1));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(0), tempState.at(3));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 1, 3 options
    if(currentState.at(1) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(1), tempState.at(0));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(1), tempState.at(2));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(1), tempState.at(4));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 2, 2 options
    if(currentState.at(2) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(2), tempState.at(1));
        newSetOfStates.push_back(tempState);
        
        tempState = currentState;
        swap(tempState.at(2), tempState.at(5));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 3, 3 options
    if(currentState.at(3) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(3), tempState.at(0));
        newSetOfStates.push_back(tempState);

        tempState = currentState;
        swap(tempState.at(3), tempState.at(4));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(3), tempState.at(6));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 4, 4 options
    if(currentState.at(4) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(4), tempState.at(1));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(4), tempState.at(3));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(4), tempState.at(5));
        newSetOfStates.push_back(tempState);

        tempState = currentState;
        swap(tempState.at(4), tempState.at(7));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 5, 3 options
    if(currentState.at(5) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(5), tempState.at(2));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(5), tempState.at(4));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(5), tempState.at(8));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 6, 2 options
    if(currentState.at(6) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(6), tempState.at(7));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(6), tempState.at(3));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 7, 3 options
    if(currentState.at(7) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(7), tempState.at(6));
        newSetOfStates.push_back(tempState);

        tempState = currentState;
        swap(tempState.at(7), tempState.at(8));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(7), tempState.at(4));
        newSetOfStates.push_back(tempState);
    }

    // blank tile is at 8, 2 options
    if(currentState.at(8) == 0){
        vector<int> tempState = currentState;
        swap(tempState.at(8), tempState.at(5));
        newSetOfStates.push_back(tempState);
    
        tempState = currentState;
        swap(tempState.at(8), tempState.at(7));
        newSetOfStates.push_back(tempState);
    }

    return newSetOfStates;
}

//This function changes the type of state from int to string so it can added to the visited set
string Tree::changeTypeOfState(const vector<int>& currentState){
    string newState;
    for(size_t i = 0; i < currentState.size(); ++i){
        newState = newState + to_string(currentState[i]);
    }
    return newState;
}

//This function print path and transver the node upward using parent node. 
//At every node, printState function is employed to print individually a node
void Tree::printSolutionPath(Node* currentNode){
    cout << "Solution Found! Printing path:" << endl;
    vector<Node*> path;
    while(currentNode != nullptr){
        path.push_back(currentNode);
        currentNode = currentNode->parent;
    }
    for(int i = path.size() - 1; i >= 0; --i){
        cout << "Step " << path.size() - i - 1 << ":" << endl;
        vector<int> currentState = path.at(i)->state;
        printState(currentState);
    }
}

//Print the state of a node
void Tree::printState(const vector<int>& state){
    for(int i = 0; i < 3; ++i){
        cout << state.at(i) << " ";
    }
    cout << endl;
    for(int i = 3; i < 6; ++i){
        cout << state.at(i) << " ";
    }
    cout << endl;
    for(int i = 6; i < 9; ++i){
        cout << state.at(i) << " ";
    }
    cout << endl << endl;
}


void Tree::misplacedTile(){
    //inialize priority queue and unordered set
    priority_queue<Node*, vector<Node*>, CompareAStarNode> pq;
    unordered_set<string> visited;

    //h score of the given puzzle is calculated
    int currenthScore = calcMisplacedTiles(startState);
    pq.push(new Node(startState, 0, currenthScore, nullptr));

    //the top node of the queue is removed; then it is compared with goal state
    while(!pq.empty()){
        Node* currentNode = pq.top();
        pq.pop();

        if(currentNode->state == goalState){
            printSolutionPath(currentNode);
            return;
        }

        //the state is then added the unordered_set visisted.
        //But first the state changes its type from int to string through the changeOfState function
        visited.insert(changeTypeOfState(currentNode->state));

        //nextStates is vector that store new expanded states
        vector<vector<int>> nextStates = generateNextStates(currentNode->state);

        //this loop loops through the vector nexStates and tranverse through the visited set
        //to find if the newstates are already in the set or not. If not, then the newstates are added to the queue
        for(const auto& nextState : nextStates){
            if(visited.find(changeTypeOfState(nextState)) == visited.end()){
                int nextCost = currentNode->gScore + 1;
                int currenthScore = calcMisplacedTiles(nextState);
                Node* nextNode = new Node(nextState, nextCost, currenthScore, currentNode);
                pq.push(nextNode);
            }
        }
    }
    cout << "UwU, no solution" << endl;
}

//This function just calculate the total of tiles that are not at the correct positions
int Tree::calcMisplacedTiles(const vector<int>& state){
    int totalMisplaced = 0;
    if(state.at(0)!= 1){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(1)!= 2){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(2)!= 3){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(3)!= 4){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(4)!= 5){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(5)!= 6){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(6)!= 7){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(7)!= 8){
        totalMisplaced = totalMisplaced + 1;
    }
    if(state.at(8)!= 0){
        totalMisplaced = totalMisplaced + 1;
    }
    return totalMisplaced;
}


void Tree::euclideanDistance(){
     //inialize priority queue and unordered set
    priority_queue<Node*, vector<Node*>, CompareAStarNode> pq;
    unordered_set<string> visited;

    //h score of the given puzzle is calculated
    int currenthScore = calcEuclideanDistance(startState);
    pq.push(new Node(startState, 0, currenthScore, nullptr));

    //the top node of the queue is removed; then it is compared with goal state
    while(!pq.empty()){
        Node* currentNode = pq.top();
        pq.pop();

        if(currentNode->state == goalState){
            printSolutionPath(currentNode);
            return;
        }

        //the state is then added the unordered_set visisted.
        //But first the state changes its type from int to string through the changeOfState function
        visited.insert(changeTypeOfState(currentNode->state));
        
        //nextStates is vector that store new expanded states
        vector<vector<int>> nextStates = generateNextStates(currentNode->state);

        //this loop loops through the vector nexStates and tranverse through the visited set
        //to find if the newstates are already in the set or not. If not, then the newstates are added to the queue
        for(const auto& nextState : nextStates){
            if(visited.find(changeTypeOfState(nextState)) == visited.end()){
                int nextCost = currentNode->gScore + 1;
                int currenthScore = calcEuclideanDistance(nextState);
                Node* nextNode = new Node(nextState, nextCost, currenthScore, currentNode);
                pq.push(nextNode);
            }
        }
    }
    cout << "UwU, no solution" << endl;
}

//this function calculate the direct distance of the tile to their correct positions.
//to find the direct distance, Pythagorean theorem is employed
int Tree::calcEuclideanDistance(const vector<int>& currentState){
    int totalDistance = 0;
    for(int i = 0; i < currentState.size(); ++i){
        if(currentState.at(i) != 0){
            int goalIndex = currentState[i] - 1;
            int diffOfRow = abs(i / 3 - goalIndex / 3);
            int diffOfCol = abs(i % 3 - goalIndex % 3);
            totalDistance = totalDistance + sqrt(diffOfRow * diffOfRow + diffOfCol * diffOfCol);
        }
    }
    return totalDistance;
}