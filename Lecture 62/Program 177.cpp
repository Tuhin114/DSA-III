// Count Leaf Nodes
// https://www.naukri.com/code360/problems/count-leaf-nodes_893055?source=youtube&campaign=LoveBabbar_Codestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=LoveBabbar_Codestudio&leftPanelTabValue=PROBLEM

/**
 void inorder(BinaryTreeNode<int> *root, int &count)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left,  count);

    //Leaf node
    if(root -> left == NULL && root -> right == NULL){
      count++;
    }

    inorder(root->right,  count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
  int count = 0;
  inorder(root, count);
  return count;
}
*/