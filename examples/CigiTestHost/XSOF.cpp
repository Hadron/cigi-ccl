// XSOF.cpp: Body of the XSOF class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "XSOF.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

XSOF::XSOF()
{

}

XSOF::~XSOF()
{

}


void XSOF::OnPacketReceived(CigiBasePacket *Packet)
{
CigiSOFV3_2 *InPckt = (CigiSOFV3_2 *)Packet;

   printf("DatabaseID ==> %d\n",InPckt->GetDatabaseID());
   printf("IGStatus ==> %d\n",InPckt->GetIGStatus());
   printf("IGMode ==> %d\n",InPckt->GetIGMode());
   printf("TimestampValid ==> %d\n",InPckt->GetTimeStampValid());
   printf("EarthRefModel ==> %d\n",InPckt->GetEarthRefModel());
   printf("FrameCntr ==> %d\n",InPckt->GetFrameCntr());
   printf("TimeStampV3 ==> %d\n",InPckt->GetTimeStamp());
   printf("Last Host FrameCntr ==> %d\n",InPckt->GetLastRcvdHostFrame());


}
