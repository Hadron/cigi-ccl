
std::vector<MessageBuffer*> MessageBuffers;

class MessageBuffer
{
public:

   MessageBuffer( unsigned int length )
   {
      // this bit of trickery ensures that the buffer length is an even 
      // multiple of 64 bits
      Length = ((length/sizeof(Cigi_int64)) + 1) * sizeof(Cigi_int64);
      Buffer = new Cigi_uint8[Length];
      
      FillCount = 0;
      Valid = false;
   }

   ~MessageBuffer()
   {
      delete [] Buffer;
   }
   
   //=========================================================
   //! Specifies the size of the buffer.
   //!
   int Length;

   //=========================================================
   //! The message buffer itself.
   //!
   Cigi_uint8 * Buffer;

   //=========================================================
   //! Specifies the number of valid bytes in the message that
   //! is contained within this buffer.
   //!
   int FillCount;

   //=========================================================
   //! A bool that specifies whether the buffer has valid data in it.
   //!
   bool Valid;
};

