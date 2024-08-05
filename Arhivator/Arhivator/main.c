#include "myArchivator.h"

int main(int argc, char** argv)
{
    printf("Welcome to Nek1t_'s cool Archivator.\n");
    printf("My Archivator can do:\n");
    printf("1 - Archive data\n");
    printf("2 - Dearchive data\n");
    printf("Your choice? :D (type 1 or 2)\n");
    int32_t UserChoose;
    scanf("%d", &UserChoose);
    // введите 2 пути (первый - текст, второй - заархивированный) и передать его в функцию, 1 - архивация
    if (UserChoose == 1)
    {
        printf("Good Choice :0\n");
        printf("Please write your path to File that need to be decoded\n");
        const char filepath[100];
        scanf("%s", &filepath);
        printf("Please write your path to File where should be your decoded text\n");
        const char filePathDecoded[100];
        scanf("%s", &filePathDecoded);
        Compress(filepath, filePathDecoded);
        printf("\n");
        printf("\n");
        printf("=========================================================\n");
        printf("Your file is decoded and stays here\n");
        printf("%s\n", filePathDecoded);
        
    }
    // введите 2 пути (первый - откуда деархивировать) (второй - куда деархивировать) и передать его в функцию, 2 - деорхивация
    else if (UserChoose == 2)
    {
        printf("Good Choice :0\n");
        printf("Please write your path to File where lies decodedFile\n");
        const char filepathDecoded[100];
        scanf("%s", &filepathDecoded);
        printf("Please write your path to File where should be Your undecoded text\n");
        const char filePath[100];
        scanf("%s", &filePath);
        decodeHuffman(filepathDecoded, filePath);
        printf("\n");
        printf("\n");
        printf("=========================================================\n");
        printf("Your file is undecoded and stays here\n");
        printf("%s\n", filePath);
    }
    else
    {
        printf("Your choise is not good. I'm leaving");
        return 1;
    }
    printf("Thank you for using my very cool archivator\n");
    printf("=========================================================\n");
    return 0;
}
