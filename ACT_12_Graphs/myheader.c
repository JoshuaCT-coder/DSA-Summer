#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "myheader.h"



int hash(char * item){
	char firstletter = toupper(item[0]);

    int hashvalue = (int)firstletter % 26;

    return hashvalue;
}

void initDict(Dictionary *dic){
	int i;
	for(i=0;i<MAX;i++){
	strcpy(dic->List[i].key,EMPTY_KEY);
	dic->List[i].value.count=0;
	dic->List[i].value.max=10;
	dic->List[i].value.data=NULL;
	}
	printf("\nInitialization complete\n");
}

void freeDict(Dictionary *dic){
	int i;
	for(i=0;i<MAX;i++){
	free(dic->List[i].value.data);
	dic->List[i].value.data=NULL;
	}
	printf("\nFreed Space\n");
}


void addVertex(Dictionary *dic,String item){
	int hashval=hash(item);
	if(strcmp(dic->List[hashval].key,EMPTY_KEY)==0){
		strcpy(dic->List[hashval].key,item);
		printf("\n Inserted vertex\n");
	}else if(strcmp(dic->List[hashval].key,item)==0){
		printf("\nVertex Already exists\n");
	}else{
		while (strcmp(dic->List[hashval].key,EMPTY_KEY)!=0 && strcmp(dic->List[hashval].key,item)!=0){
        hashval = (hashval + 1) % MAX;
    }
	if(strcmp(dic->List[hashval].key,item)!=0){
    strcpy(dic->List[hashval].key,item);
	printf("\n Inserted vertex\n");
	}else{
		printf("\nVertex Already exists\n");
	}
	}
	
}

bool checkVertex(Dictionary dic, String item){
	int hashval=hash(item);
	bool state= false;
	if(strcmp (dic.List[hashval].key,item)==0){
	 state = true;	
	
	}else{
		while (strcmp(dic.List[hashval].key,item)!=0 && strcmp(dic.List[hashval].key,EMPTY_KEY)!=0){
        hashval = (hashval + 1) % MAX;
    }
	    if(strcmp(dic.List[hashval].key,EMPTY_KEY)==0){
	    	state = false;
		}else{
			state = true;
		}
}
return state;
}

int getHashIndex(Dictionary dic, String vertex){
	int hashval=hash(vertex);
	int value=0;
	if(strcmp (dic.List[hashval].key,vertex)==0){
	value = hashval;	
	
	}else{
		while (strcmp(dic.List[hashval].key,vertex)!=0 && strcmp(dic.List[hashval].key,EMPTY_KEY)!=0){
        hashval = (hashval + 1) % MAX;
    }
	    if(strcmp(dic.List[hashval].key,EMPTY_KEY)==0){
			value=-1;
		}
		if(strcmp (dic.List[hashval].key,vertex)==0){
		value = hashval;	
	
		}
}
	return value;
}


void addSortedEdge(Dictionary *dic, String vertex1, String vertex2){
	bool state1= checkVertex(*dic,vertex1);
	bool state2= checkVertex(*dic,vertex2);
	int hash1;
	int hash2;
	int i;
	int a;

	if (state1 && state2){
		hash1=getHashIndex(*dic,vertex1);
		hash2=getHashIndex(*dic,vertex2);
	if(dic->List[hash2].value.count < dic->List[hash2].value.max && dic->List[hash1].value.count < dic->List[hash1].value.max){
			if(strcmp(dic->List[hash1].key,vertex1)==0){
				if(dic->List[hash1].value.data==NULL){
					dic->List[hash1].value.data = malloc(sizeof(String)*dic->List[hash1].value.max);
					strcpy(dic->List[hash1].value.data[dic->List[hash1].value.count],vertex2);
					dic->List[hash1].value.count++;
				}else{
					for(i=0;i<dic->List[hash1].value.count && strcmp(dic->List[hash1].value.data[i],vertex2)<0 && strcmp(dic->List[hash1].value.data[i],vertex2)!=0;i++){}
					if(strcmp(dic->List[hash1].value.data[i],vertex2)!=0){
					if(i<dic->List[hash1].value.count){
					
						for(a=dic->List[hash1].value.count;a>=i;a--){
							strcpy(dic->List[hash1].value.data[a],dic->List[hash1].value.data[a-1]);
						}						
					  }
					strcpy(dic->List[hash1].value.data[i],vertex2);
					dic->List[hash1].value.count++;
					printf("\nInserted Edge\n");
					}else{
						printf("\nThe Connection Already Exists\n");
					}
				}
				}
			if(strcmp(dic->List[hash2].key,vertex2)==0){
				if(dic->List[hash2].value.data==NULL){
					dic->List[hash2].value.data = malloc(sizeof(String)*dic->List[hash2].value.max);
					strcpy(dic->List[hash2].value.data[dic->List[hash2].value.count],vertex1);
					dic->List[hash2].value.count++;
				}else{
					for(i=0;i<dic->List[hash2].value.count && strcmp(dic->List[hash2].value.data[i],vertex1)<0 && strcmp(dic->List[hash2].value.data[i],vertex1)!=0;i++){}
					if(strcmp(dic->List[hash2].value.data[i],vertex1)!=0){
					if(i<dic->List[hash2].value.count){
						
						for(a=dic->List[hash2].value.count;a>=i;a--){
							strcpy(dic->List[hash2].value.data[a],dic->List[hash2].value.data[a-1]);
						}						
					  }
					strcpy(dic->List[hash2].value.data[i],vertex1);
					dic->List[hash2].value.count++;
					printf("\nInserted Edge\n");
					}else{
						printf("\nThe Connection Already Exists\n");
					}
				}
			}
				
		}else{
			printf("\nOne of the edges doesnt have Adjacency Space , CANT INSERT\n");
		}	
	}else{
		printf("\nOne or both vertex does not Exist ,  CANT INSERT\n");
	}

}

void deleteVertex(Dictionary *dic, String key){
	bool state= checkVertex(*dic,key);
	 int hash1;
	 String vertex;
	if(state){
		
		hash1=getHashIndex(*dic,key);
			if(strcmp(dic->List[hash1].key,key)==0){
				if(dic->List[hash1].value.data==NULL){
					strcpy(dic->List[hash1].key,EMPTY_KEY);
				}else{
					
					
					while(dic->List[hash1].value.count>0){
					  printf("\nCOUNT: | %d\n",dic->List[hash1].value.count);
					  strcpy(vertex,dic->List[hash1].value.data[0]);
					  deleteEdge(dic, key,vertex);
					}
					free(dic->List[hash1].value.data);
					dic->List[hash1].value.data=NULL;
					
					strcpy(dic->List[hash1].key,EMPTY_KEY);
				}
				printf("\nDeleted Vertex and Edges\n");
		}

	}
	

}
void deleteEdge(Dictionary *dic, String vertex1, String vertex2){
	bool state1= checkVertex(*dic,vertex1);
	bool state2= checkVertex(*dic,vertex2);
	int hash1;
	int hash2;
	if(state1 && state2){
		
		hash1=getHashIndex(*dic,vertex1);
		hash2=getHashIndex(*dic,vertex2);
			if(dic->List[hash2].value.count > 0 && dic->List[hash1].value.count > 0){
				
				if(strcmp(dic->List[hash1].key,vertex1)==0){
					if(dic->List[hash1].value.data!=NULL){
						int i=0;
						while(dic->List[hash1].value.count > i && strcmp(dic->List[hash1].value.data[i],vertex2)!=0){i++;}
							if(i>=dic->List[hash1].value.count){
								printf("These vertices aren't connected");
							}else{
								while(i<dic->List[hash1].value.count){
								strcpy(dic->List[hash1].value.data[i],dic->List[hash1].value.data[i+1]);
								i++;
								}
								dic->List[hash1].value.count--;
								strcpy(dic->List[hash1].value.data[dic->List[hash1].value.count],EMPTY_KEY);
								printf("\n!-Edge Removed-!\n");
							}	
					}
				}
				if(strcmp(dic->List[hash2].key,vertex2)==0){
					if(dic->List[hash2].value.data!=NULL){
						int a=0;
						while(dic->List[hash2].value.count > a && strcmp(dic->List[hash2].value.data[a],vertex1)!=0){a++;}
							if(a>=dic->List[hash2].value.count){
								printf("These vertices aren't connected");
							}else{
								while(a<dic->List[hash2].value.count){
								strcpy(dic->List[hash2].value.data[a],dic->List[hash2].value.data[a+1]);
								a++;
								}
								dic->List[hash2].value.count--;
								strcpy(dic->List[hash2].value.data[dic->List[hash2].value.count],EMPTY_KEY);
							}	
					}
				}
			}else{
				printf("\nOne or Both vertex doesnt have an Edge, Can't delete the edge\n");
			}
	}else{
		printf("\nOne or both vertex doesn't exist\n");
	}
}

void visualize(Dictionary dic){
	int i;
	printf("\n%8s | %5s | %8s\n","VERTEX","INDEX","EDGES");
	for(i=0; i<MAX ;i++){
		if(strcmp(dic.List[i].key,EMPTY_KEY)!=0 && strcmp(dic.List[i].key,"DELETED")!=0){
			printf("%8s | %5d :",dic.List[i].key,i);
			if(dic.List[i].value.data!=NULL){
				int a=0;
				while(a<dic.List[i].value.count){
					printf("%8s | ",dic.List[i].value.data[a]);
					a++;
				}
				//printf("\n   EDGE COUNT: %d ",dic.List[i].value.count);
			}
			printf("\n");
			}//else{
		// 		printf("%8s : ","EMPTY");	
		// }
		
	}
}





//STACK Functions
void initStack(Stack *s){
	s->top=0;
	
}
void pop(Stack *s){
	s->top--;
	
}
void push(Stack *s, String vertex){
	strcpy(s->list[s->top++],vertex);
	
}
char * top(Stack *s){
	return s->list[s->top-1];
}
void displaySTK(Stack s){
	Stack temp;
	initStack(&temp);
	while(s.top>0){
		push(&temp,top(&s));
		pop(&s);
	}
	printf("\nPRINTING STACK\n");
	while(temp.top>0){
		printf("\n%10s\n",top(&temp));
		pop(&temp);
	}
}


//Queue Functions
void initQueue(Queue *q){
	
}
void enqueue(Queue *q, String vertex);
void dequeue(Queue *q);
char *front(Queue * q);
void displayQ(Queue);





//VISITED FUNCTIONS
bool searchVisited(Visited list ,String item){
int i;
for(i=0;i<list.count && strcmp(list.data[i],item)!=0;i++){}
return (i>=list.count)?false:true;
}

void initVisited(Visited *v){
	int i;
	for(i=0;i<MAX;i++){
		strcpy(v->data[i],EMPTY_KEY);
	}
	v->count=0;
}

int addUnvisited(Dictionary dic,Stack *s, Visited *v){
	
	int i,hash1,count=0;
	printf("\nAdding Unvisited\n");
	hash1=getHashIndex(dic,top(s));
	
	for(i=dic.List[hash1].value.count-1;i>=0;i--){
		if(!searchVisited(*v,dic.List[hash1].value.data[i])){
			push(s,dic.List[hash1].value.data[i]);
			count++;
		}
	}
	return count;
}
void visitedDisplay(Visited v){
	int i;
	for(i=0;i<v.count;i++){
		printf("\n%10s\n",v.data[i]);
	}
	printf("\n    TOTAL #of VERTEXES: %d\n",v.count);
}






//TRAVERSAL DISPLAY

void BFSdisplay(Dictionary dic, String vertex);

void DFSdisplay(Dictionary dic, String vertex){
	
	Stack vertices;
	Visited result;
	int i;
	int added;

	initVisited(&result);
	initStack(&vertices);
	push(&vertices,vertex);
	
	displaySTK(vertices);

	visitedDisplay(result);
	while(vertices.top!=0){
		if(!searchVisited(result,top(&vertices))){
			
			strcpy(result.data[result.count++],top(&vertices));
			
		}
			
			added = addUnvisited(dic,&vertices,&result);
			printf("\nUNVISITED NODES ADDED:  %d\n",added);
			if(added==0){
				pop(&vertices);
			}	
			displaySTK(vertices);
	}


	printf("\n---------DFS TRAVERSAL---------\n");
	visitedDisplay(result);
}



//POPULATE VERTEX AND STACKS HAS THE CAPACITY TO REJECT DUPLICATES
void populateVertex(Dictionary *list){
	addVertex(list,"Canada");
	addVertex(list,"Japan");
	addVertex(list,"Coda");
	addVertex(list,"Silent");
	addVertex(list,"River");
	addVertex(list,"Luster");
	addVertex(list,"Rein");

}

void populateEdges(Dictionary *list){

	addSortedEdge(list,"Silent","Canada");
	addSortedEdge(list,"Silent","Rein");
	addSortedEdge(list,"Silent","River");
	addSortedEdge(list,"Silent","Coda");

	addSortedEdge(list,"Luster","Coda");
	addSortedEdge(list,"Luster","Silent");

	addSortedEdge(list,"Canada","Rein");

	addSortedEdge(list,"Japan","Luster");
	addSortedEdge(list,"Japan","Rein"); 
}