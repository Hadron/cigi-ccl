/** <pre>
 *  This Class will process any unassigned packets
 *
 *  FILENAME:   DefaultProc.cpp
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
 *  04/29/2005 Greg Basler                       INIT
 *  Initial Release.
 *
 * </pre>
 *  Author: The Boeing Company
 *  Version: 0.1
 */


#include <iostream>

#include "DefaultProc.h"

#include <CigiDefaultPacket.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ================================================
// DefaultProc
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
DefaultProc::DefaultProc()
{

}

// ================================================
// ~DefaultProc
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
DefaultProc::~DefaultProc()
{

}


// ================================================
// OnPacketReceived
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void DefaultProc::OnPacketReceived(CigiBasePacket *Packet)
{
   unsigned char *buff = ((CigiDefaultPacket *)Packet)->GetDataPtr();
   cout << "Received an Umsupported packet: id " << hex << (int *)buff << endl;
}

