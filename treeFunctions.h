
#ifndef _TREEFUNCTIONS_H_
#define _TREEFUNCTIONS_H_

#define ENTER (char) '\n'   // change 
#define TAB (char) '\t'     // change 
#define SPACE (char) ' '      // change 
#define END (char) '\0'     // change 



// a constant definition 

#define NUM_LETTERS ((int)26) 

typedef enum { FALSE = 0, TRUE = 1 } boolean;

typedef struct node {

	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];

} node;


// a function prototype 

_Bool isCharLeagal(char character);
node* newNode();
void buildTree(node* head);
node* addword(node* head,node* pointNode,char character);
int bigWordLength(node* n, int counter);
void freeLevelsOnTree(node* head);
void printWord(node* head,char strWord[], int levelTree);
void printWordReverse(node* head,char strWord[], int levelTree);











#endif
