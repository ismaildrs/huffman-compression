#include<iostream>
#include "../include/getBinary.hpp"
using namespace std;


string getBinary(Node* tree, char entry, string path) {
    if (!tree) 
        return ""; // Return empty string if tree is empty
    if (tree->elem == entry) 
        return path; // Return the accumulated path if the entry is found
    string rightPath = getBinary(tree->right, entry, path + "1"); // Traverse right subtree
    if (!rightPath.empty()) 
        return rightPath; // Return the path if found in the right subtree
    string leftPath = getBinary(tree->left, entry, path + "0"); // Traverse left subtree
    return leftPath; // Return the path found in the left subtree, could be an empty string if not found
}
