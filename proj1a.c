#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>


DIR *dp;
struct dirent *ep;





typedef struct folderName{
	char name[100];
	struct folderName* next;
} folder_name;

typedef struct node{
	char name[100];
	struct node* next;
} nodes;




//Adds a name to the linked list
void push(folder_name* head, char* str) {
        folder_name* current = head;
        while (current->next != NULL) {
                current = current->next;
        }
        current->next = malloc(sizeof(folder_name));
        strcpy(current->next->name, str);
        current->next->next = NULL;
}

void clearfList(folder_name* head){
	head->next = NULL;
	strcpy(head->name,"q");
}

//Puts file names into linked list

int mkListOfDirect(folder_name* list, char* str){
	
	clearfList(list);
		
        dp = opendir (str);
        if (dp != NULL){
                while (ep = readdir (dp))
                        push(list, ep->d_name);
                (void) closedir (dp);
                return 1;
        } else {
                perror ("couldnt open dir");
                return 0;
        }


}

//Prints linked list of names

void printfList(folder_name* head) {

        folder_name* current = head;
        while (current != NULL) {
                printf("%s \n", current->name);
                current = current->next;
        }
}


/////////////////////////////
// putting into array
////////////////////////


nodes* createNewNode(char* str) {
        
        nodes *newNode= malloc(sizeof(nodes));
        strcpy(newNode->name, str);
        newNode->next = NULL;
	return newNode;
}

void pushNode(nodes* head, char* str){
        nodes* current = head;
        while (current->next != NULL) {
                current = current->next;
        }
        current->next = malloc(sizeof(nodes));
        strcpy(current->next->name, str);
        current->next->next = NULL;
}



int stringToIndex(char* str){
	if(str[0] == (char) *"a"){ return 0;}
	if(str[0] == (char) *"b"){ return 1;}
	if(str[0] == (char) *"c"){ return 2;}
	if(str[0] == (char) *"d"){ return 3;}
	if(str[0] == (char) *"e"){ return 4;}
	if(str[0] == (char) *"f"){ return 5;}
	if(str[0] == (char) *"g"){ return 6;}
	if(str[0] == (char) *"h"){ return 7;}
	if(str[0] == (char) *"i"){ return 8;}
	if(str[0] == (char) *"j"){ return 9;}
	if(str[0] == (char) *"k"){ return 10;}
	if(str[0] == (char) *"l"){ return 11;}
	if(str[0] == (char) *"m"){ return 12;}
	if(str[0] == (char) *"n"){ return 13;}
	if(str[0] == (char) *"o"){ return 14;}
	if(str[0] == (char) *"p"){ return 15;}
	if(str[0] == (char) *"q"){ return 16;}
	if(str[0] == (char) *"r"){ return 17;}
	if(str[0] == (char) *"s"){ return 18;}
	if(str[0] == (char) *"t"){ return 19;}
	if(str[0] == (char) *"u"){ return 20;}
	if(str[0] == (char) *"v"){ return 21;}
	if(str[0] == (char) *"w"){ return 22;}
	if(str[0] == (char) *"x"){ return 23;}
	if(str[0] == (char) *"y"){ return 24;}
	if(str[0] == (char) *"z"){ return 25;}
		return 60;
}

void initializeArray(nodes* array[]){

	nodes* empty = malloc(sizeof(nodes));
	strcpy(empty->name,"q");
	empty->next = NULL;
	for(int i = 0; i <28; i++){
		array[i] = empty; 
	}

}


void printArray(nodes* array[]){
	nodes* current;
	for(int i =0; i < 25; i++){
		current = array[i];
		if(strcmp(current->name, "q") != 0){
			printf("%s \n", current->name);
			while(current->next != NULL){
				printf("%s \n", current->next->name);	
				current = current->next;
			}
		}
	}
}

void printArrayAll(nodes* array[]){
	nodes* current;
	for(int i =0; i < 26; i++){
		current = array[i];
			printf("%s \n", current->name);
			while(current->next != NULL){
				printf("%s \n", current->next->name);	
				current = current->next;
			}
		}
}

void add(folder_name* fNames, nodes* array[]){

 	folder_name* currentx = fNames;
	nodes* currenty;
        int index;	
	char* str;	
	
	while (currentx !=  NULL) {
       
		index = stringToIndex(currentx->name);
		if(index != 60){
			if (strcmp(array[index]->name, "q") == 0 ){
				currenty = createNewNode(currentx->name);
				array[index] = currenty;
			} else{
				currenty = array[index];
				pushNode(currenty, currentx->name);
			}
			currentx = currentx->next;
			currenty = NULL;
               	} else{
			currentx = currentx->next;
			currenty = NULL;
        	}
	}
}

void findNames(nodes* array[], char* str){

	int length = strlen(str);
	int booln;
	nodes* current;
	for(int i =0; i < 28; i++){
		booln = 1;
		current = array[i];
		if(strcmp(current->name, "q") != 0){
			for(int j = 0; j<length; j++){
				if(length > strlen(current->name)){
					booln = 0;
				} else {
					if(str[j] != current->name[j]){
						booln = 0;
					}
				}} 
				if(booln == 1){
					printf("%s\n", current->name);
				}
				
			while(current->next != NULL){
				booln = 1;
				
				for(int j = 0; j<length; j++){
                                	if(length > strlen(current->next->name)){
                                        	booln = 0;
                        		} else {
                                		if(str[j] != current->next->name[j]){
                                        		booln = 0;
                                		}
                        		}}
                        		if(booln == 1){
                                		printf("%s\n", current->next->name);
                        		}
				
				current = current->next;
                        }
                }
        }

}




int main(){

char quit[2]="q";
char userInput[100];
nodes* pArray[29];
int booln;

while(1){
        folder_name* fNames = NULL;
        fNames = malloc(sizeof(folder_name));
	initializeArray(pArray);
        booln = 0;
	

	printf("\n Enter a directory name or press q to quit: ");
        scanf("%s", userInput);
        if(userInput[0] == quit[0]){
                break;
        }

        booln = mkListOfDirect(fNames, userInput);
        if(booln ==1){
		add(fNames, pArray);
		printArray(pArray);
                printf("\n Enter the beginning of a file name: ");
                scanf("%s", userInput);
                findNames(pArray, userInput);
	free(fNames);
	}
	
}

return 0;
}






