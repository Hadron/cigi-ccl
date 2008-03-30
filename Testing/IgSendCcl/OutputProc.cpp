// OutputProcessor.cpp: implementation of the OutputProcessor class.
//
//////////////////////////////////////////////////////////////////////


#include "StdAfx.h"


#ifndef _WIN32
    #include <fstream>
#elif _MSC_VER > 1300
    #include <fstream>
#else
    #include <fstream.h>
#endif


#include "PcktParsingProcessor.h"
#include "ParseLine.h"
#include "ParseValue.h"

#include "OutputProc.h"

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


OutputProcessor::OutputProcessor()
{

   CrntSession = NULL;
   OmsgPtr = NULL;
   HPrsLn = NULL;

   CsvFile = "HostData.csv";

   TstID = 0;

}




OutputProcessor::~OutputProcessor()
{

   if(HPrsLn != NULL)
      delete HPrsLn;

   list<PcktParsingProcessor *>::iterator iPrs;
   for(iPrs=Parsers.begin();iPrs!=Parsers.end();iPrs++)
   {
      if(*iPrs != NULL)
         delete *iPrs;
   }
   Parsers.clear();

}




void OutputProcessor::Init(CigiSession *CrntSessionIn,
                           string &CsvFileNm,
                           int MajorVer,
                           int MinorVer)
{

   CrntSession = CrntSessionIn;
   CigiOutgoingMsg &Omsg = CrntSession->GetOutgoingMsgMgr();
   OmsgPtr = &Omsg;

   list<PcktParsingProcessor *>::iterator iPrs;
   for(iPrs=Parsers.begin();iPrs!=Parsers.end();iPrs++)
   {
      (*iPrs)->Init(OmsgPtr);
   }

   HPrsLn = new ParseLine;

   TstID = 0;

   if(!CsvFileNm.empty())
      CsvFile = CsvFileNm;

}



bool OutputProcessor::Out()
{
   static ifstream Hinfl(CsvFile.c_str(),ios::in);

   bool Valid = true;

   if(Hinfl.is_open() != 0)
   {

      if(!Hinfl.eof())
      {
         Hinfl.getline(line,511);

         if(line[0] != 0)
         {
            HPrsLn->ParseBuf(line);

            ProcLine(*HPrsLn);

         }
      }
      else
      {
         Hinfl.close();
         Valid = false;
      }

   }
   else
      Valid = false;

   return(Valid);

}



void OutputProcessor::ProcLine(ParseLine &PrsLn)
{


   if(OmsgPtr == NULL)
      return;

   TstID++;
   printf("\n\n================================\nIG Output Test No. %d\nvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n",TstID);

   ParseValue *pPV = PrsLn.Get1stVal();
   string CmpStr = pPV->GetStr();


   list<PcktParsingProcessor *>::iterator iPrs;
   for(iPrs=Parsers.begin();iPrs!=Parsers.end();iPrs++)
   {
      if(*((*iPrs)->GetPcktID()) == (char *)pPV->GetStr())
      {
         (*iPrs)->ProcPckt(pPV);
         break;
      }
   }

   printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

}







