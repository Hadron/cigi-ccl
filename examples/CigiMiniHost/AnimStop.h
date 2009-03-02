#if !defined(_AnimStop_INCLUDED_)
#define _AnimStop_INCLUDED_

#include <CigiBaseEventProcessor.h>


//=========================================================
//! The base class for the Animation Stop Event Packet Processing
//!
class AnimStop : public CigiBaseEventProcessor
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   AnimStop();

   //=========================================================
   //! General Destructor
   //!
   virtual ~AnimStop();



   //==> Incoming Packet Processing

   //=========================================================
   //! The callback handler for the CIGI Animation Stop packet
   //! \param Packet - The pointer to the Animation Stop packet object.
   //!
   virtual void OnPacketReceived(CigiBasePacket *Packet);

   void clearStopID();

   Cigi_uint16 getStopID();

private:
	Cigi_uint16 StopID;

};

#endif // !defined(_AnimStop_INCLUDED_)
