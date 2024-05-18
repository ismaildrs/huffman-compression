#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <cstring>
#include "../include/getFrequency.hpp"
#include "../include/getHuffmanTree.hpp"
#include "../include/getMinHeap.hpp"
#include "../include/getBinary.hpp"
#include "../include/makeBinaryFile.hpp"
#include "../include/makeTextFile.hpp"

using namespace std;

void showTree(Node* tree){
    if (!tree) return;
    cout << tree->elem << " : " << tree->freq << endl;
    showTree(tree->left);
    showTree(tree->right);
}

void showMinHeap(vector<Node*> entry){
    for (int i = 0; i < entry.size(); i++) {
        cout << entry[i]->elem << " - " << entry[i]->freq << endl;
    }
}

void serialize(Node* root, ofstream& out) {
    if (root == nullptr) {
        out << "#,";
        return;
    }
    out << root->elem << "," << root->freq << ",";
    serialize(root->left, out);
    serialize(root->right, out);
}

Node* deserialize(ifstream& in) {
    string val;
    getline(in, val, ',');
    if (val == "#") {
        return nullptr;
    }

    char elem = val[0];
    getline(in, val, ','); // Read the frequency as a string
    int freq = stoi(val); // Convert the frequency to an integer

    Node* node = new Node(elem, freq);
    node->left = deserialize(in);
    node->right = deserialize(in);
    return node;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Choose either -z to compress the file, or -uz to uncompress a file, -h to get the manual" << endl;
        return 1;
    }

    if (strcmp(argv[1], "-z") == 0) {
        if (argc != 4) {
            cerr << "Usage: ./zip -z <inputfile> <outputfile>" << endl;
            return 1;
        }
        ofstream serializeTree("serialization.txt");
        if (!serializeTree.is_open()) {
            cerr << "Failed to open serialization file for writing" << endl;
            return 1;
        }
        unordered_map<char, int> frequency_map = getFrequency(argv[2]);
        vector<Node*> res_vect = getMinHeap(frequency_map);
        Node* res = getHuffmanTree(res_vect);
        serialize(res, serializeTree);
        serializeTree.close();
        makeBinaryFile(res, argv[2], strcat(argv[3], ".o"));
    } 
    else if (strcmp(argv[1], "-uz") == 0) {
        if (argc != 5) {
            cerr << "Usage: ./zip -uz <treefile> <binaryfile> <outputfile>" << endl;
            return 1;
        }
        ifstream deserializeTree(argv[2]);
        if (!deserializeTree.is_open()) {
            cerr << "Failed to open serialization file for reading" << endl;
            return 1;
        }
        Node* huffmanTree = deserialize(deserializeTree);
        deserializeTree.close();
        makeTextFile(huffmanTree, argv[3], argv[4]);
    } 
    else if (strcmp(argv[1], "-h") == 0) {
        cout << "./zip -z <inputfile> <outputfile>" << endl;
        cout << "./zip -uz <treefile> <binaryfile> <outputfile>" << endl;
    } 
    else {
        cerr << "Invalid choice, use -h option to see possible commands" << endl;
        return 1;
    }

    return 0;
}
