/** <pre>
 *  This Class will process the "Animation Stop Event Notification"
 *  
 *  FILENAME:   AnimStop.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    CIGI
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  06/20/2005 Alex Storms                       INIT
 *  Initial Release.
 *  
 * </pre>
 *  Author: The Boeing Company
 *  Version: 0.1
 */
#include <iostream>

#include "AnimStop.h"

#include <CigiAnimationStopV3.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ================================================
// AnimStop
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AnimStop::AnimStop()
{
	StopID = 0;
}

// ================================================
// ~AnimStop
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
AnimStop::~AnimStop()
{

}


// ================================================
// OnPacketReceived
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void AnimStop::OnPacketReceived(CigiBasePacket *Packet)
{
	CigiAnimationStopV3 *stop = (CigiAnimationStopV3 *)(Packet);

	StopID = stop->GetEntityID();
   
}

void AnimStop::clearStopID()
{
	StopID = 0;
}

Cigi_uint16 AnimStop::getStopID()
{
	return StopID;
}


