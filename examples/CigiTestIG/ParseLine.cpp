// ParseLine.cpp: implementation of the ParseLine class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>

#include "ParseLine.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ParseLine::ParseLine()
{
   Val1 = NULL;
   ValCnt = 0;
}

ParseLine::ParseLine(char *Buff)
{
   Val1 = NULL;
   ValCnt = 0;

   ParseBuf(Buff);
}

ParseLine::~ParseLine()
{
   Clear();
}


void ParseLine::Clear()
{
   ParseValue *Crnt;
   ParseValue *Nxt;

   Crnt = Val1;
   while(Crnt != NULL)
   {
      Nxt = Crnt->nxt();
      delete Crnt;
      Crnt = Nxt;
   }

   Val1 = NULL;

}

void ParseLine::ParseBuf(char *Buff)
{
   char tbuf[255];

   char *p = Buff;
   char *b = tbuf;

   bool go = true;

   ParseValue *cVal = new ParseValue;
   Val1 = cVal;

   ValCnt = 1;

   while(go)
   {
      switch(*p)
      {
      case ',':
         *b = 0;
         cVal->SetDta(tbuf);
         cVal->Next = new ParseValue;
         cVal = cVal->Next;
         b = tbuf;
         ValCnt++;
         break;
      case 0x0a:
      case 0x0d:
      case 0:
         go = false;
         *b = 0;
         cVal->SetDta(tbuf);
         cVal->Next = NULL;
         break;
      default:
         *b++ = *p;
         break;
      }

      p++;
   }


}

