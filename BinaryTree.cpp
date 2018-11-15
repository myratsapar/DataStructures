#include <stdio.h>

#include <stdlib.h>



struct treeNode{

	int data;

	

	treeNode *left;

	treeNode *right;

};



typedef struct treeNode TreeNode;
typedef struct treeNode *TreeNodePointer;




void insertTreeNode(TreeNode** treeNode, int data){

	if (*treeNode == NULL){
		*treeNode  = (struct treeNode*)malloc(sizeof(struct treeNode));
		if (*treeNode != NULL){
			(*treeNode) -> left = NULL;
			(*treeNode) -> right = NULL;
			(*treeNode)-> data = data;
		}
		else{
			printf("There is no memory\n");
			exit(EXIT_FAILURE);
		}
	}

	else{
		if (data< (*treeNode)-> data){
		insertTreeNode(&((*treeNode) -> left), data);
		}
		else if (data > (*treeNode)-> data){
		insertTreeNode(&((*treeNode) -> right), data);
		}
		else {
			printf("Duplicate\n");
			}
		}
	}	





void traverse(treeNode *root){

	if (root != NULL){
		traverse(root -> left);

	printf("%d ", root -> data);

	traverse(root -> right);
	}

}



int find(treeNode *root, int x){

	if(root == NULL)
	return -1;
	
	if (root -> data == x)
	return 1;	

	if(find(root -> right, x) == 1)
	return 1;


	if(find(root -> left, x) == 1)
	return 1;

	return -1;

}



void max(treeNode *root){

	while (root -> right != NULL)
	root = root -> right;
	printf("Max: %d\n", root -> data);
}



/*int min(treeNode *root){

	while (root -> left != NULL)
	root = root -> left;
	return root-> data;

}*/

TreeNodePointer removeNode(TreeNodePointer root, int data){
	if (root == NULL){
		return root;
	}
		if(data < root -> data){
			root -> left = removeNode(root -> left, data);
		}
		else if (data > root -> data){
			root -> right = removeNode(root -> right, data);
		}
	else{
		if(root -> left == NULL){
			TreeNodePointer temp = root -> right;
			free(root);
			return temp; 
		}	
		else if(root -> right == NULL){
			TreeNodePointer temp = root -> left;
			free(root);
			return temp;
		}
		else{
			TreeNodePointer temp = root -> right;
			while(temp -> left != NULL){
				temp = temp -> left;
			}
			root -> data = temp -> data;
			root -> right = removeNode(root -> right, temp -> data);
		}
	}
	return root;	
}


void deleteFromTree(TreeNode** treeNode, int data){

	if(*treeNode != NULL){
		TreeNodePointer current = *treeNode;
		while(current != NULL && current -> data != data){
			if(data < current -> data){
				current = current -> left;
			}
			else if(data > current -> data){
				current = current -> right;
			}
		}
		if (current != NULL){
			removeNode(*treeNode, data);
		}
		else{
			printf("Record wasnt found\n");
		}
	}
}



int main(){
	
	TreeNode *root = NULL;
	
	insertTreeNode(&root, 50);

	insertTreeNode(&root, 30);

	insertTreeNode(&root, 20);

	insertTreeNode(&root, 40);

	insertTreeNode(&root, 70);

	insertTreeNode(&root, 60);

	insertTreeNode(&root, 80);	

	

	

	traverse(root);
	
    printf("\nResult search: %d\n", find(root, 25));

    max(root);

    deleteFromTree(&root, 20);

    deleteFromTree(&root, 30);

    deleteFromTree(&root, 50);

    traverse(root);

}
