/** <pre>
 *  This Class will process any unassigned packets
 *
 *  FILENAME:   DefaultProc.h
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

#if !defined(_DEFAULT_PACKET_PROCESSING_INCLUDED_)
#define _DEFAULT_PACKET_PROCESSING_INCLUDED_

#include <CigiBaseEventProcessor.h>

using namespace std;


//=========================================================
//! The base class for the SOF Event Packet Processing
//!
class DefaultProc : public CigiBaseEventProcessor
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   DefaultProc();

   //=========================================================
   //! General Destructor
   //!
   virtual ~DefaultProc();




   //==> Incoming Packet Processing

   //=========================================================
   //! The default callback handler for the CIGI
   //! \param Packet - The pointer to the default packet object.
   //!
   virtual void OnPacketReceived(CigiBasePacket *Packet);



};

#endif // !defined(_DEFAULT_PACKET_PROCESSING_INCLUDED_)



