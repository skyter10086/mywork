/* new_linklist.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data {
	char name[20];
	struct data *next;
};

typedef struct data PERSON;
typedef PERSON *LINK;

LINK Head = NULL;
LINK Current = NULL;
LINK End = NULL;

LINK head(LINK node);
LINK append(LINK node);
LINK insert(LINK node);
LINK move(LINK node);
LINK del(LINK node);
LINK clean(void);
LINK current(void);
int eachdo(void *func);
int exist(LINK node);
void show(void);



int main(void) {
	LINK Person_1 = (PERSON*)malloc(sizeof(PERSON));
	Person_1->next = NULL;
	strcpy(Person_1->name, "Bill");
	
	head(Person_1);
	printf("after head Person_1 current is %s\n",current()->name);
	printf("after head Person_1 head is %s\n",Head->name);
	printf("after head Person_1 end is %s\n",End->name);
	

	
	LINK Person_2 = (PERSON*)malloc(sizeof(PERSON));
	strcpy(Person_2->name, "Jeffson");
    //printf("%s\n",current()->name);
    
        int exist1 = exist(Person_1);
        int exist2 = exist(Person_2);

        printf("Person1 exist return %d, Person2 exist return %d.\n", exist1, exist2);
	LINK Person_3 = (PERSON*)malloc(sizeof(PERSON));
	strcpy(Person_3->name, "Marilyn");
	
    LINK Person_4 = (PERSON*)malloc(sizeof(PERSON));
	strcpy(Person_4->name, "Kolfma");
	
	LINK Person_5 = (PERSON*)malloc(sizeof(PERSON));
	strcpy(Person_5->name, "Defcraft");	
	//printf("%s\n",current()->name);
	
	append(Person_5);
	printf("after append Person_5 current is %s\n",current()->name);
	printf("after append Person_5 Head is %s\n",Head->name);
	printf("after append Person_5 End is %s\n",End->name);
        
        move(Person_2);

	move(Head);
	printf("after move head current is %s\n",current()->name);
	insert(Person_2);
	printf("after insert Person_2 current is %s\n",current()->name);
	append(Person_3);
	printf("after append Person_3 current is %s\n",current()->name);
	move(End);
	printf("after move end current is %s\n",current()->name);
	append(Person_4);
	printf("after append Person_4 current is %s\n",current()->name);
	
	move(Head);
	printf("after move head current is %s\n",current()->name);
	while( Current != NULL ) {
		printf("now Current is %s\n", Current->name);
		Current = Current->next;
	}
	
        show();	
	clean();
	printf("after clean current is %s\n",current()->name);
	
	return 0;
}

void show(void) {
  move(Head);
  int index = 0;
  printf("\n[\n");
  while (current() != NULL) {
    printf("\t%d  :  %s\n", index, current()->name);
    Current = Current->next;
    index++;
  }
  printf("]\n");
}

LINK current(void) {
	return Current;
}


LINK clean(void) {
	 Head = NULL;
	 Current = NULL;
	 End = NULL;
	return Current;
}

LINK head(LINK node) {
	
	Head = node;
	Head->next = NULL;
	Current = Head;
	End = Head;
	
	return Current;
}

LINK append(LINK node) {
  
        int exist_node = exist(node);
	if (exist_node == 1) {
		printf("The node %s already existed.\n", node->name);
		return Current;
	}
	
	if (Current == NULL) {
		Head = node;
		Current = node;
		
		LINK P;
		P = node;
		while ( P->next != NULL) {
			P = P->next;
		}
		End = P;
		return Current;
	}
	
	else if (Current == End) {
		//node->next = NULL;
		Current->next = node;
		
		Current = node;
		
		LINK P;
		P = node;
		while ( P->next != NULL) {
			P = P->next;
		}
		End = P;
		//End = node;
		
		return Current;
	}
	
	else {
        node->next = Current->next;
	    Current->next = node;
	    Current = node;
	
	    return Current;	
	}
	
}

LINK move(LINK node) {

	if (exist(node) == 0) {
	    printf("The node %s is not exist in link list.\n", node->name);
	    return Current;
	}

	LINK P;
	
	P = Head;
	while (P != NULL) {
		if (P == node) {
			Current = node;
			return Current;
		}
		
		P = P->next;
	}
	printf("You should give a pointer in linked list!\n");
	return Current;
}

LINK insert(LINK node) {
 
  
	if (exist(node) == 1) {
		printf("The node %s already existed.\n", node->name);
		return Current;
	}

        LINK Prev;
	LINK P;
	
	if ( Current == Head ) {
		node->next = Current;
		Head = node;
		Current = node;
		
		return Current;
	}
	
	P = Head;
	while (P != NULL) {
		P = P->next;
	}
	Prev = P;
	Prev->next = node;
	node->next = Current;
	Current = node;
	
	return Current;
}

int exist(LINK node) {
	//move(Head);
        LINK P;
        P = Head;

	while (P != NULL) {
		if (P == node) {
			return 1;
		}
		P = P->next;
    }
    return 0;
}
