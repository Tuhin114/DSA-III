// Lowest Common Ancestor in a Binary Tree
// https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = right = NULL;
    }
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        // Base case
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == n1 || root->data == n2)
        {
            return root;
        }

        Node *leftAns = lca(root->left, n1, n2);
        Node *rightAns = lca(root->right, n1, n2);

        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return NULL;
        }
    }
};
