#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> startState(9, 0);
    cout << "Please enter the puzzle with 0 isthe blank tile" << endl;
    for(int i = 0; i < 9; ++i){
        int number = 0;
        cin >> number;
        startState.at(i) = number;
    }
    vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    Tree puzzle(startState, goalState);
    cout << "Enter your choice of algorithm" << endl;
    cout << "1. Uniform Cost Search" << endl;
    cout << "2. A* with Misplaced Tile Heuristic" << endl;
    cout << "3. A* with Euclidean Distance Heuristic" << endl;
    int choice;
    cin >> choice;

    if(choice == 1){
        puzzle.uniformCostSearch();
    }
    else if(choice == 2){
        puzzle.misplacedTile();
    }
    else if(choice == 3){
        puzzle.euclideanDistance();
    }
    else{
        cout << "UwU, invalid choice" << endl;
    }
    return 0;
}