// ParseLine.h: interface for the ParseLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARSELINE_H__A40EAAC5_829E_43DF_A3FD_03C9D565A6EB__INCLUDED_)
#define AFX_PARSELINE_H__A40EAAC5_829E_43DF_A3FD_03C9D565A6EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ParseValue;

#include "ParseValue.h"

class ParseLine  
{
public:
	ParseLine();
	ParseLine(char *Buff);
	virtual ~ParseLine();



	void ParseBuf(char *Buff);

   ParseValue * Get1stVal() { return(Val1); }
	void Clear();
   int GetValCnt() { return(ValCnt); }






protected:
	int ValCnt;
	ParseValue * Val1;
};

#endif // !defined(AFX_PARSELINE_H__A40EAAC5_829E_43DF_A3FD_03C9D565A6EB__INCLUDED_)
