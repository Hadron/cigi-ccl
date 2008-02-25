/** <pre>
 *  This Class will process the Start-Of-Frame for the LCPS
 *  
 *  FILENAME:   SOFP.cpp
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    LCPS
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

#include "SOFP.h"

#include <CigiSOFV3_2.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// ================================================
// SOFP
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
SOFP::SOFP()
{

}

// ================================================
// ~SOFP
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
SOFP::~SOFP()
{

}


// ================================================
// OnPacketReceived
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
void SOFP::OnPacketReceived(CigiBasePacket *Packet)
{
	CigiSOFV3_2 *sof = (CigiSOFV3_2 *)(Packet);

   // We are actually not processing any information in the SOF
   // The incoming msg and host session are pulling out the version
   //   information
	
}

