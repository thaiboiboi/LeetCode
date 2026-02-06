#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void RandomStringGenerator(char* code, int codeLength)
{
	char* box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int boxLength = strlen(box);

	for (int i = 0; i < codeLength; i++)
	{
		code[i] = box[rand() % boxLength];
	}
	code[codeLength] = '\0';
}

int main()
{
	srand(time(0));

	int length1 = 6;
	char code1[6 + 1];
	RandomStringGenerator(&code1[0], length1);
	printf("%s\n", code1);

	int length2 = 8;
	char* code2 = new char[length2 + 1];
	RandomStringGenerator(code2, length2);
	printf("%s\n", code2);
	delete[]code2;

	return 0;
}
