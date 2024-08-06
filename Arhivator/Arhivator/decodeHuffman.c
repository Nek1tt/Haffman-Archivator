#include "myArchivator.h"

int32_t countTable = 0;

static void loadTable(FILE* file)
{
    fread(&countTable, sizeof(int32_t), 1, file);
    Table = (List**)malloc(countTable * sizeof(List*));
    if (Table == NULL)
    {
        printf("\n");
        printf("\n");
        printf("===================================================================================================================\n");
        printf("||  Memory management error: Cannot locate memory when loading a Table. Check decodeHuffman.c for more details.  ||\n");
        printf("===================================================================================================================\n");
        exit(1);
    }
    for (int32_t i = 0; i < countTable; i++)
    {
        Table[i] = (List*)malloc(sizeof(List));
        if (Table[i] == NULL)
        {
            printf("\n");
            printf("\n");
            printf("===================================================================================================================\n");
            printf("||  Memory management error: Cannot locate memory when loading a Table. Check decodeHuffman.c for more details.  ||\n");
            printf("===================================================================================================================\n");
            exit(1);
        }
        Table[i]->letter = fgetc(file);
        int32_t codeLen;
        fread(&codeLen, sizeof(int32_t), 1, file);
        Table[i]->code = (char*)malloc(codeLen * sizeof(char));
        if (Table[i]->code == NULL)
        {
            printf("\n");
            printf("\n");
            printf("===================================================================================================================\n");
            printf("||  Memory management error: Cannot locate memory when loading a Table. Check decodeHuffman.c for more details.  ||\n");
            printf("===================================================================================================================\n");
            exit(1);
        }
        fread(Table[i]->code, sizeof(char), codeLen, file);
    }
}

static void freeHuffmanTable()
{
    for (int32_t i = 0; i < countTable; i++)
    {
        free(Table[i]->code);
        free(Table[i]);
    }
    free(Table);
}

void decodeHuffman(const char* filenameWhereDecoded, const char* filenameToDecode)
{
    FILE* fileToDecode = fopen(filenameWhereDecoded, "rb");
    if (fileToDecode == NULL)
    {
        printf("\n");
        printf("\n");
        printf("==========================================================\n");
        printf("||  Cannot open file where should be your decoded text  ||\n");
        printf("==========================================================\n");
        exit(1);
    }
    loadTable(fileToDecode);
    FILE* outputFile = fopen(filenameToDecode, "w");
    if (outputFile == NULL)
    {
        printf("\n");
        printf("\n");
        printf("============================================================\n");
        printf("||  Cannot open file where should be your undecoded text  ||\n");
        printf("============================================================\n");
        fclose(fileToDecode);
        exit(1);
    }
    unsigned char buffer;
    char bitString[256] = { 0 };
    int32_t bitStringLen = 0;
    while (fread(&buffer, 1, 1, fileToDecode) == 1)
    {
        for (int32_t i = 0; i < 8; i++)
        {
            bitString[bitStringLen++] = (buffer & (1 << (7 - i))) ? '1' : '0';
            bitString[bitStringLen] = '\0';
            for (int32_t j = 0; j < countTable; j++)
            {
                if (strcmp(bitString, Table[j]->code) == 0)
                {
                    fputc(Table[j]->letter, outputFile);
                    bitStringLen = 0;
                    bitString[0] = '\0';
                    break;
                }
            }
        }
    }
    fclose(outputFile);
    fclose(fileToDecode);
    freeHuffmanTable();
}