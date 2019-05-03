#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    char a;
    Node(char a1):a(a1) {}
    };

void createTree(Node* root, vector<string> codes) {
    Node* root_ref = root;

    for(auto code: codes) {
        char* letter = strtok(strdup(code.c_str()), "\t");
        string lets(letter);
        //to accomodate for newline text
        if(lets == "newline") {
            *letter = '\n';
        }
        char* huf = strtok(NULL, "\t");
        string hufs(huf);
        for(auto i = hufs.begin(); i != hufs.end(); i++) {
            if(root == NULL) {
                break;
            }
                
            if(*i == '0') {
                if(root->left == NULL) {
                    root -> left = new Node('-');
                }
                root = root->left;
            } 
            else {
                if(root->right == NULL) {
                    root -> right = new Node('-');
                }
                root = root->right;
            }
            
            if(i == hufs.end() - 1) {
                root->a = *letter;
                root = root_ref;
            }
        }
    }

    
    return;
    }


int main()
{
Node* root = new Node('-');

string nn = "001011100";

std::vector<string> codes = {"A\t0", "B\t111", "C\t1100", "D\t1101", "R\t10"};
createTree(root, codes);
Node * root_ref = root;
vector<char> result;

for(auto i = nn.begin(); i != nn.end(); i++) {
    if(root == NULL) {
        break;
    }
        
    if(*i == '0') {
        root = root->left;
    } 
    else {
        root = root->right;
    }
    
    if(root->a != '-') {
        result.push_back(root->a);
        root = root_ref;
    }
    
}

for(int i = 0; i < result.size(); i++) {
    cout<<result[i];
}

  return 0;
}