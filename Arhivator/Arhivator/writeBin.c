#include "myArchivator.h"


static void saveHuffmanTable(FILE* binCompress)
{
    fwrite(&count, sizeof(int32_t), 1, binCompress);
    for (int32_t i = 0; i < count; i++)
    {
        fputc(Table[i]->letter, binCompress);
        int32_t codeLen = strlen(Table[i]->code) + 1;
        fwrite(&codeLen, sizeof(int32_t), 1, binCompress);
        fwrite(Table[i]->code, sizeof(char), codeLen, binCompress);
    }
}

void writeBinFile(const char* text, const char* fileWhereDecoded)
{
    FILE* binCompress = fopen(fileWhereDecoded, "wb");
    if (binCompress == NULL)
    {
        printf("\n");
        printf("\n");
        printf("==========================================================\n");
        printf("||  Cannot open file where should be your decoded text  ||\n");
        printf("==========================================================\n");
        exit(1);
    }
    saveHuffmanTable(binCompress);
    int32_t cnt = strlen(text);
    unsigned char buffer = 0;
    int32_t bit_count = 0;
    for (int32_t i = 0; i < cnt; i++)
    {
        char symbol = text[i];
        char* letter = NULL;
        for (int32_t j = 0; j < count; j++)
        {
            if (symbol == Table[j]->letter)
            {
                letter = _strdup(Table[j]->code);
                break;
            }
        }
        if (letter == NULL)
        {
            continue; // по идее не должна сработать никогда
        }
        int32_t len = strlen(letter);
        for (int32_t k = 0; k < len; k++)
        {
            if (letter[k] == '1')
            {
                buffer |= (1 << (7 - bit_count)); // Устанавливаем бит в buffer
            }
            bit_count++;
            if (bit_count == 8)
            {
                fwrite(&buffer, 1, 1, binCompress); // Записываем байт в файл
                buffer = 0;
                bit_count = 0;
            }
        }
        free(letter);
    }
    if (bit_count > 0) // Записываем оставшиеся биты
    {
        fwrite(&buffer, 1, 1, binCompress);
    }
    fclose(binCompress);
}