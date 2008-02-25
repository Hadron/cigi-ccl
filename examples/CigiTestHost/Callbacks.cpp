// Callbacks.cpp: The call backs
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "AllCigi.h"
#include "Callbacks.h"




void YSOF(CigiBasePacket *Packet)
{
   printf("YSOF\n");
}
void YCollDetSegResp(CigiBasePacket *Packet)
{
   printf("YCollDetSegResp\n");
}

void YSensorResp(CigiBasePacket *Packet)
{
   printf("YSensorResp\n");
}

void YSensorXResp(CigiBasePacket *Packet)
{
   printf("YSensorXResp\n");
}

void YLosResp(CigiBasePacket *Packet)
{
   printf("YLosResp\n");
}

void YLosXResp(CigiBasePacket *Packet)
{
   printf("YLosXResp\n");
}

void YHatHotResp(CigiBasePacket *Packet)
{
   printf("YHatHotResp\n");
}

void YHatHotXResp(CigiBasePacket *Packet)
{
   printf("YHatHotXResp\n");
}

void YCollDetVolResp(CigiBasePacket *Packet)
{
   printf("YCollDetVolResp\n");
}

void YPositionResp(CigiBasePacket *Packet)
{
   printf("YPositionResp\n");
}

void YWeatherCondResp(CigiBasePacket *Packet)
{
   printf("YWeatherCondResp\n");
}

void YAerosolResp(CigiBasePacket *Packet)
{
   printf("YAerosolResp\n");
}

void YMaritimeSurfaceResp(CigiBasePacket *Packet)
{
   printf("YMaritimeSurfaceResp\n");
}

void YTerrestrialSurfaceResp(CigiBasePacket *Packet)
{
   printf("YTerrestrialSurfaceResp\n");
}

void YAnimationStop(CigiBasePacket *Packet)
{
   printf("YAnimationStop\n");
}

void YEventNotification(CigiBasePacket *Packet)
{
   printf("YEventNotification\n");
}

void YIGMsg(CigiBasePacket *Packet)
{
   printf("YIGMsg\n");
}

void YDeflt(CigiBasePacket *Packet)
{
   printf("YDeflt\n");
}






