#include<iostream>
#include<fstream>
#include "../include/nodeStruct.hpp"
#include "../include/getBinary.hpp"
using namespace std;

void makeBinaryFile(Node* tree, string fileName, string outputName){
    ifstream inputFile(fileName);
    ofstream outputFile(outputName);
    string sentence;
    while(getline(inputFile, sentence)){
        for(int i=0; i<sentence.length(); i++){
            outputFile << getBinary(tree, sentence[i]);
        }
        outputFile << "\n";
    }
}