#include "myArchivator.h"

int32_t count = 0;

void freq(char* str)
{
	for (int32_t i = 0; i < strlen(str); i++)
	{
		if (frequency[str[i]] == 0)
		{
			count++;
		}
		frequency[str[i]] += 1;
	}
}