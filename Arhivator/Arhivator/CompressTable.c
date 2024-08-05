#include "myArchivator.h"

static int32_t TableCount = 0;

void CreateTable(Node* queue, char* before, char* now)
{
	char* copy = _strdup(before);
	copy = strcat(copy, now);
	if (queue->letter == NULL)
	{
		CreateTable(queue->left, copy, "0");
		CreateTable(queue->right, copy, "1");
	}
	else
	{
		Table[TableCount]->letter = queue->letter;
		Table[TableCount]->code = copy;
		TableCount++;
	}
}