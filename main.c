/*
 * main.c
 *
 *  Created on: Oct 31, 2018
 *      Author: yoram
 */

#include <stdio.h>
#include "listc.h"

static int count;

void printInt (int *element)
{
	printf("[%d] - %d\n", count++, *element);
}

int main ()
{
	LIST list, list_c, list_d, list_s;
	int elements, i;
	int element;
	char element_c;
	double element_d;
	char str[30];


	// inint lists
	list = createList(1, sizeof(int));
	list_c = createList(1, sizeof(char));
	list_d = createList(1, sizeof(double));
	list_s = createList(1, sizeof(str));

	for (i = 0; i < 49; i++)
	{
		element = i;
		insertElement(list, &element);
	}

	// display list
	count = 1;
	elements = listElements(list, (void (*)(void *))&printInt);
	printf("---------\n");
	resetList(list);
	elements = 0;
	while (getNextElement(list, &element))
		printf("[%d] - %d\n", ++elements, element);

	printf("Total number of elemenets - %d\n", elements);

	for (i = 0; i < 51; i++)
	{
		element_c = i + ' ';
		insertElement(list_c, &element_c);
	}

	// display list
	resetList(list_c);
	elements = 0;
	while (getNextElement(list_c, &element_c))
		printf("[%d] - %c\n", ++elements, element_c);


	printf("Total number of elemenets - %d\n", elements);

	for (i = 0; i < 81; i++)
	{
		element_d = i * 1.1;
		insertElement(list_d, &element_d);
	}

	// display list
	resetList(list_d);
	elements = 0;
	while (getNextElement(list_d, &element_d))
		printf("[%d] - %f\n", ++elements, element_d);


	printf("Total number of elemenets - %d\n", elements);

	for (i = 0; i < 38; i++)
	{
		sprintf(str, "str (%d)", i);
		insertElement(list_s, str);
	}

	// display list
	resetList(list_s);
	elements = 0;
	while (getNextElement(list_s, str))
		printf("[%d] - %s\n", ++elements, str);


	printf("Total number of elemenets - %d\n", elements);


	deleteList(&list);
	deleteList(&list_c);
	deleteList(&list_d);
	deleteList(&list_s);

}
