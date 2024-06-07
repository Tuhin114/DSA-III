// Merge Two BSTs
// https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&nps=true&leftPanelTabValue=PROBLEM

// Approach - 1
/**
 vector<int> mergeArr(vector<int> a, vector<int> b){
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

void inorder(TreeNode *root, vector<int> &arr){
    if(root == NULL)    return;

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step 1 : store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergeArray = mergeArr(bst1, bst2);

    return mergeArray;
}
 */

// Approach - 2
/**
 #ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Function to convert BST to Sorted Doubly Linked List
void convertIntoSortedDLL(TreeNode *root, TreeNode *&head) {
    // Base case
    if (root == NULL) {
        return;
    }

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

// Function to merge two sorted doubly linked lists
TreeNode* mergeLL(TreeNode *head1, TreeNode *head2) {
    TreeNode *head = NULL;
    TreeNode *tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

// Function to count nodes in the doubly linked list
int countNodes(TreeNode *head) {
    int cnt = 0;
    TreeNode *temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// Function to convert sorted doubly linked list to BST
TreeNode* sortedLLToBST(TreeNode *&head, int n) {
    // Base case
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    TreeNode *left = sortedLLToBST(head, n / 2);

    TreeNode *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}

// Helper function to perform in-order traversal and collect elements in a vector
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

// Function to convert BST to vector
vector<int> bstToVector(TreeNode* root) {
    vector<int> result;
    inorderTraversal(root, result);
    return result;
}

// Function to merge two BSTs and return the result as a sorted vector
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Step 1: Convert BST to Sorted DLL in-place
    TreeNode *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    if (head1 != NULL) head1->left = NULL;

    TreeNode *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    if (head2 != NULL) head2->left = NULL;

    // Step 2: Merge sorted DLL
    TreeNode *head = mergeLL(head1, head2);

    // Step 3: Convert Sorted DLL into BST
    TreeNode *node = sortedLLToBST(head, countNodes(head));

    // Step 4: Convert BST to vector arr
    return bstToVector(node);
}

#endif // SOLUTION_H

 */