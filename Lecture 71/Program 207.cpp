// CodeStudio -  Normal BST To Balanced BST
//  https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0&leftPanelTabValue=PROBLEM

/**
 void inorder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return ;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &in){
    //Base case
    if(s > e){
        return NULL;
    }

    int mid = (s + e)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);


    root -> left = inorderToBST(s, mid - 1, in);
    root -> right = inorderToBST(mid + 1, e, in);

    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
}
*/