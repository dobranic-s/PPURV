/*
 * dlcl.c
 *
 *  Created on: Oct 21, 2021
 *      Author: rtrk
 */

#include "dlcl.h"
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>	/* Zbog "warning: implicit declaration of function ‘malloc’" */

void DoubleLinkedListCreate(DLL* list)
{
	list->head = (DLCLData*)NULL;
	list->tail = (DLCLData*)NULL;
}

void DoubleLinkedListInsert(DLL* list, int_least8_t new_data)
{
	DLCLData* element  = malloc(sizeof(DLCLData));
	element->data = new_data;
	if (list->head == NULL)
	{
		list->head = element;
		list->tail = element;
		element->next = list->head;
		element->prev = list->head;
	}
	else
	{
		list->tail->next = element;
		element->prev = list->tail;
		element->next = list->head;
		list->head->prev = element;
		list->tail = element;
	}
}

void DoubleLinkedListPrint(const DLL* list)
{
	DLCLData* temp1;
	temp1 = list->head;

	if (list->head == NULL)
	{
		printf("Lista je prazna!\n");
	}
	else
	{
		while(temp1 != list->tail)
		{
			printf("%"PRIdLEAST8"\n", temp1->data);
			temp1 = temp1->next;
		}
		printf("%"PRIdLEAST8"\n", temp1->data);
	}
}

void DoubleLinkedListDelete(DLL* list, DLCLData* temp)
{
	int_least8_t oneElement = 0;
	if (list->head == list->tail) {
		oneElement = 1;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	if (list->head == temp) {
		list->head = temp->next;
	}
	if (list->tail == temp) {
		list->tail = temp->prev;
	}

	printf("%"PRIdLEAST8"\n", temp->data);
	free(temp);

	if (oneElement == 1) {
		list->head = NULL;
		list->tail = NULL;
	}

}

void FunctionPrintNthElement(DLL* list, int_least8_t x)
{
	DLCLData* temp2;
	DLCLData temp3;
	int_least8_t i;
	temp2 = list->head;
	temp3 = *temp2;
	while (list->head != NULL)
	{
		temp2 = &temp3;
		for (i = 0; i < x; i++)
		{
			temp2 = temp2->next;
		}
		
		temp3 = *temp2;
		
		DoubleLinkedListDelete(list, temp2);

		/*y--;

		if (y==0)
		{
			list->head = (DLCLData*)NULL;
			break;
		}*/
		if (list->head == NULL) 
		{
			break;
		}
		temp2 = &temp3;
		for (i = 0; i < x; i++)
		{
			temp2 = temp2->prev;
		}

		temp3 = *temp2;
		DoubleLinkedListDelete(list, temp2);



	}

	printf("Svi elementi su izbaceni iz liste.\n");
}

