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
void removeElem(BST **list, int prodID); //iterative
BST *deleteElement(BST *list,int prodID); //recursive



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

