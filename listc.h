/*
 * listc.h
 *
 *  Created on: Oct 31, 2018
 *      Author: yoram
 */

#ifndef LISTC_H_
#define LISTC_H_

typedef struct _lnode
{
	int				elements;		// Actual number of elements
	void 			*arr;			// Pointer to array of elements. Element can be of any type!
	struct _lnode	*next;			// Pointer to next node in the global list
} lnode;

typedef struct _list
{
	int				maxElements;	// Max number of elements in one lnode
	int				sizeOfElement;	// Size of an element in bytes
	int				nextElement;	// Used when scaning list for retrieving elements
	lnode			*current;		// Used when scaning list for retrieving elements
	lnode 			*first;			// Point to first elements lnode
	lnode 			*last;			// Points to last elelemnts lnode
} listHDR;

typedef listHDR *LIST;

LIST createList (const int initElements, const int sizeOfElement);
void deleteList (LIST *list);
void insertElement (const LIST list, const void *element);
int listElements (const LIST list, const void (*cfunc)(void *));
int getNextElement (const LIST list, void *val);
void resetList (const LIST list);

#endif /* LISTC_H_ */
