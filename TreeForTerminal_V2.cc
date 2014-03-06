//Tree.cc for terminal V1
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    
    string item;
    TreeNode *left;
    TreeNode *right;
    TreeNode(string s) {
        item = s;
        left = NULL;
        right = NULL;
    }
};

int countNodes(TreeNode *node) {
    if (node == NULL)
        return 0; // Tree is empty, so it contains no nodes.
    
    else {
        // Add up the root node and the nodes in its two subtrees.
        int leftCount = countNodes( node->left );
        int rightCount = countNodes( node->right );
        return  1 + leftCount + rightCount;
    }
}

void addNode(TreeNode *&root, string item) {
    if (root == NULL)
        root = new TreeNode(item);
    else if (item < root->item )
        addNode(root->left, item);
    
    else
        addNode(root->right, item);
}

void printIn(TreeNode *&root) {
    if (root != NULL) {
        printIn(root->left);
        cout << root->item << " ";
        printIn(root->right);
    }
}

void printPre(TreeNode *&root) {
    if (root != NULL) {
        cout << root->item << ", ";
        printPre(root->left);
        printPre(root->right);
    }
}

void printPost(TreeNode *&root) {
    if (root != NULL) {
        printPost(root->left);
        printPost(root->right);
        cout << root->item << ", ";
    }
}

void storeCharArrays(char x[],char* l1, int starter, int ender) {
    int beeker = 0;
    while (starter < ender) {
        l1[beeker] = x[starter];
        starter++;
        beeker++;
    }
}

int main(int argc, char *argv[]) {
    
        char line1[27], line2[11], line3[27], line4[17], line5[11], line6[6];
        char line7[7], line8[8], line9[8], line10[7], line11[9], line12[9];
        char str[160];
    ifstream fileT (argv[1]);
    if (!fileT.is_open()) {
        cout << "Could not open file\n";
    }
    else {
        char c;
        int i=0;
        while (i < 160) {
            fileT.get(str[i]);
            i++;
        }
    }
    
    storeCharArrays(str,line1, 0,26);
    storeCharArrays(str,line2, 27, 37);
    storeCharArrays(str,line3, 38, 64);      //Passed One Line in at a time, because
    storeCharArrays(str,line4, 65, 82);      //2 or more lines created problems.
    storeCharArrays(str,line5, 83, 92);
    storeCharArrays(str,line6, 93,99);
    storeCharArrays(str,line7, 100,106);
    storeCharArrays(str,line8, 107,114);
    storeCharArrays(str,line9, 115, 122);
    storeCharArrays(str,line10, 123, 129);
    storeCharArrays(str,line11, 130, 139);
    storeCharArrays(str,line12, 140,149);
    
    for (int b = 0; b < sizeof(line1); b++)
        cout << line1[b];
    cout << endl;
    for (int b = 0; b < sizeof(line2); b++)
        cout << line2[b];
    cout << endl;
    for (int b = 0; b < sizeof(line3); b++)
        cout << line3[b];
    cout << endl;
    for (int b = 0; b < sizeof(line4); b++)
        cout << line4[b];
    cout << endl;
    for (int b = 0; b < sizeof(line5); b++)
        cout << line5[b];
    cout << endl;
     for (int b = 0; b < sizeof(line6); b++)
        cout << line6[b];
    cout << endl;
    for (int b = 0; b < sizeof(line7); b++)
        cout << line7[b];
    cout << endl;
    for (int b = 0; b < sizeof(line8); b++)
        cout << line8[b];
    cout << endl;
    for (int b = 0; b < sizeof(line9); b++)
        cout << line9[b];
    cout << endl;
    for (int b = 0; b < sizeof(line10); b++)
        cout << line10[b];
    cout << endl;
    for (int b = 0; b < sizeof(line11); b++)
        cout << line11[b];
    cout << endl;
    for (int b = 0; b < sizeof(line12); b++)
        cout << line12[b];
     
    
    cout << "<---Needs to Last Line. Line Below needs to be prompt.\n";
    
    
    return 0;
    
    TreeNode *root;
    root = NULL;
    
    while (true) {

        cout << ("\nEnter a string to be inserted, type 'print' to print tree, or press return to end.\n");
        string item;
        if (cin.peek() == '\n')
              break;
        cin >> item;
        cin.ignore(10000,'\n');
        if(item == "print") {
            printIn(root); cout << endl;
            if (countNodes(root) <= 1) {
                cout << "There is " << countNodes(root) << " node.\n";
                break;
            }
            else {
                cout << "There are " << countNodes(root) << " nodes.\n";
                break;
            }
        }
        addNode(root, item);
    }
    cout << "\n\nExiting program.\n\n";
}