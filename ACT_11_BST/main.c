#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
/* 

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

BST addEleem(BST list, Product item); //recursiv
void insertBST (BSTPtr *list, Product item); //iterative

//Delete element int BST
void removeElem(BST **list, int prodID); //iterative
BST *deleteElement(BST *list,int prodID); //recursive

//Display all (recursive)
void inorderBST(BST *list);
void preorderBST(BST *list);
void postorderBST(BST *list);
*/
int main(int argc, char *argv[]) {
	BSTPtr list= newBST();
	
//	 list=addElem(list,createProd(211003,"Jeremy",15,12.3));
//	 list=addElem(list,createProd(211001,"Jonny",14,13.3));
//	 list=addElem(list,createProd(211004,"Jirc",12,10.5));
//	 list=addElem(list,createProd(201003,"Jeremy",15,12.3));
//	 list=addElem(list,createProd(191001,"Jonny",14,13.3));
//	 list=addElem(list,createProd(181004,"Jirc",12,10.5));

	 insertBST(&list,createProd(211003,"Jeremy",15,12.3));
	 insertBST(&list,createProd(211001,"Jonny",14,13.3));
	 insertBST(&list,createProd(211004,"Jirc",12,10.5));
	 insertBST(&list,createProd(201003,"Jeremy",15,12.3));
	 insertBST(&list,createProd(191001,"Jonny",14,13.3));
	 insertBST(&list,createProd(181004,"Jirc",12,10.5));
	 
	
	if (isEmpty(list)){
		printf("\n%7s\n","EMPTY");
	}else{
	printf("---------------INORDER---------------");
	printf("\n%9s | %8s | %8s | %5s\n","PRODID","PRODNAME","QUANTITY","PRICE");
	inorderBST(list);
	printf("---------------PREORDER---------------");
	printf("\n%9s | %8s | %8s | %5s\n","PRODID","PRODNAME","QUANTITY","PRICE");
		preorderBST(list);
	printf("---------------POSTORDER---------------");
	printf("\n%9s | %8s | %8s | %5s\n","PRODID","PRODNAME","QUANTITY","PRICE");
		postorderBST(list);
	
	BSTPtr Max=max(list);
	BSTPtr Min=min(list);
	printf("\n\n%20s %d","Minimum studID is",Min->data.prodID);
	printf("\n\n%20s %d","Maximum studID is",Max->data.prodID);
	}
	return 0;
}
