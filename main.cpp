#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <memory>

using namespace std;

// Define the Node class representing each state of the puzzle
class Node {
public:
    vector<int> state; // Configuration of the puzzle
    int cost; // Cost to reach this node from the initial state
    Node* parent; // Pointer to the parent node

    Node(const vector<int>& state, int cost, Node* parent) : state(state), cost(cost), parent(parent) {}
};

// Define custom comparator for priority queue
struct CompareNode {
    bool operator()(const Node* n1, const Node* n2) const {
        return n1->cost > n2->cost; // Priority based on cost
    }
};

// Define the Tree class implementing Uniform-Cost Search
class Tree {
public:
    vector<int> initialState;
    vector<int> goalState;

    Tree(const vector<int>& initial, const vector<int>& goal) : initialState(initial), goalState(goal) {}

    // Uniform-Cost Search algorithm
    void uniformCostSearch() {
        priority_queue<Node*, vector<Node*>, CompareNode> pq; // Priority queue for frontier
        unordered_set<string> visited; // Set to keep track of visited states

        pq.push(new Node(initialState, 0, nullptr)); // Push initial state with cost 0 and no parent

        while (!pq.empty()) {
            Node* current = pq.top();
            pq.pop();

            // Check if current state is goal state
            if (current->state == goalState) {
                cout << "Solution Found! Printing path:" << endl;
                printSolutionPath(current);
                clearMemory(pq); // Clear memory before exiting
                return;
            }

            // Mark current state as visited
            visited.insert(serializeState(current->state));

            // Generate possible next states
            vector<vector<int>> nextStates = generateNextStates(current->state);

            // Explore each possible next state
            for (const auto& nextState : nextStates) {
                // Check if the state is visited, if not, add it to the priority queue
                if (visited.find(serializeState(nextState)) == visited.end()) {
                    // Calculate cost for the next state (for now, uniform cost, so just increase by 1)
                    int nextCost = current->cost + 1;
                    Node* nextNode = new Node(nextState, nextCost, current); // Set parent as the current node
                    pq.push(nextNode);
                }
            }
        }

        cout << "Solution Not Found!" << endl;
    }

    // Function to generate possible next states from the current state
    vector<vector<int>> generateNextStates(const vector<int>& currentState) {
        vector<vector<int>> newSetOfStates;
        int blankPosition = -1;

        // Find the position of the blank tile
        for (int i = 0; i < currentState.size(); ++i) {
            if (currentState[i] == 0) {
                blankPosition = i;
                break;
            }
        }

        // Define possible moves
        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        // Generate next states by swapping the blank tile with its neighbors
        for (const auto& move : moves) {
            int newX = blankPosition / 3 + move.first;
            int newY = blankPosition % 3 + move.second;

            // Check if the new position is within the puzzle boundaries
            if (newX >= 0 && newX < 3 && newY >= 0 && newY < 3) {
                vector<int> nextState = currentState;
                int newPosition = newX * 3 + newY;

                swap(nextState[blankPosition], nextState[newPosition]);
                newSetOfStates.push_back(nextState);
            }
        }

        return newSetOfStates;
    }

    // Function to serialize the state into a string for hashing
    string serializeState(const vector<int>& state) {
        string serializedState = "";
        for (int tile : state) {
            serializedState += to_string(tile);
        }
        return serializedState;
    }

    // Function to print the solution path
    void printSolutionPath(Node* node) {
        vector<Node*> path;
        while (node != nullptr) {
            path.push_back(node);
            node = node->parent;
        }

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << "Step " << path.size() - i - 1 << ":" << endl;
            printState(path[i]->state);
        }
    }

    // Function to print a state
    void printState(const vector<int>& state) {
        for (int i = 0; i < state.size(); ++i) {
            cout << state[i] << " ";
            if ((i + 1) % 3 == 0)
                cout << endl;
        }
        cout << endl;
    }

    // Function to clear memory
    void clearMemory(priority_queue<Node*, vector<Node*>, CompareNode>& pq) {
        while (!pq.empty()) {
            delete pq.top();
            pq.pop();
        }
    }
};

int main() {
    vector<int> initial = {0, 1, 2, 3, 4, 5, 6, 7, 8}; // Example initial state
    vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0}; // Example goal state

    Tree puzzle(initial, goal);
    puzzle.uniformCostSearch();

    return 0;
}
