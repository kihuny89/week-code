
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "sString.h"
#include "sParagraph.h"
#include "PrintLib.h"
#include "sParagraphList.h"



void sParagraphList::Create(int count)
{
	_count = count;
	_list = new sParagraph[_count];
}

void sParagraphList::Destroy()
{
	delete[] _list;
}

void sParagraphList::AddStringToList(int pNo, sString* newString)
{
	_list[pNo].AddString(newString);
}

int sParagraphList::Process(int select)
{

	if (select <_count)
	{
		printf("\n");

		return _list[select].Process();
	}
	return -1;
}