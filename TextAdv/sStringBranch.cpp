#include "sStringBranch.h"
#include <conio.h>

sStringBranch::sStringBranch() 
{

}
sStringBranch::~sStringBranch()
{

}

int sStringBranch::process()
{
	Print();
	int select = -1;
	while (true)
	{
		char ch = _getche();
		if ('y' == ch || 'Y' == ch)
		{
			select = GetSelectY();
		}
		else if ('n' == ch || 'N' == ch)
		{
			select = GetSelectN();
		}
		else if ('q' == ch || 'Q' == ch || 27 == ch)	// 27 : ESC
		{
			select = -1;
			break;	// Á¾·á
		}
	}
	return select;
}