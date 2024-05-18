#include <iostream>
#include <fstream>
#include<unordered_map>
#include <vector>
#include "../include/nodeStruct.hpp"
#include "../include/getFrequency.hpp"
using namespace std;


void heapify(vector<Node*> &entry){
    Node* temp;
    for(int i=entry.size()-1;i >= 0;i--){
        if(entry[i]->freq < entry[i/2]->freq){
            temp = entry[i];
            entry[i] = entry[i/2];
            entry[i/2] = temp;
        }
    }
}


vector<Node*> getMinHeap(unordered_map<char, int> entry) {
    vector<Node*> res;
    for (auto it = entry.begin(); it != entry.end(); ++it) {
        Node* item = new Node(it->first, it->second);
        res.push_back(item);
    }

    // Construct the initial min-heap
    heapify(res);

    return res;
}

void sort(Node* head) {
    Node* tmp = head;
    while(tmp!=nullptr && tmp->right!=nullptr){
        if(tmp->freq>tmp->right->freq){
            int tmpFreq = tmp->freq;
            int tmpElem = tmp->elem;
            tmp->freq = tmp->right->freq;
            tmp->elem = tmp->right->elem;
            tmp->right->freq = tmpFreq;
            tmp->right->elem = tmpElem;
        }
        tmp=tmp->right;
    }
}

// Node* getMinHeap(unordered_map<char, int> entry) {
//     Node* root=nullptr, *tmp=root;
//     for (auto it = entry.begin(); it != entry.end(); ++it) {
//         Node* item = new Node(it->first, it->second);
//         if(!root){
//             root = item;
//             tmp=root;
//         }
//         else{
//             tmp->right=item;
//             tmp = tmp->right;
//         }
//     }

//     // Construct the initial min-heap
//     //sort(root);

//     return root;
// }