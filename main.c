#include <stdio.h>
#include <string.h>
#include "treeFunctions.h"
#include <stdlib.h>





int main(int argc, char* argv[]) {

	char* r = "r";
	node* head = newNode();
	buildTree(head);
        int biggestWordLength=bigWordLength(head, 0);
        char* word = (char*)malloc(biggestWordLength);

	if( (strcmp(argv[1],r)==0) && (argc==2) )
        {
                printWordReverse(head,word,0);}

	else {
		printWord(head,word,0);
	}


        free(word);
	freeLevelsOnTree(head);


	return 0;
}

