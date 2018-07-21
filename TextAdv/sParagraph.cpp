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
	// ù ������ ��, ù ������ �ƴ� �� ������ �ٸ���.
	if (NULL == _current)
	{
		// ù ���� (paragraph->current : ù ����)
		_current = string;	// ���� ���� ����
							//string->_prev = NULL;
							//string->_next = NULL;
		string->InitNode(NULL, NULL);
		_start = string;
	}
	else
	{
		// ù ���� �ƴ�
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
	// ���� ����� ������ ù �������� ����
	// (ù ���� ���� ���)
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
