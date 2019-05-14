#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>

#include <string.h>

#include <stdio.h>
#include <stdlib.h>


void repl()
{
    char input[50];
	do {
        fgets(input, 50, stdin); 
        printf("%s\n", input); 
    } while (!(strlen(input) == 5 && memcmp(input, "exit", 4) == 0));
}


enum nat
{
    INTEGER,PLUS,MINUS,TIMES,DIV,MOD
};


struct token
{
    enum nat ident;
    int value;
};


typedef struct s_List List;
struct s_List
{
    List *next;
    void *data;
};





List* list_create(void *data)
{
    List *list;
    list->next = NULL;
    list->data = data;

    return list;
}

List* list_prepend(List *old, void *data)
{
    List *list = list_create(data);
    if (list)
       list->next = old;
    return list;
}


List* list_append(List *list, void *data)
{
    List **plist = &list;
    while (*plist)
       plist = &(*plist)->next;
    *plist = list_create(data);
    if (*plist)
       return list;
    else
       return NULL;
}

void printok(struct token x);
int member(char *liste,char c);
List* lex(char *entiers);


int main()
{

    char entiers[10] = "0123456789";
    List* tokens = lex(entiers);
    List **lect = &tokens;
	
    while (*lect != NULL)
    {
		void *x = &(*lect)->data;
		printok(*(struct token *)x);
		lect = &(*lect)->next;
    }
	
	repl();
    return 0;
}

void printok(struct token x)
{
    printf("%d",x.value);
}


int member(char *liste,char c)
{
    int k = -1;
    char *curseur;
    for (curseur = liste; *curseur != '\0'; curseur++)
    {
		if (*curseur == c)
		{
		   k = *curseur;
		}
    }
    return(*curseur);
}


List* lex(char *entiers)
{
    List *tokens = NULL;
    char input[50];
    char *curseur;
    fgets(input, 50, stdin);
    for (curseur = input; *curseur != '\0'; curseur++)
    {
	struct token *x;
        if ( member(entiers,*curseur) > 0)
	{
		(*x).ident = INTEGER;
		(*x).value = 0;
		while(member(entiers,*curseur) > 0)
			{
				(*x).value = 10*((*x).value) + member(entiers,*curseur);
				curseur++;
			}
		
		list_append(tokens,x);
	}

	else
	{
		switch(*curseur)
		{
		case('+'):
		(*x).ident = PLUS;
		break;

		case('-'):
		(*x).ident = MINUS;
		break;

		case('*'):
		(*x).ident = TIMES;
		break;

		case('/'):
		(*x).ident = DIV;
		break;

		case('%'):
		(*x).ident = MOD;
		break;
		}

		(*x).value = -1;
		list_append(tokens,x);
	}
    }
    return(tokens);
}










