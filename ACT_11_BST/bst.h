#ifndef BST_h
#define BST_H

#include <stdbool.h>



typedef struct{
	int prodID;
	char prodName[20];
	int prodQty;
	float prodPrice;
}Product;

typedef struct node{
	Product data;
	struct node *left;
	struct node *right;
}nodeType, *nodePtr,BST,*BSTPtr;

//other func.
BST *newBST();
void initBST(BST **list);
bool isEmpty(BST *list);
Product createProd(int id, char*name, int qty, float price);
void displayProduct(Product prod);
BST* max(BST *list);
BST* min(BST *list);
bool isMember(BST *list, int prodID);

//Add element to BST

BSTPtr addElem(BST *list, Product item); //recursiv
void insertBST (BSTPtr *list, Product item); //iterative

//Delete element int BST
void removeElem(BST **list, int prodID); //iterative
BST *deleteElement(BST *list,int prodID); //recursive

//Display all (recursive)
void inorderBST(BST *list);
void preorderBST(BST *list);
void postorderBST(BST *list);


#endif
