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


int main(int argc, char *argv[]) {
    
        ifstream fileT (argv[1]);
        if (argc == 1)
            goto NoFileLabel;
        if (!fileT.is_open()) {
            cout << "Could not open file\n";
            goto NoFileLabel;
        }
        else {
            
            char c;
            int i=0;
            char str[460];
            int x = 300;
            while (i < 300) {
                fileT.get(str[i]);
                i++;
            }
            for (int i = 0; i < 300; i++)
                cout << str[i];
        }
    
    cout << endl;
    return 0;
    
NoFileLabel:
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