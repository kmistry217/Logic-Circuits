#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct node{
	struct node* next;
	char name[10];
	int* value;
};

struct node* head = NULL;

unsigned long int greyCode (int n, unsigned long int *gcDec){
	
	int i, j, x;
	for (x=1; x<n; x++){
		i = 1<<x;
		j = i-1;
		while (i<2*(1<<x) && j>=0){
			gcDec[i]=gcDec[j];
			i++;
			j--;
		}
		for (i=1<<x; i<2*(1<<x); i++){	
			gcDec[i] = gcDec[i] | 1<<x;
		}
	}
	return *gcDec; 	
}

int** convertBinary(int n, unsigned long int *gcDec, int** gc){
	
	int i, j, x;
	int columns = 1<<n;
	
	for (j=0; j<columns; j++){
		x = gcDec[j];
		for (i=n-1; i>=0; i--){
			gc[i][j] = x & 1;
			x = x>>1;
		}
	}
	return gc;
}

void insert(struct node* variables){
	struct node *ptr = head;
	if (head == NULL){
		variables->next = NULL;
		head = variables;
	}
	else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = variables;
		ptr->next->next = NULL;
	}
	return;
}

int main (int argc, char** argv){

	char* file = argv[1];
	FILE* fp = NULL;
	fp = fopen(file, "r");

	int i,j;
	int numInputs, numOutputs; 
	struct node *variables, *ptr;
	char op[10];
	
	fscanf(fp, "%*s %d", &numInputs);
	int columns = 1<<numInputs;
	
	int *zero = (int*) malloc (columns*sizeof(int));
	for(i=0; i<columns; i++){
		zero[i]=0;
	}
	unsigned long int *gcDec = (unsigned long int*) malloc (columns* sizeof(unsigned long ));
	int** gc = (int**) malloc (numInputs* sizeof(int*));
	for (i=0; i<numInputs; i++){
		gc[i] = (int*) malloc (columns*sizeof(int));
	}
	gcDec[0] = 0; 
	gcDec[1] = 1;
	
	greyCode(numInputs, gcDec);
	convertBinary(numInputs, gcDec, gc);
	
	for (i=0; i<numInputs; i++){
		variables = (struct node*) malloc (sizeof(struct node));
		fscanf(fp, "%s", variables->name);
		variables->value = gc[i];
		insert(variables);
	}
	
	fscanf(fp, "%*s %d", &numOutputs);
	for (i=0; i<numOutputs; i++){
		variables = (struct node*) malloc (sizeof(struct node));
		fscanf(fp, "%s", variables->name);
		variables->value = (int*) malloc (columns*sizeof(int));
		insert(variables);
	}
	
	int hi = numInputs+numOutputs;
	
	free(gcDec);
	
	
	while(!feof(fp)){
		char tempName[10];
		int* tempValue = (int*) malloc (columns* sizeof(int));
		char tempName2[10];
		int* tempValue2 = (int*) malloc (columns* sizeof(int));
		char tempName3[10];
		int* tempValue3 = (int*) malloc (columns* sizeof(int));

		ptr = head; 
		fscanf(fp, "%s", op);
		
		if (strcmp(op, "NOT")==0){
			fscanf(fp, "%s", tempName);
			if (strcmp(tempName, "1")==0) {
				for (i=0; i<columns; i++){
					tempValue[i] = 1; 
				}
			}
			else if (strcmp(tempName, "0")==0) {
				for (i=0; i<columns; i++){
					tempValue[i] = 0; 
				}
			}
			else{
			while (ptr != NULL){
				if (strcmp(tempName, ptr->name)==0){
					for(i=0; i<columns; i++){
						tempValue[i] = ptr->value[i];
					}
					break;
				}
				ptr=ptr->next;
			}
			}
			variables = (struct node*) malloc (sizeof(struct node));
			fscanf(fp, "%s", variables->name); 
			for (i=0; i<columns; i++){
				tempValue[i] = !tempValue[i];
			}
			variables->value = tempValue; 
			ptr = head;
			while(ptr!=NULL){
				if (strcmp(ptr->name, variables->name)==0){
					ptr->value = variables->value; 
					break;
				}
				ptr = ptr->next;
				if (ptr==NULL){
					insert(variables);
				}
			}
		}
		
		else{
			fscanf(fp, "%s %s %s", tempName, tempName2, tempName3);  
			if (strcmp(tempName, "1")==0) {
				for (i=0; i<columns; i++){
					tempValue[i] = 1; 
				}
			}
			else if (strcmp(tempName, "0")==0) {
				for (i=0; i<columns; i++){
					tempValue[i] = 0; 
				}
			}
			if (strcmp(tempName2, "1")==0) {
				for (i=0; i<columns; i++){
					tempValue2[i] = 1; 
				}
			}
			else if (strcmp(tempName2, "0")==0) {
				for (i=0; i<columns; i++){
					tempValue2[i] = 0; 
				}
			}
			while(ptr != NULL){
				if  (strcmp(tempName, "1") !=0 && strcmp(tempName, "0") !=0  && strcmp(tempName, ptr->name)==0){
					for(i=0; i<columns; i++){
						tempValue[i] = ptr->value[i];
					}
				}
				if  (strcmp(tempName2, "1") !=0 && strcmp(tempName2, "0") !=0 && strcmp(tempName2, ptr->name)==0){
					for(i=0; i<columns; i++){
						tempValue2[i] = ptr->value[i];
					}
				}
				ptr = ptr->next;
			}   
					
			
			if (strcmp(op, "AND")==0){
				for (i=0; i<columns; i++){
					tempValue3[i] = tempValue[i] & tempValue2[i];
				}
			}
			else if (strcmp(op, "OR")==0){
				for (i=0; i<columns; i++){
					tempValue3[i] = tempValue[i] | tempValue2[i];
				}
			}
			else if (strcmp(op, "NAND")==0){
				for (i=0; i<columns; i++){
					tempValue3[i] = tempValue[i] & tempValue2[i];
					tempValue3[i] = !tempValue3[i]; 
				}
			}
			else if (strcmp(op, "NOR")==0){
				for (i=0; i<columns; i++){
					tempValue3[i] = tempValue[i] | tempValue2[i];
					tempValue3[i] = !tempValue3[i];
				}
			}
			else if (strcmp(op, "XOR")==0){
				for(i=0; i<columns; i++){
					tempValue3[i] = tempValue[i] ^ tempValue2[i];
				}
			}
			 
			ptr = head;
			while(ptr!=NULL){
				if (strcmp(ptr->name, tempName3)==0){
					for (i=0; i<columns; i++){
						ptr->value[i] = tempValue3[i]; 
					}
					break;
				}
				ptr = ptr->next;
			}
			if (ptr==NULL){
				variables = (struct node*) malloc (sizeof(struct node));
				strcpy(variables->name, tempName3);
				variables->value = tempValue3;
				insert(variables);
			}			
		}

		free(tempValue);
		free(tempValue2);
		free(tempValue3);
	}
	
	/*
	printf("\n");
	ptr = head;
	while (ptr != NULL){
		printf("%s\n", ptr->name);
		for (j=0; j<columns; j++){
			printf("%d ", ptr->value[j]);
		}
		ptr = ptr->next;
		printf("\n");
	}
	printf("\n");
	*/
	 
	for(i=0; i<columns; i++){
		ptr = head; 
		for(j=0; j<hi; j++){
			printf("%d ", ptr->value[i]);
			ptr = ptr->next; 
		}
		printf("\n");
	}
	
	return 0; 
}

