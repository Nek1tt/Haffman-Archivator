#include "myArchivator.h"

void Compress(const char* fileToDecode, const char* fileWhereDecoded)
{
	char* fileContent = readTextFile(fileToDecode);
	freq(fileContent);
	for (int32_t i = 0; i < 256; i++)
	{
		if (frequency[i] != 0)
		{
			Node* NodeBinary = newNode(i, frequency[i]);
			addElement(NodeBinary);
		}
	}
	while (size > 1)
	{
		Node* first = delElement();
		Node* second = delElement();
		Node* MyNewTree = newNode(NULL, first->freq + second->freq);
		if (first->freq >= second->freq)
		{
			MyNewTree->left = second;
			MyNewTree->right = first;
		}
		else
		{
			MyNewTree->left = first;
			MyNewTree->right = second;
		}
		addElement(MyNewTree);
	}
	Table = (List**)malloc(count * sizeof(List*));
	if (Table == NULL)
	{
		printf("\n");
		printf("\n");
		printf("==============================================================================================================\n");
		printf("||  Memory management error: Cannot locate memory when creating the table. See Compress.c for more details  ||\n");
		printf("==============================================================================================================\n");
		exit(1);
	}
	for (int32_t i = 0; i < count; i++)
	{
		Table[i] = (List*)malloc(sizeof(List));
		Table[i]->code = malloc(100 * sizeof(char));
		if (Table[i] == NULL || Table[i]->code == NULL)
		{
			printf("\n");
			printf("\n");
			printf("==============================================================================================================\n");
			printf("||  Memory management error: Cannot locate memory when creating the table. See Compress.c for more details  ||\n");
			printf("==============================================================================================================\n");
			exit(1);
		}
	}
	char code[100] = "";
	char before[100] = "";
	Node* Tree = queue[0];
	CreateTable(Tree, code, before);
	writeBinFile(fileContent, fileWhereDecoded);
	freeQueue();
}
