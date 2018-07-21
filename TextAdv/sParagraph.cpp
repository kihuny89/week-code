#include <stdio.h>
#include "sParagraph.h"
#include "sString.h"
#include <conio.h>


sParagraph::sParagraph()
{
	_current = NULL;
}
sParagraph::~sParagraph()
{
	_current = _start;
	while (NULL != _current)
	{
		sString* nextStirng = _current->GetNext();
		delete _current;
		_current = nextStirng;
	}
}



void sParagraph::AddString(sString* string)
{
	// 첫 문장일 때, 첫 문장이 아닐 때 세팅이 다르다.
	if (NULL == _current)
	{
		// 첫 문장 (paragraph->current : 첫 문장)
		_current = string;	// 현재 문장 세팅
							//string->_prev = NULL;
							//string->_next = NULL;
		string->InitNode(NULL, NULL);
		_start = string;
	}
	else
	{
		// 첫 문장 아님
		//paragraph->current->_next = string;
		_current->SetNext(string);

		//string->_prev = paragraph->current;
		//string->_next = NULL;
		string->InitNode(_current, NULL);
		_current = string;
	}
}

int sParagraph::Process()
{
	int nextSelect =0;
	// 현재 출력할 문장을 첫 문장으로 세팅
	// (첫 문장 부터 출력)
	_current = _start;
	while (NULL != _current)
	{
		/*
		switch (_current->GetType())
		{
		case TEXT:
			//_current->Print();
			nextSelect =_current->Process();
			break;
		case BRANCH:
			nextSelect =_current->Process();
			
			break;
		case QUIT:
			nextSelect = _current->Process();
		
			break;
		}
		*/
		nextSelect = _current->Process(); 
		_current = _current->GetNext();
	}

	return nextSelect;
}
