#include "Node.h"
#include <vector>

using namespace std;

Node::Node(const vector<int>& state, int gScore, int hScore, Node* parent) : state(state), gScore(gScore), hScore(hScore), parent(parent){}
