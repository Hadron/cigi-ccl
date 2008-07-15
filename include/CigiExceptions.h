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
 *  FILENAME:   CigiExceptions.h
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
 *  09/15/2003 James Durtschy                    CIGI_CR_DR_1
 *  Initial Release.
 *  
 *  01/21/2005 Greg Basler                       Version 1.5
 *  Added the CIGI_SPEC modifier to the class declarations for exporting the 
 *  classes in a Windows DLL.
 *  
 *  06/23/2006 Greg Basler                       Version 1.7.1
 *  Changed native char and unsigned char types to CIGI types Cigi_int8 and 
 *  Cigi_uint8.
 * </pre>
 *  Author: The Boeing Company
 *
 */


#if ! defined( _CIGI_EXCEPTIONS_INCLUDED_)
#define _CIGI_EXCEPTIONS_INCLUDED_
    
    
#include "CigiException.h"
#include <string.h>
#include <stdio.h>


//=========================================================
//! This is the exception thrown when a problem involving 
//!   a class, variable, memory, etc. allocatin failure 
//!   is encountered.
//!
class CIGI_SPEC CigiAllocFailedException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiAllocFailedException 
   //!   exception class
   //!
   CigiAllocFailedException(void)
   {
      memcpy(ErrMsg,"Allocation Failure\n",21);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_ALLOC_FAILED;
   }

   //=========================================================
   //! General Destructor for the CigiAllocFailedException 
   //!   exception class
   //!
   virtual ~CigiAllocFailedException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   the current message buffer being overrun is encountered.
//!
class CIGI_SPEC CigiBufferOverrunException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiBufferOverrunException 
   //!   exception class
   //!
   CigiBufferOverrunException(void)
   {
      memcpy(ErrMsg,"Buffer Overrun Error\n",22);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_BUFFER_OVERRUN;
   }

   //=========================================================
   //! General Destructor for the CigiBufferOverrunException 
   //!   exception class
   //!
   virtual ~CigiBufferOverrunException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   the buffer being to small to use is encountered.
//!
class CIGI_SPEC CigiBufferTooSmallException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiBufferTooSmallException 
   //!   exception class
   //!
   CigiBufferTooSmallException(void)
   {
      memcpy(ErrMsg,"Buffer Too Small Error\n",26);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_BUFFER_TOO_SMALL;
   }


   //=========================================================
   //! General Destructor for the CigiBufferTooSmallException 
   //!   exception class
   //!
   virtual ~CigiBufferTooSmallException(void) throw() { };

protected:

   char ErrMsg[30];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   routines having a specific call sequence being called 
//!   out of that sequence is encountered.
//!
class CIGI_SPEC CigiCalledOutOfSequenceException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiCalledOutOfSequenceException 
   //!   exception class
   //!
   CigiCalledOutOfSequenceException(void)
   {
      memcpy(ErrMsg,"Routine Call Out Of Sequence Error\n",38);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_CALLED_OUT_OF_SEQUENCE;
   }

   //=========================================================
   //! General Destructor for the CigiCalledOutOfSequenceException 
   //!   exception class
   //!
   virtual ~CigiCalledOutOfSequenceException(void) throw() { };

protected:

   char ErrMsg[40];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   the use of an invalid opcode/packet id is encountered.
//!
class CIGI_SPEC CigiInvalidOpcodeException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidOpcodeException 
   //!   exception class
   //!
   CigiInvalidOpcodeException(void)
   {
      memcpy(ErrMsg,"Invalid Packet ID\n",21);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_OPCODE;
   }

   //=========================================================
   //! General Destructor for the CigiInvalidOpcodeException 
   //!   exception class
   //!
   virtual ~CigiInvalidOpcodeException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   an invalid packet is encountered.
//!
class CIGI_SPEC CigiInvalidPacketException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidPacketException 
   //!   exception class
   //!
   CigiInvalidPacketException(void)
   {
      memcpy(ErrMsg,"Invalid Packet\n",18);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_PACKET;
   }

   //=========================================================
   //! General Destructor for the CigiInvalidPacketException 
   //!   exception class
   //!
   virtual ~CigiInvalidPacketException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   an incorrect packet size is encountered.
//!
class CIGI_SPEC CigiInvalidPacketSizeException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidPacketSizeException 
   //!   exception class
   //!
   CigiInvalidPacketSizeException(void)
   {
      memcpy(ErrMsg,"Invalid Packet Size\n",23);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_PACKET_SIZE;
   }

   //=========================================================
   //! General Destructor for the CigiInvalidPacketSizeException 
   //!   exception class
   //!
   virtual ~CigiInvalidPacketSizeException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   an invalid session being requested is encountered.
//!
class CIGI_SPEC CigiInvalidSessionException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidSessionException 
   //!   exception class
   //!
   CigiInvalidSessionException(void) 
   {
      memcpy(ErrMsg,"Invalid Session\n",19);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_SESSION;
   }

   //=========================================================
   //! General Destructor for the CigiInvalidSessionException 
   //!   exception class
   //!
   virtual ~CigiInvalidSessionException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   invalid seesion type being requested is encountered.
//!
class CIGI_SPEC CigiInvalidSessionTypeException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidSessionTypeException 
   //!   exception class
   //!
   CigiInvalidSessionTypeException(void) 
   {
      memcpy(ErrMsg,"Invalid Session Type\n",24);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_SESSION_TYPE;
   }

   //=========================================================
   //! General Destructor for the CigiInvalidSessionTypeException 
   //!   exception class
   //!
   virtual ~CigiInvalidSessionTypeException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   too many sessions being requested is encountered.
//!
class CIGI_SPEC CigiMaxSessionsException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiMaxSessionsException 
   //!   exception class
   //!
   CigiMaxSessionsException(void) 
   {
      memcpy(ErrMsg,"Requested Number Of Sessions Exceeds Maximum\n",48);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_MAX_SESSIONS;
   }

   //=========================================================
   //! General Destructor for the CigiMaxSessionsException 
   //!   exception class
   //!
   virtual ~CigiMaxSessionsException(void) throw() { };

protected:

   char ErrMsg[50];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   the IG Control message not being created and used is encountered.
//!
class CIGI_SPEC CigiMissingIgControlException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiMissingIgControlException 
   //!   exception class
   //!
   CigiMissingIgControlException(void) 
   {
      memcpy(ErrMsg,"The Message Is Missing The IG Control Packet\n",48);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_MISSING_IG_CONTROL_PACKET;
   }

   //=========================================================
   //! General Destructor for the CigiMissingIgControlException 
   //!   exception class
   //!
   virtual ~CigiMissingIgControlException(void) throw() { };

protected:

   char ErrMsg[50];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   the Start Of Frame message not being created and used 
//!   is encountered.
//!
class CIGI_SPEC CigiMissingStartOfFrameException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiMissingStartOfFrameException 
   //!   exception class
   //!
   CigiMissingStartOfFrameException(void) 
   {
      memcpy(ErrMsg,"The Message Is Missing The Start Of Frame Packet\n",52);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_MISSING_SOF_PACKET;
   }

   //=========================================================
   //! General Destructor for the CigiMissingStartOfFrameException 
   //!   exception class
   //!
   virtual ~CigiMissingStartOfFrameException(void) throw() { };

protected:

   char ErrMsg[55];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   an Unimplemented function, packet, etc. is encountered.
//!
class CIGI_SPEC CigiNotImplementedException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiNotImplementedException 
   //!   exception class
   //!
   CigiNotImplementedException(void) 
   {
      memcpy(ErrMsg,"Not Implemented Error\n",25);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_NOT_IMPLEMENTED;
   }

   //=========================================================
   //! General Destructor for the CigiNotImplementedException 
   //!   exception class
   //!
   virtual ~CigiNotImplementedException(void) throw() { };

protected:

   char ErrMsg[30];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   a null pointer being improperly used is encountered.
//!
class CIGI_SPEC CigiNullPointerException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiNullPointerException 
   //!   exception class
   //!
   CigiNullPointerException(void) 
   {
      memcpy(ErrMsg,"Null Pointer Error\n",21);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_UNEXPECTED_NULL;
   }

   //=========================================================
   //! General Destructor for the CigiNullPointerException 
   //!   exception class
   //!
   virtual ~CigiNullPointerException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   a packet being too large is encountered.
//!
class CIGI_SPEC CigiPacketTooLargeException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiPacketTooLargeException 
   //!   exception class
   //!
   CigiPacketTooLargeException(void) 
   {
      memcpy(ErrMsg,"Packet Is Too Large\n",23);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_PACKET_TOO_LARGE;
   }

   //=========================================================
   //! General Destructor for the CigiPacketTooLargeException 
   //!   exception class
   //!
   virtual ~CigiPacketTooLargeException(void) throw() { };

protected:

   char ErrMsg[25];

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   a packet parameter being set to an invalid value 
//!   is encountered.
//!
class CIGI_SPEC CigiValueOutOfRangeException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiValueOutOfRangeException 
   //!   exception class
   //!
   CigiValueOutOfRangeException(void) 
   {
      memcpy(ErrMsg,"Value Out Of Range\n",23);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_VALUE_OUT_OF_RANGE;
   }

   //=========================================================
   //! Integer Data Fill Constructor for the CigiValueOutOfRangeException 
   //!   exception class
   //!
   CigiValueOutOfRangeException(char *ParameterName, int Value, int Low, int High) 
   {

      if(strlen(ParameterName) < 75)
         PrtPname = ParameterName;
      else
      {
         memcpy(SubPname,ParameterName,74);
         SubPname[74] = 0;
         PrtPname = SubPname;
      }

      sprintf(ErrMsg,"Parameter Out of Range: Parameter %s is %d. The valid range is from %d to %d.\n",
              PrtPname, Value, Low, High);

      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_VALUE_OUT_OF_RANGE;
   }

   //=========================================================
   //! Float/Double Data Fill Constructor for the CigiValueOutOfRangeException 
   //!   exception class
   //!
   CigiValueOutOfRangeException(char *ParameterName, double Value, double Low, double High) 
   {
      if(strlen(ParameterName) < 75)
         PrtPname = ParameterName;
      else
      {
         memcpy(SubPname,ParameterName,74);
         SubPname[74] = 0;
         PrtPname = SubPname;
      }

      sprintf(ErrMsg,"Parameter Out of Range: Parameter %s is %g. The valid range is from %g to %g.\n",
              PrtPname, Value, Low, High);

      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_VALUE_OUT_OF_RANGE;
   }

   //=========================================================
   //! Float/Double Data Fill Constructor for the CigiValueOutOfRangeException 
   //!   exception class
   //!
   CigiValueOutOfRangeException(char *ParameterName, double Value, char *Mod, double Limit) 
   {
      if(strlen(ParameterName) < 75)
         PrtPname = ParameterName;
      else
      {
         memcpy(SubPname,ParameterName,74);
         SubPname[74] = 0;
         PrtPname = SubPname;
      }

      sprintf(ErrMsg,"Parameter Out of Range: Parameter %s is %g. The valid range is %s %g.\n",
              PrtPname, Value, Mod, Limit);

      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_VALUE_OUT_OF_RANGE;
   }

   //=========================================================
   //! General Destructor for the CigiValueOutOfRangeException 
   //!   exception class
   //!
   virtual ~CigiValueOutOfRangeException(void) throw() { };

protected:

   char ErrMsg[255];
   char SubPname[75];
   char *PrtPname;

};

//=========================================================
//! This is the exception thrown when a problem involving 
//!   an attempted use of the wrong CIGI version is encountered.
//!
class CIGI_SPEC CigiWrongVersionException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiWrongVersionException 
   //!   exception class
   //!
   CigiWrongVersionException(void) 
   {
      memcpy(ErrMsg,"Wrong Cigi Version Used\n",28);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_WRONG_VERSION;
   }

   //=========================================================
   //! General Destructor for the CigiWrongVersionException 
   //!   exception class
   //!
   virtual ~CigiWrongVersionException(void) throw() { };

protected:

   char ErrMsg[30];

};


//=========================================================
//! This is the exception thrown when a problem involving 
//!   an attempted use of the wrong CIGI version is encountered.
//!
class CIGI_SPEC CigiInvalidUserPacketException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiInvalidUserPacketException 
   //!   exception class
   //!
   CigiInvalidUserPacketException(void) 
   {
      memcpy(ErrMsg,"Cigi User Defined Packets Must Have an ID above 199\n",56);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_USER_PACKET;
   }


   //=========================================================
   //! Constructor used to specify the invalid user packet id
   //!
   CigiInvalidUserPacketException(Cigi_uint8 PacketID)
   {
      int IPacketID = (int)PacketID;
      sprintf(ErrMsg,"Cigi User Defined Packets Must Have an ID above 199\nUsed ID was %d\n",IPacketID);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_INVALID_USER_PACKET;
   }


   //=========================================================
   //! General Destructor for the CigiWrongVersionException 
   //!   exception class
   //!
   virtual ~CigiInvalidUserPacketException(void) throw() { };

protected:

   char ErrMsg[90];

};



//=========================================================
//! This is the exception thrown when a problem involving 
//!   an attempted use of the wrong CIGI version is encountered.
//!
class CIGI_SPEC CigiImproperPacketException : public CigiException
{

public:

   //=========================================================
   //! General Constructor for the CigiImproperPacketException 
   //!   exception class
   //!
   CigiImproperPacketException(void) 
   {
      memcpy(ErrMsg,"Improper packet for Session Type\n",37);
      Msg = ErrMsg;
      ErrorCode = CIGI_ERROR_IMPROPER_PACKET;
   }


   //=========================================================
   //! General Destructor for the CigiWrongVersionException 
   //!   exception class
   //!
   virtual ~CigiImproperPacketException(void) throw() { };

protected:

   char ErrMsg[40];

};

#endif // #if ! defined(_CIGI_EXCEPTIONS_INCLUDED_)
