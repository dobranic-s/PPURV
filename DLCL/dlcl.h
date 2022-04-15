/*
 * dlcl.h
 *
 *  Created on: Oct 21, 2021
 *      Author: rtrk
 */

#ifndef DLCL_H_
#define DLCL_H_

#include <stdint.h>

typedef struct DoubleLinkedCircularListData
{
	int_least8_t data;
	struct DoubleLinkedCircularListData* prev;
	struct DoubleLinkedCircularListData* next;

} DLCLData;

typedef struct DoubleLinkedList
{
	struct DoubleLinkedCircularListData* head;
	struct DoubleLinkedCircularListData* tail;
} DLL;

void DoubleLinkedListCreate(DLL* list);
void DoubleLinkedListInsert(DLL* list, int_least8_t new_data);
void DoubleLinkedListPrint(const DLL* list);
void DoubleLinkedListDelete(const DLL* list, DLCLData* temp);
void FunctionPrintNthElement(DLL* list, int_least8_t x, int_least8_t y);

#endif /* DLCL_H_ */
