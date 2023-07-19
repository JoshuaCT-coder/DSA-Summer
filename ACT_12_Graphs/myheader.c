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
	dic->List[i].value.max=5;
	dic->List[i].value.data=NULL;
	}
	printf("\nitialization complete\n");
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
	}else if(strcmp(dic->List[hashval].key,item)==0){
		printf("\nVertex Already exists\n");
	}else{
		while (strcmp(dic->List[hashval].key,EMPTY_KEY)!=0){
        hashval = (hashval + 1) % MAX;
    }
    strcpy(dic->List[hashval].key,item);
	}
	printf("\n Inserted vertex\n");
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


void addEdge(Dictionary *dic, String vertex1, String vertex2){
	bool state1= checkVertex(*dic,vertex1);
	bool state2= checkVertex(*dic,vertex2);
	int hash1;
	int hash2;


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
					strcpy(dic->List[hash1].value.data[dic->List[hash1].value.count],vertex2);
					dic->List[hash1].value.count++;
					}
				}
			if(strcmp(dic->List[hash2].key,vertex2)==0){
				if(dic->List[hash2].value.data==NULL){
					dic->List[hash2].value.data = malloc(sizeof(String)*dic->List[hash2].value.max);
					strcpy(dic->List[hash2].value.data[dic->List[hash2].value.count],vertex1);
					dic->List[hash2].value.count++;
				}else{
					strcpy(dic->List[hash2].value.data[dic->List[hash2].value.count],vertex2);
					dic->List[hash2].value.count++;
				}
			}
				printf("\nInserted Edges\n");
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
			}else{
				printf("%8s : ","EMPTY");	
		}
		printf("\n");
	}
}
void DFShelper(Dictionary *dic);
void BFSdisplay(Dictionary dic);
void DFSdisplay(Dictionary dic);
