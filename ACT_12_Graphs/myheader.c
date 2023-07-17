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
	}
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
		}else{
			printf("\nOne of the edges doesnt have Adjacency Space , CANT INSERT\n");
		}	
	}else{
		printf("\nOne or both vertex does not Exist ,  CANT INSERT\n");
	}
	printf("\nInserted Edges\n");
}
void display(Dictionary dic){
	int i;
	printf("\n%8s | %8s\n","VERTEX","EDGES");
	for(i=0; i<MAX ;i++){
		if(strcmp(dic.List[i].key,EMPTY_KEY)!=0 && strcmp(dic.List[i].key,"DELETED")!=0){
			printf("%8s : ",dic.List[i].key);
			if(dic.List[i].value.data!=NULL){
				int a=0;
				while(a<dic.List[i].value.count){
					printf("%8s | ",dic.List[i].value.data[a]);
					a++;
				}
			}
			printf("\n");
		}
	}
}




