#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int counter = 0;
    vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    vector<int> startState(9, 0);
    cout << "Please enter the puzzle with 0 is represents the blank tile" << endl;
    for(int i = 0; i < 9; ++i){
        int number = 0;
        cin >> number;
        startState.at(i) = number;
    }

    cout << endl << endl;
    Tree currTree;
    currTree.insert(startState, currTree.root);

    while(counter == 0){
        if(currTree.findSmallestDepthLeaf(currTree.root)->getData() == goalState){
            cout << "Sucessfully found goal state!" << endl;
            return 0;
        }
        else{
            vector<int> tempGoalState = currTree.findSmallestDepthLeaf(currTree.root)->getData();
            for(int j = 0; j < 3; ++j){
                cout << tempGoalState.at(j) << " ";
            }
            cout << endl;
            for(int j = 3; j < 6; ++j){
                cout << tempGoalState.at(j) << " ";
            }
            cout << endl;
            for(int j = 6; j < 9; ++j){
                cout << tempGoalState.at(j) << " ";
            }
            cout << endl << endl;
            currTree.moveBlankTile(currTree.findSmallestDepthLeaf(currTree.root));
        }
    }

    // test
    // vector<int> testingState = {3,1,2,7,6,5,4,8,0};
    // if(currTree.duplicatedState(testingState)){
    //     cout << "Already in the Record" << endl;
    // }
    // else{
    //     cout << "Not in the Record" << endl;
    // }
    

    // //Previous Testing
    // //testing start
    // cout << "Testing findSmallestDepthLeaf when root is first added. Expect Success " << endl;
    // if(currTree.root == currTree.findSmallestDepthLeaf(currTree.root)){
    //     cout << "Success";
    // }
    // else{
    //     cout << "Fail";
    // }
    // cout << endl << endl;


    // currTree.moveBlankTile(currTree.root);

    // //testing start
    // cout << "Testing findSmallestDepthLeaf after expanding root node. Expect Success " << endl;
    // if(currTree.root->firstChild == currTree.findSmallestDepthLeaf(currTree.root)){
    //     cout << "Success";
    // }
    // else{
    //     cout << "Fail";
    // }
    // cout << endl << endl;

    // cout << "Testing findSmallestDepthLeaf after expanding root node. Expect Failure " << endl;
    // if(currTree.root->thirdChild == currTree.findSmallestDepthLeaf(currTree.root)){
    //     cout << "Success";
    // }
    // else{
    //     cout << "Fail";
    // }
    // cout << endl << endl;
    // //testing end


    // currTree.moveBlankTile(currTree.root->firstChild);


    // //testing start
    // cout << "Testing findSmallestDepthLeaf after expanding the first firstChild node. Expect Failure " << endl;
    // if(currTree.root->firstChild->firstChild == currTree.findSmallestDepthLeaf(currTree.root)){
    //     cout << "Success";
    // }
    // else{
    //     cout << "Fail";
    // }
    // cout << endl << endl;

    // cout << "Testing findSmallestDepthLeaf after expanding the first firstChild node. Expect Success " << endl;
    // if(currTree.root->secondChild == currTree.findSmallestDepthLeaf(currTree.root)){
    //     cout << "Success";
    // }
    // else{
    //     cout << "Fail";
    // }
    // cout << endl << endl;
    // //testing end


    // currTree.printRecordOfValue();


    // //testing start
    // cout << "Testing Value of Node and its gScore: " << endl;
    // cout << endl << "Testing First Child Node with gScore: " << currTree.root->firstChild->getgScore() << endl;
    // vector<int> goalState = currTree.root->firstChild->getData();
    // for(int j = 0; j < 3; ++j){
    //     cout << goalState.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 3; j < 6; ++j){
    //     cout << goalState.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 6; j < 9; ++j){
    //     cout << goalState.at(j) << " ";
    // }
    // cout << endl << endl;

    // cout << endl << "Testing Second Child Node with gScore: " << currTree.root->secondChild->getgScore() << endl;
    // vector<int> goalState2 = currTree.root->secondChild->getData();
    // for(int j = 0; j < 3; ++j){
    //     cout << goalState2.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 3; j < 6; ++j){
    //     cout << goalState2.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 6; j < 9; ++j){
    //     cout << goalState2.at(j) << " ";
    // }
    // cout << endl << endl;

    // cout << endl << "Testing First Child of the First Child Node with gScore: " << currTree.root->firstChild->firstChild->getgScore() << endl;
    // vector<int> goalState3 = currTree.root->firstChild->firstChild->getData();
    // for(int j = 0; j < 3; ++j){
    //     cout << goalState3.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 3; j < 6; ++j){
    //     cout << goalState3.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 6; j < 9; ++j){
    //     cout << goalState3.at(j) << " ";
    // }
    // cout << endl << endl;

    // cout << endl << "Testing Second Child of the First Child Node with gScore: " << currTree.root->firstChild->secondChild->getgScore() << endl;
    // vector<int> goalState4 = currTree.root->firstChild->secondChild->getData();
    // for(int j = 0; j < 3; ++j){
    //     cout << goalState4.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 3; j < 6; ++j){
    //     cout << goalState4.at(j) << " ";
    // }
    // cout << endl;
    // for(int j = 6; j < 9; ++j){
    //     cout << goalState4.at(j) << " ";
    // }
    // cout << endl << endl;

    // return 0;
    // //testing end
}