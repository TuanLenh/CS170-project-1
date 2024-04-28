#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class Node{
    public:
    vector<int> state;
    int gScore;
    int hScore;
    Node* parent;

    Node(const vector<int>& state, int gScore, int hScore, Node* parent);
};
#endif