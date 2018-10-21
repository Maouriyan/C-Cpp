/* program to construct tree using inorder and preorder traversals */
#include <stdio.h> 
#include <stdlib.h> 
int row=0,col=0;i=0;
int lis[10];
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node { 
	char data; 
	struct node* left; 
	struct node* right; 
}; 

void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
  
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL){ 
        //printf("0 ");
        lis[++i]='0';
        return; }
    if (level == 1){ 
        //printf("%c ", root->data); 
        lis[++i]=root->data;}
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
  
/* Compute the "height" of a tree -- the number of 
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 
/* Prototypes for utility functions */
int search(char arr[], int strt, int end, char value); 
struct node* newNode(char data); 

/* Recursive function to construct binary of size len from 
Inorder traversal in[] and Preorder traversal pre[]. Initial values 
of inStrt and inEnd should be 0 and len -1. The function doesn't 
do any error checking for cases where inorder and preorder 
do not form a tree */
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd) 
{ 
	static int preIndex = 0; 

	if (inStrt > inEnd) 
		return NULL; 

	/* Pick current node from Preorder traversal using preIndex 
	and increment preIndex */
	struct node* tNode = newNode(pre[preIndex++]); 

	/* If this node has no children then return */
	if (inStrt == inEnd) 
		return tNode; 

	/* Else find the index of this node in Inorder traversal */
	int inIndex = search(in, inStrt, inEnd, tNode->data); 

	/* Using index in Inorder traversal, construct left and 
	right subtress */
	
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd); 
    
	return tNode; 
} 

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end] 
The function assumes that value is present in in[] */
int search(char arr[], int strt, int end, char value) 
{ 
	int i; 
	for (i = strt; i <= end; i++) { 
		if (arr[i] == value) 
			return i; 
	} 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(char data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 

/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	/* first recur on left child */
	printInorder(node->left); 
	

	/* then print the data of node */
	//printf("%c ", node->data); 

	/* now recur on right child */
	printInorder(node->right); 
} 

/* Driver program to test above functions */
int main() 
{ 
	char in[] = { 'A', 'C', 'B','D'}; 
	char pre[] = { 'A', 'B', 'C','D'}; 
	int len = sizeof(in) / sizeof(in[0]); 
	struct node* root = buildTree(in, pre, 0, len - 1); 

	/* Let us test the built tree by printing Insorder traversal */
	
	printLevelOrder(root); 
	for(i=0;i<10;i++){
	    printf("%c ",lis[i]);
	}
	getchar(); 
} 
