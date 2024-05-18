#include<fstream>
#include <iostream>
#include<unordered_map>
#include "../include/getFrequency.hpp"
using namespace std;

unordered_map<char, int> getFrequency(string fileName){
    ifstream inputFile(fileName);

    unordered_map<char, int> res;

    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
    } 

    string line;

    while (getline(inputFile, line)) { 
        for(int i=0;i<line.size();i++){
            res[line[i]]++;
        }
    } 
  
    inputFile.close();

    return res;
}
