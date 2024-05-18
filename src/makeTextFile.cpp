#include<iostream>
#include<fstream>
#include "../include/makeTextFile.hpp"
using namespace std;

char getChar(Node* tree, string entry) {
    Node* tmp = tree;
    int i = 0;
    if (!tree) return '$'; // Return '$' if the tree is empty
    while ((tmp->right != nullptr || tmp->left != nullptr) && i < entry.length()) {
        if (entry[i] == '1') // Check if the character at position 'i' is '1'
            tmp = tmp->right;
        else
            tmp = tmp->left;
        i++;
    }
    if (tmp->right == nullptr && tmp->left == nullptr) // Check if the current node is a leaf node
        return tmp->elem;
    return '$'; // Return '$' if no character is found for the given binary code
}


void makeTextFile(Node* tree, string fileName, string outputName){
    ifstream inputFile(fileName);
    ofstream outputFile(outputName);
    string line, code="";
    while(getline(inputFile, line)){
        for(int i=0; i<line.length(); i++){
            code += line[i];
            if(getChar(tree, code) != '$'){
                outputFile << getChar(tree, code);
                code = "";
            }
        }
        outputFile << "\n";
    }
}