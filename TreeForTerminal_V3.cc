//Tree.cc for terminal V1
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    char c;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char s) {
        c = s;
        left = NULL;
        right = NULL;
    }
};

void addNode(TreeNode *&root, char x) {
    if (root == NULL)
        root = new TreeNode(x);
    else if (x < root->c)
        addNode(root->left, x);
    
    else
        addNode(root->right, x);
}

void printIn(TreeNode *&root, bool b) {
    bool header = b;
    if (header) {
        cout << "Inorder:\t";
        header = false;
    }
    if (root != NULL) {
        printIn(root->left, header);
        cout << root->c;
        printIn(root->right, header);
    }
}

void printPre(TreeNode *&root, bool b) {
    bool header = b;
    if (header) {
        cout << "Preorder:\t";
        header = false;
    }
    if (root != NULL) {
        cout << root->c;
        printPre(root->left, header);
        printPre(root->right, header);
    }
}

void printPost(TreeNode *&root, bool b) {
    bool header = b;
    if (header) {
        cout << "Postorder:\t";
        header = false;
    }
    if (root != NULL) {
        printPost(root->left, header);
        printPost(root->right, header);
        cout << root->c;
    }
}

void execute(char p[], int size) {
    TreeNode *root;
    root = NULL;
    for (int i = 0; i<size; i++)
        addNode(root, p[i]);
    printPre(root, true);     cout << endl;
    printIn(root, true);      cout << endl;
    printPost(root, true);    cout << endl;
    cout << "\n\n\n";
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
    cout << "\n";
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
    
    execute(line1, sizeof(line1));
    execute(line2, sizeof(line2));
    execute(line3, sizeof(line3));
    execute(line4, sizeof(line4));
    execute(line5, sizeof(line5));
    execute(line6, sizeof(line6));
    execute(line7, sizeof(line7));
    execute(line8, sizeof(line8));
    execute(line9, sizeof(line9));
    execute(line10, sizeof(line10));
    execute(line11, sizeof(line11));
    execute(line12, sizeof(line12));
    
    cout << "Exiting program.\n\n";
}