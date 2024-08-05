#include "myArchivator.h"

static void swap(Node** first, Node** second)
{
	Node* temp = *first;
	*first = *second;
	*second = temp;
}

void insertSort() 
{
	for (int32_t i = 1; i < size; i++)
	{
		for (int32_t j = i; j > 0 && queue[j - 1]->freq > queue[j]->freq; j--)
		{
			swap(&queue[j], &queue[j - 1]);
		}
	}
}