#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/getHuffmanTree.hpp"
#include "../include/getMinHeap.hpp"
#include "../include/nodeStruct.hpp"
using namespace std;

Node* getHuffmanTree(vector<Node*> entry){
    vector<Node*> res = entry;
    while(res.size()!=1){
        Node* item = new Node(res[0]->freq+res[1]->freq, res[0], res[1]);
        res.push_back(item);
        res.erase(res.begin(), res.begin() + 2);
        heapify(res);
    }
    return res[0];
}

// Function to insert a node in a sorted linked list based on frequency
void insertEnd(Node*& list, Node* item) {
    if (!list || list->freq > item->freq) {
        item->right = list;
        if (list) list->left = item;
        list = item;
        return;
    }
    Node* tmp = list;
    while (tmp->right && tmp->right->freq <= item->freq) {
        tmp = tmp->right;
    }
    item->right = tmp->right;
    if (tmp->right) tmp->right->left = item;
    tmp->right = item;
    item->left = tmp;
}

// Function to build the Huffman Tree
Node* getHuffmanTree(Node* entry) {
    Node* tmp = entry;
    while (tmp != nullptr && tmp->right != nullptr) {
        // Create a new internal node with the sum of the frequencies of the first two nodes
        Node* leftNode = tmp;
        Node* rightNode = tmp->right;
        Node* item = new Node(leftNode->freq + rightNode->freq, leftNode, rightNode);

        // Update the list to exclude the first two nodes
        tmp = rightNode->right;
        if (tmp) {
            tmp->left = nullptr;
        }

        // Insert the new node into the list
        insertEnd(tmp, item);
    }
    
    return tmp; // The root of the Huffman Tree
}