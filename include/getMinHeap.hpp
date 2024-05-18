#pragma once
#include <iostream>
#include <fstream>
#include<unordered_map>
#include<vector>
#include "nodeStruct.hpp"
using namespace std;

void heapify(vector<Node*>&);

vector<Node*> getMinHeap(unordered_map<char, int>);


void sort(Node*);

//
// Node* getMinHeap(unordered_map<char, int>);
