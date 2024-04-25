// CodeStudio - LCA of Two Nodes In A BST
//  https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0

/**
 TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    //Base case
    if(root == NULL){
        return NULL;
    }

    if(root -> data < P -> data && root -> data < Q -> data){
        return LCAinaBST(root -> right, P, Q);
    }

    if(root -> data > P -> data && root -> data > Q -> data){
        return LCAinaBST(root -> left, P, Q);
    }

    return root;
}
*/