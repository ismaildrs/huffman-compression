#pragma once

struct Node{
    char elem; //char
    int freq; //frequency
    Node* right;
    Node* left;
    Node(int num, Node* lf=nullptr, Node* rg=nullptr):elem('$'), freq(num), left(lf), right(rg){};
    Node(char eChar, int num): elem(eChar), freq(num), right(nullptr), left(nullptr){};
};