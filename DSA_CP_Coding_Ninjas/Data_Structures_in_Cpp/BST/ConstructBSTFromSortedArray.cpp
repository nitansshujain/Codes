Code: Construct BST from a Sorted Array
Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.Note : If array size is even, take first mid as root.
Sample Input :
7
1 2 3 4 5 6 7
Sample Output :
4 2 1 3 6 5 7


/************************************************************ SOLUTION ******************************************************************/


SOLUTION:
BinaryTreeNode<int> *tree(int *input, int start, int end){
    if(start > end){    //base case
        return NULL;
    }
    int mid = (start + end) / 2;    //mid of array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);    //assign mid as root
    root -> left = tree(input, start, mid - 1);    // call to left
    root -> right = tree(input, mid + 1, end);    // call to right
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    int start = 0;    //start of array
    int end = n - 1;    //end of array
    tree(input, start, end);
}
