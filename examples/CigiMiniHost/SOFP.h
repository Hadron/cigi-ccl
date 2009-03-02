/** <pre>
 *  This Class will process the Start-Of-Frame
 *  
 *  FILENAME:   SOFP.h
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

#if !defined(_SOFP_INCLUDED_)
#define _SOFP_INCLUDED_

#include <CigiBaseEventProcessor.h>


//=========================================================
//! The base class for the SOF Event Packet Processing
//!
class SOFP : public CigiBaseEventProcessor
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   SOFP();

   //=========================================================
   //! General Destructor
   //!
   virtual ~SOFP();



   //==> Incoming Packet Processing

   //=========================================================
   //! The callback handler for the CIGI SOF packet
   //! \param Packet - The pointer to the SOF packet object.
   //!
   virtual void OnPacketReceived(CigiBasePacket *Packet);

};

#endif // !defined(_SOFP_INCLUDED_)
