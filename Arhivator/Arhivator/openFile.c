#include "myArchivator.h"

// Функция для чтения текста из файла
char* readTextFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("\n");
        printf("\n");
        printf("==========================================================\n");
        printf("||  Cannot open file with text that need to be decoded  ||\n");
        printf("==========================================================\n");
        exit(1);
    }
    // Буфер для временного хранения данных
    int32_t bufferSize = 1024;
    char* buffer = (char*)malloc(bufferSize);
    if (buffer == NULL)
    {
        printf("\n");
        printf("\n");
        printf("==========================================================================================================\n");
        printf("||  Memory management error: Cannot locate memory when opening file. Check openFile.c for more details  ||\n");
        printf("==========================================================================================================\n");
        fclose(file);
        exit(1);
    }
    char* fileContent = NULL;
    int32_t totalSize = 0;
    int32_t bytesRead;
    while ((bytesRead = fread(buffer, 1, bufferSize, file)) > 0)
    {
        char* temp = realloc(fileContent, totalSize + bytesRead + 1);
        if (temp == NULL)
        {
            printf("\n");
            printf("\n");
            printf("==========================================================================================================\n");
            printf("||  Memory management error: Cannot locate memory when opening file. Check openFile.c for more details  ||\n");
            printf("==========================================================================================================\n");
            free(buffer);
            free(fileContent);
            fclose(file);
            exit(1);
        }
        fileContent = temp;
        memcpy(fileContent + totalSize, buffer, bytesRead);
        totalSize += bytesRead;
    }
    free(buffer);
    if (fileContent != NULL)
    {
        fileContent[totalSize] = '\0';
    }
    fclose(file);
    return fileContent;
}