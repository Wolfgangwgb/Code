#include "commentconvert.h"


void Commentconvert()
{
	FILE *pfRead = NULL;
	FILE *pfWrite = NULL;
	pfRead = fopen("input.c","r");
	if(pfRead == NULL)
	{
		perror("open file for input:");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen("output.c","w");
	if(pfRead == NULL)
	{
		perror("open file for output:");
		fclose(pfRead);
		exit(EXIT_FAILURE);
	}
	Docommentconvert(pfRead,pfWrite);
	fclose(pfRead);
	fclose(pfWrite);

}


int main()
{
	Commentconvert();
	system("pause");
	return 0;
}