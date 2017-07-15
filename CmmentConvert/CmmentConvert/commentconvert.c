#include "commentconvert.h"


enum State state = NUL_STATE;

void DoNulState(FILE* pfIn,FILE* pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	if(first == '/')
	{
		second = fgetc(pfIn);
		if(second == '*')
		{
			fputc(first,pfOut);
			fputc('/',pfOut);
			state = C_STATE;
		}
		else if(second == '/')
		{
			fputc(first,pfOut);
			fputc(second,pfOut);
			state = CPP_STATE;
		}
		else
		{
			fputc(first,pfOut);
			fputc(second,pfOut);
		}
	}
	else if(first == EOF)
	{
		fputc(first,pfOut);
		state = END_STATE;
	}
	else
	{
		fputc(first,pfOut);
	}
}
void DoCState(FILE* pfIn,FILE* pfOut)
{
	int first = 0;
	int second = 0;
	int third = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	first = fgetc(pfIn);
	if(first == '*')
	{
		second = fgetc(pfIn);
		if(second == '/')
		{
			third = fgetc(pfIn);
			state = NUL_STATE;
			if(third != '\n')
			{
				fputc('\n',pfOut);
                ungetc(third,pfIn);
			}
			else
			{
				ungetc(third,pfIn);
				fputc('\n',pfOut);
			}
		}
		else if(second == '*')
		{
			
		    four = fgetc(pfIn);
			if(four == '*')
			{
				five = fgetc(pfIn);
				if(five == '/')
				{
					six = fgetc(pfIn);
					state = NUL_STATE;
					if(six == '\n')
					{
						ungetc(six,pfIn);
						fputc(six,pfOut);
						fputc('\n',pfOut);
					}
					else
					{
						ungetc(six,pfIn);
						fputc('\n',pfOut);
					}
				}
			}
			ungetc(second,pfIn);
		}
		else
		{
			fputc(first,pfOut);
			ungetc(second,pfIn);
		}
	}
	else if(first == '\n')
	{
		fputc(first,pfOut);
		fputc('/',pfOut);
		fputc('/',pfOut);
	}
	else
	{
		fputc(first,pfOut);
	}
}
void DoCppState(FILE* pfIn,FILE* pfOut)
{
	int first = 0;
	first = fgetc(pfIn);
	if(first == '\n')
	{
		fputc(first,pfOut);
		state = NUL_STATE;
	}
	else if(first == EOF)
	{
		fputc(first,pfOut);
		state = END_STATE;
	}
	else
	{
		fputc(first,pfOut);
	}
}

void Docommentconvert(FILE* pfIn,FILE* pfOut)
{
	while(state != END_STATE)
	{
		switch(state)
		{
		case NUL_STATE:
			DoNulState(pfIn,pfOut);
			break;
		case C_STATE:
			DoCState(pfIn,pfOut);
			break;
		case CPP_STATE:
			DoCppState(pfIn,pfOut);
			break;
		default:
			break;
		}
	}
}
