/** <pre>
 *  The SDK is used to create and format CIGI compliant messages.
 *  Copyright (c) 2001-2005 The Boeing Company
 *  
 *  This library is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU Lesser General Public License as published by 
 *  the Free Software Foundation; either version 2.1 of the License, or (at 
 *  your option) any later version.
 *  
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more 
 *  details.
 *  
 *  You should have received a copy of the GNU Lesser General Public License 
 *  along with this library; if not, write to the Free Software Foundation, 
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *  
 *  FILENAME:   CigiEventList.h
 *  LANGUAGE:   C++
 *  CLASS:      UNCLASSIFIED
 *  PROJECT:    Common Image Generator Interface (CIGI) SDK
 *  
 *  PROGRAM DESCRIPTION: 
 *  ...
 *  
 *  MODIFICATION NOTES:
 *  DATE     NAME                                SCR NUMBER
 *  DESCRIPTION OF CHANGE........................
 *  
 *  09/17/2003 Greg Basler                       CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declaration for exporting the 
 *  class in a Windows DLL.
 * </pre>
 *  Author: The Boeing Company
 *  Version: 1.7.5
 */

#if !defined(_CIGI_EVENT_LIST_INCLUDED_)
#define _CIGI_EVENT_LIST_INCLUDED_

#include "CigiBaseEventProcessor.h"
#include "CigiBaseSignalProcessing.h"


//=========================================================
//! The formatting definition for all static callback functions
//!
typedef void (* CigiCBProcessor)(CigiBasePacket *Packet);


//=========================================================
//! The list class to link packet handling classes or routines
//!
class CIGI_SPEC CigiEventList  
{
public:

   //==> Management

   //=========================================================
   //! General Constructor
   //!
   CigiEventList();

   //=========================================================
   //! General Destructor
   //!
	virtual ~CigiEventList();




   //==> Accessing Member Variable Values functions

   //+> Event Processor

   //=========================================================
   //! Sets the pointer to this list node's Event object.
   //! \param EventIn - A pointer to this node's Event object.
   //!
   void SetCigiEvent(CigiBaseEventProcessor *EventIn) { Event = EventIn; }

   //=========================================================
   //! Gets the pointer to this list node's Event object.
   //! \return Event - A pointer to this node's Event object.
   //!
   CigiBaseEventProcessor *GetCigiEvent(void) { return(Event); }


   //+> Callback Processor

   //=========================================================
   //! Sets the pointer to this list node's static callback function.
   //! \param CallBackIn - A pointer to this node's static callback function.
   //!
   void SetCigiCallBack(CigiCBProcessor CallBackIn) { CallBack = CallBackIn; }

   //=========================================================
   //! Gets the pointer to this list node's static callback function.
   //! \return CallBack - A pointer to this node's Event object.
   //!
   CigiCBProcessor GetCigiCallBack(void) { return(CallBack); }


   //+> Signal Processor

   //=========================================================
   //! Sets the pointer to this list node's Signal object.
   //! \param SignalIn - A pointer to this node's Signal object.
   //!
   void SetCigiSignal(CigiBaseSignalProcessing *SignalIn) { Signal = SignalIn; }

   //=========================================================
   //! Gets the pointer to this list node's Signal object.
   //! \return Signal - A pointer to this node's Signal object.
   //!
   CigiBaseSignalProcessing *GetCigiSignal(void) { return(Signal); }


   //+> Next List Node Link


   //=========================================================
   //! Sets this node's link pointer to the next node.
   //! \param NextEventIn - A pointer to the next node.
   //!
   void SetNextEvent(CigiEventList *NextEventIn) { NextEvent = NextEventIn; }

   //=========================================================
   //! Gets the pointer to the next node.
   //! \return NextEvent - A pointer to the next node.
   //!
   CigiEventList *GetNextEvent(void) { return(NextEvent); }

protected:

   //==> Member variables

   //=========================================================
   //! Next Event<br>
   //! A pointer to the next node in this list.
   //!
	CigiEventList * NextEvent;

   //=========================================================
   //! Event<br>
   //! A pointer to this node's Event Processor object.
   //!
   CigiBaseEventProcessor *Event;

   //=========================================================
   //! CallBack<br>
   //! A pointer to this node's static Callback Processor function.
   //!
   CigiCBProcessor CallBack;

   //=========================================================
   //! Signal<br>
   //! A pointer to this node's Signal Processor object.
   //!
   CigiBaseSignalProcessing *Signal;


};

#endif // !defined(_CIGI_EVENT_LIST_INCLUDED_)
