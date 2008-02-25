// ParseValue.h: interface for the ParseValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSEVALUE_H__57CC0107_2674_49FA_A326_8E383F2E1735__INCLUDED_)
#define AFX_PARSEVALUE_H__57CC0107_2674_49FA_A326_8E383F2E1735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ParseLine;

#include "ParseLine.h"

class ParseValue  
{
friend class ParseLine;

public:
	void SetDta(char *buf);
	ParseValue();
	virtual ~ParseValue();

   char *GetStr() { return(dta); }
	unsigned char GetUChar();
	char GetChar();
	unsigned short GetUShort();
	short GetShort();
	unsigned long GetULong();
	long GetLong();
	float Getfloat();
	double Getdouble();
   bool GetBool();


   ParseValue * nxt() { return(Next); }



protected:
	char dta[255];
   ParseValue * Next;

};

#endif // !defined(AFX_PARSEVALUE_H__57CC0107_2674_49FA_A326_8E383F2E1735__INCLUDED_)
