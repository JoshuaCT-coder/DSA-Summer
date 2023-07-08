#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bst.h"

/*
typedef struct{
	int prodID;
	charprodName[20];
	int prodQty;
	float prodPrice;
}Product;

typedef struct node{
	Product data;
	struct *node left;
	struct *node right;
}nodeType, *nodePtr,BST,*BSTPtr;
*/


//other func.
BST *newBST(){
	nodePtr list=NULL;
	return list;
}
void initBST(BST **list){
	*list=NULL;
}

bool isEmpty(BST *list){
	return (list==NULL);
}
Product createProd(int id, char*name, int qty, float price){
	Product p;
	p.prodID=id;
	strcpy(p.prodName,name);
	p.prodPrice=price;
	p.prodQty=qty;
	return p;
}
void displayProduct(Product prod){
	printf("\n%9d | %8s | %-8d | %-5.2f\n",prod.prodID,prod.prodName,prod.prodQty,prod.prodPrice);
}


BSTPtr createNode(){
	BSTPtr temp= malloc(sizeof(BST));
	temp->data=createProd(0,"",0,0.00);
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

BST* max(BST *list){
	BSTPtr *trav;
	for(trav=&list;(*trav)->right!=NULL;trav=&(*trav)->right){}
	return *trav;
}
BST* min(BST *list){
	BSTPtr *trav;
	for(trav=&list;(*trav)->left!=NULL;trav=&(*trav)->left){}
	return *trav;
}

bool isMember(BST *list, int prodID){
	BSTPtr trav;
}
//Add element to BST

BSTPtr addElem(BST *list, Product item){

	if(isEmpty(list)){
	
		BSTPtr temp=createNode();
		if(temp!=NULL){
		printf("\nNode created\n");
		temp->data=item;
	}else{
		printf("\nLost in memory\n");
	}
		return temp;
	}


 	if (item.prodID < list->data.prodID) {
 		printf("\nMoving Left\n");
        list->left = addElem(list->left, item);
    }
    else if (item.prodID > list->data.prodID) {
    		printf("\nMoving Right\n");
        list->right = addElem(list->right, item);
    } 
    
    printf("\nReturning List\n");
    return list;
} //recursive



void insertBST (BSTPtr *list, Product item){
	BSTPtr *curr;
	BSTPtr parent;
	
	curr=list;
	parent=*curr;
	
		while(!isEmpty(parent)){
		
	 	if (item.prodID < (*curr)->data.prodID) {
	 		printf("\nMoving Left\n");
	        curr=&(*curr)->left;
	        parent=*curr;
	    }
	    else{
	    	printf("\nMoving Right\n");
	        curr=&(*curr)->right;
	        parent=*curr;
	    }
	}
			BSTPtr temp=createNode();
				if(temp!=NULL){
				printf("\nNode created\n");
				temp->data=item;
				*curr=temp;
			}else{
				printf("\nLost in memory\n");
			}
		}

//Delete element int BST
void removeElem(BST **list, int prodID) { //Geeks for Geeks implementation
    BSTPtr curr = *list;
    BSTPtr parent = NULL;
 
    // Find the node to be deleted
    while (curr != NULL && curr->data.prodID != prodID) {
        parent = curr;
        if (prodID < curr->data.prodID)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    // If the node is not found
    if (curr == NULL)
        return;
 
    // Case 1: Node to be deleted has no children
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == NULL) {
            *list = NULL; // Node to be deleted is the root
        } else if (parent->left == curr) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(curr);
    }
 
    // Case 2: Node to be deleted has one child
    else if (curr->left == NULL) {
        if (parent == NULL) {
            *list = curr->right;
        } else if (parent->left == curr) {
            parent->left = curr->right;
        } else {
            parent->right = curr->right;
        }
        free(curr);
    }
    else if (curr->right == NULL) {
        if (parent == NULL) {
            *list = curr->left;
        } else if (parent->left == curr) {
            parent->left = curr->left;
        } else {
            parent->right = curr->left;
        }
        free(curr);
    }
 
    // Case 3: Node to be deleted has two children
    else {
        BSTPtr successorParent = curr;
        BSTPtr successor = curr->right;
 
        while (successor->left != NULL) {
            successorParent = successor;
            successor = successor->left;
        }
 
        if (successorParent != curr)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
 
        curr->data.prodID = successor->data.prodID;
        free(successor);
    }
}

BST *deleteElement(BST *list,int prodID){  //Geeks for Geeks implementation
	
    // Base case
    if (isEmpty(list))
        return list;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (list->data.prodID > prodID) {
        list->left = deleteElement(list->left, prodID);
        return list;
    }
    else if (list->data.prodID < prodID) {
        list->right = deleteElement(list->right, prodID);
        return list;
    }
 
    // We reach here when list is the node
    // to be deleted.
 
    // If one of the children is empty
    if (list->left == NULL) {
        BSTPtr temp = list->right;
        free(list);
        return temp;
    }
    else if (list->right == NULL) {
        BSTPtr temp = list->left;
        free(list);
        return temp;
    }
 
    // If both children exist
    else {
 
		BSTPtr currParent = list;
 
        // Find successor
		BSTPtr succ = list->right;
        while (succ->left != NULL) {
            currParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to currParent->right
        if (currParent != list)
            currParent->left = succ->right;
        else
            currParent->right = succ->right;
 
        // Copy Successor Data to list
        list->data.prodID = succ->data.prodID;
 
        // Delete Successor and return list
        free(succ);
        return list;   
}
}


//Display all (recursive)
void inorderBST(BST *list){
     	nodePtr trav=list;
	if(!isEmpty(trav)){
     	inorderBST(trav->left);
     	displayProduct(trav->data);
        inorderBST(trav->right);
    }
}
void preorderBST(BST *list){
	nodePtr trav=list;
	if(!isEmpty(trav)){
	displayProduct(trav->data);
     	preorderBST(trav->left);
        preorderBST(trav->right);
   }
}
void postorderBST(BST *list){
	nodePtr trav=list;
	if(!isEmpty(trav)){
     	postorderBST(trav->left);
        postorderBST(trav->right);
        displayProduct(trav->data);
    }
}

