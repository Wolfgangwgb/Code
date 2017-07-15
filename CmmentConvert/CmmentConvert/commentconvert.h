#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>



enum State
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};



void Docommentconvert(FILE *pfIn,FILE *pfOut);

void DoNulState(FILE* pfIn,FILE* pfOut);
void DoCState(FILE* pfIn,FILE* pfOut);
void DoCppState(FILE* pfIn,FILE* pfOut);








#endif//__COMMENT_CONVERT_H__