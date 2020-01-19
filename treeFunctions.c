#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "treeFunctions.h"
#include <stdlib.h>


node* newNode() {

        node* n=NULL;
	n= (node*)malloc(sizeof(node));
	if (n==NULL){
           printf("error-malloc not allocate memory");
              return NULL; }
	n->count = 0;
        int i;
	for (i = 0; i < NUM_LETTERS; i++){
		n->children[i] = NULL;}

	return n;	
}



void buildTree(node* head)
{
    char character;
    node* pointNode = head;
   
   do{

        character = getchar();
       character = tolower(character); //Turns a big letter into a small letter lib <ctype.h>
 
        if(character == EOF)
        {
            pointNode->count++;
            return;
        }

      if( character<'a' || character>'z' )
        {continue;}


        
        if (character=='\n' || character==' ' || character=='\t')
        {
            
            if ( (pointNode!=NULL) && (pointNode != head)  )
            {
                pointNode->count++;
                pointNode= NULL;
            }
            
            continue;
        }


        if(pointNode ==NULL){
             pointNode = head;}  
     
        pointNode = addword(head, pointNode, character);
        


   }while(character!=EOF);



}







node* addword(node* head,node* pointNode,char character){

    int i = (((int)character)-((int)'a'))  ;        //calculate the place of the index

    if( (pointNode->children[i])==NULL ){
        pointNode->children[i] = newNode();
        pointNode->children[i]->letter = character; 
    }

    pointNode = pointNode->children[i]; 

    return pointNode;

}



void freeLevelsOnTree(node* head)
{
    
    node* nPointer = head;
   
    for (size_t i=0; i<NUM_LETTERS;i++)
    {
        if(nPointer->children[i] !=NULL){
            freeLevelsOnTree(nPointer->children[i]);
        }
    }

    free(nPointer);


}



int bigWordLength(node* n, int counter){

    int i;
    int length = counter;

    for(i = 0; i < NUM_LETTERS; i++)
    {
        if(n->children[i]!=NULL)
        {
            int length2 = bigWordLength(n->children[i], counter + 1);

            if(length2 > length)
            {
              length = length2;
            }

        }
    }


    return length;
}




void printWord(node* head,char strWord[], int levelTree){

    node* nPointer = head;

    if (nPointer == NULL){
       return;}

    if (nPointer->count > 0){
        strWord[levelTree] = '\0';
        printf("%s\t %ld \n",strWord,nPointer->count);}
    
     int i;
    for(i = 0; i < NUM_LETTERS; i++)
    {

        if(nPointer->children[i] != NULL)
        {
            strWord[levelTree]=nPointer->children[i]->letter;
            printWord(nPointer->children[i], strWord,levelTree + 1);
        }
    }
}




void printWordReverse(node* head,char strWord[], int levelTree){

    node* nPointer = head;

    if(nPointer == NULL){
          return;}

    if(nPointer->count > 0){
        strWord[levelTree] = '\0';
        printf("%s\t %ld \n",strWord,nPointer->count); }
    
    int i;
    for(i = NUM_LETTERS-1; i >= 0; i--)
      {
        if(nPointer->children[i]!= NULL)
           {
            strWord[levelTree] = nPointer->children[i]->letter;
            printWordReverse(nPointer->children[i], strWord, levelTree + 1);
           }
      }

}






/*

void changeLetter(char word[]){
         
        int i;
	for (i = 0; word[i]!='\0'; i++) 
        {
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] = word[i] + 32;
	}

}
*/
/*
void removeNotLetter(char* str)
{
    
    char *pointer1=str;
    char *pointer2=str;

    while (*(pointer2)!='\0')
    {
        if (*(pointer2)>='a' && *(pointer2)<='z')
        {
	       *(pointer1) = *(pointer2);
               pointer1++;
	}

	   pointer2++;

    }

	*(pointer1)='\0';

}
*/





/*
void addword(node* head,char* word) {

	changeLetter(word);
	node* temp = head;
	int i = 0;
	while (i<strlen(word)) {

		if (temp->children[*(word + i) - 97] == NULL) {
			temp->children[*(word + i) - 97] = newNode();
			temp = temp->children[*(word + i) - 97];
			temp->letter = *(word + i);
			
			i++;
		}
		else{
			temp = temp->children[*(word + i) - 97];
			i++;
		}
	}
	temp->count=count++;
	temp->thisWord = TRUE;
	
}*/


/*
void printWord(node* head,char* c) {
	
	for (int i = 0; i < NUM_LETTERS; i++) {
		if (head->children[i] != NULL) {
			int level=1;
			print_word2(head->children[i],c,level);
		}

	}

}*/


