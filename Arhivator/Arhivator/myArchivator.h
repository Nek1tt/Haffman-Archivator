#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int32_t freq;
    char letter;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct List {
    char* code;
    char letter;
} List;

extern int32_t count;
extern int32_t size;
int32_t frequency[256];
char* readTextFile(const char* filename);
void Compress(const char* fileToDecode, const char* fileWhereDecoded);
void freq(char* str);
void insertSort();
void addElement(Node* item);
void CreateTable(Node* queue, char* before, char* now);
void writeBinFile(const char* text, const char* fileWhereDecoded);
void freeQueue();
void decodeHuffman(const char* filenameWhereDecoded, const char* filenameToDecode);
List** Table;
Node** queue;
Node* newNode(char letter, int32_t freq);
Node* delElement();
