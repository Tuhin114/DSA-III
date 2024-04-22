// Search In BST
// https://www.naukri.com/code360/problems/search-in-bst_1402878?leftPanelTabValue=PROBLEM

/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

/**
 bool searchInBST(BinaryTreeNode<int> *root, int x) {
    //Base case
    if(root == NULL){
        return false;
    }

    if(root -> data == x){
        return true;
    }

    if(root -> data > x){
        //Left part
        return searchInBST(root -> left, x);
    }else{
        //Right part
        return searchInBST(root -> right, x);
    }
}
*/

// Approach - 2
/**
 bool searchInBST(BinaryTreeNode<int> *root, int x) {

   BinaryTreeNode<int> *temp = root;

   while(temp != NULL){
       if(temp -> data == x){
           return  true;
       }
       if(temp -> data > x){
           temp = temp -> left;
       }else{
           temp = temp -> right;
       }
   }
   return false;
}
*/