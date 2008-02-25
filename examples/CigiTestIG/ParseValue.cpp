// ParseValue.cpp: implementation of the ParseValue class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>


#include "ParseValue.h"
#include "stdlib.h"
#include "string.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ParseValue::ParseValue()
{
   memset(dta,0,255);
   Next = NULL;
}

ParseValue::~ParseValue()
{

}


unsigned char ParseValue::GetUChar()
{
   int t = atoi(dta);

   unsigned char tuc = (unsigned char)t;

   return(tuc);
}

char ParseValue::GetChar()
{
   int t = atoi(dta);

   char tc = (char)t;

   return(tc);
}

unsigned short ParseValue::GetUShort()
{
   int t = atoi(dta);

   unsigned short tus = (unsigned short)t;

   return(tus);
}

short ParseValue::GetShort()
{
   int t = atoi(dta);

   short ts = (short)t;

   return(ts);
}

unsigned long ParseValue::GetULong()
{
   union cnvt {
      long l;
      unsigned long ul;
   } td;

   td.l = atol(dta);

   return(td.ul);
}

long ParseValue::GetLong()
{
   return(atol(dta));
}

float ParseValue::Getfloat()
{
   double td = atof(dta);
   float tf = (float)td;
   return(tf);
}

double ParseValue::Getdouble()
{
   return(atof(dta));
}

bool ParseValue::GetBool()
{
   bool rslt = false;

   if((dta[0] == 'T')||(dta[0] == 't'))
      rslt = true;

   return(rslt);
}



void ParseValue::SetDta(char *buf)
{
   strcpy(dta,buf);
}
