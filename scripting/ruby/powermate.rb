#!/usr/bin/ruby
#
###########################################################################
#
# = PowerMate Interface Library for Linux
#
# == Description
#
# Interface Library to the Griffin PowerMate for Linux.
# The library includs a (minimalist) generic classes for the Linux Input Event
# Interface and convenience methods for Linux's ioctl(2) system call.
# Library probably works only on x86 because of values taken directly
# from asm/ioctl.h 
#
# (c) Oliver M. Bolzer <oliver@fakeroot.net>, 2002 
#
# == Revision History
#
# v0.5  (Feb 10, 2002)
# - remember LED status so we can set individual values
#   there is no way to know the previous values, so we set some sane
#   values (everything off) the first time we write the status register
# - set/get various LED status bits ( brightness, pulse_speed, pulse_mode,
#   pulse_awake?, pulse_asleep? )
#
# v0.4  (Feb 7,2002)
# - improve documentation for use with RDoc http://rdoc.sourceforge.net/
#
# v0.3.1 (Feb 4, 2002) 
# - detect old product ID of if the HID driver grabs the device
# - also usable when only the HID driver is installed, can't change
#   LED status though
#
# v0.3 (Feb 3, 2002)  
# - LED-brightness settable (brightness=)
# - record if button currently pressed
#
# v0.2 (Feb 2, 2002)
# - react and decode LED-Status-Change 
#   (PowerMate.on_led_change)
#
# v0.1 (Feb 1, 2002)
# - Initial public release
#
# ==TODO
# - need to detect PM unplug-replug, need to reopen device,
#   but there is no notification on unplug. Should be polled ?
#   (rumors say, Linux 2.5.4-preX supports plug events)
# - maybe support for "click" and "double-click"
#
# ==Licence
#
# (c) Oliver M. Bolzer <oliver@fakeroot.net>, 2002 
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the author nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
###########################################################################


##
# module for Linux-specific classes, working close to the kernel
module Linux

  ##
  # Linux ioctl(2) helper functions, values and definitions taken
  # from <asm/ioctl.h>, beware of (unlikely) changes.
  # Probably works only on Linux/x86
  module Ioctl

    ## shift values
    IOC_NRSHIFT   =  0
    IOC_TYPESHIFT =  8
    IOC_SIZESHIFT = 16
    IOC_DIRSHIFT  = 30

    ## Direction bits.
    IOC_NONE      =  0
    IOC_WRITE     =  1
    IDC_READ      =  2
   
    ##
    # encode an ioctl(2) from the specification commonly found
    # in Linux *.h files, +array+ is an Array consisting of
    # [ direction bit, type (String), number, size ]
    def Ioctl.encode( array )
      raise ArgumentError if array.class != Array
      raise ArgumentError.new( "Array has wrong number of elements, must be 4" ) if array.size != 4
      
      array[0] << IOC_DIRSHIFT | array[1].unpack('C').first << IOC_TYPESHIFT | array[2] << IOC_NRSHIFT | array[3] << IOC_SIZESHIFT;  
    end # Ioctl.encode()
  end # module Ioctl
  
  ##
  # constants related to Linux's Input Event System,
  # taken from <linux/input.h>;
  # only partial, will be extended as neccersary
  module InputConstants
    include Linux::Ioctl

    ## The event structure itself 
    Input_event = Struct.new( :time, :type, :code, :value )
    EVENT_SIZE = 16

    ## Protocol version
    EV_VERSION = 0x010000
    
    ## Event types
    EV_RST = 0x00
    EV_KEY = 0x01
    EV_REL = 0x02
    EV_ABS = 0x03
    EV_MSC = 0x04
    EV_LED = 0x11
    EV_SND = 0x12
    EV_REP = 0x14
    EV_FF  = 0x15
    EV_MAX = 0x1f

    ## ioctl's
    EVIOCGVERSION = Linux::Ioctl.encode([ IDC_READ, 'E', 0x01, 32 ])
    EVIOCGNAME = Linux::Ioctl.encode([ IDC_READ, 'E', 0x06, 255 ])

    ## Buttons
    BTN_MISC = 0x100
    BTN_0    = 0x100
    BTN_1    = 0x101
    BTN_2    = 0x102
    BTN_3    = 0x103
    BTN_4    = 0x104
    BTN_5    = 0x105
    BTN_6    = 0x106
    BTN_7    = 0x107
    BTN_8    = 0x108
    BTN_9    = 0x109
    BTN_MOUSE= 0x110
    BTN_LEFT = 0x110
    BTN_RIGHT= 0x111
    BTN_MIDDLE = 0x112
    BTN_SIDE = 0x113
    BTN_EXTRA= 0x114
    BTN_FORWARD = 0x115
    BTN_BACK = 0x116

    ## Relative axes
    REL_X      = 0x00
    REL_Y      = 0x01
    REL_Z      = 0x02
    REL_HWHEEL = 0x06
    REL_DIAL   = 0x07
    REL_WHEEL  = 0x08
    REL_MISC   = 0x09
    REL_MAX    = 0x0f
 
    ## Misc. events
    MSC_SERIAL   = 0x00
    MSC_PULSELED = 0x01
    MSC_MAX      = 0x07


  end # module InputConstants

  ##
  # class to handle Linux's Input Event Interface
  # (see linux/input.h),
  # currently a minimal implementation for the PowerMate
  class Input
    include Linux::Ioctl           # various values and routines for ioctl(2)
    include Linux::InputConstants  # constants from linux/input.h

    ##
    # open an Input Event Device
    def initialize( device )
        @device = nil
      begin
        @device =  File.open( device, File::Constants::RDONLY )
        @writable = true 
      end
      @devnode = device
    end # initialize()

    # path of device special file
    attr_reader :devnode 

    ## does the permission on the device allow us to write?
    def writable?
      @writable
    end

    ##
    # device name as reported by EVIOCGNAME
    def dev_name
      if !@name then 
        @name = "\0" * 255                  # allocate string, 255 should be enough
        @device.ioctl( EVIOCGNAME, @name )  # retrieve device name
        @name.gsub!(/\0.*/, '')             # strip extra NULLs
      end
      return @name
    end # dev_name()

    ##
    # iterator over each event being reported by the device
    # yields event of struct Linux::InputConstants::Input_event
    def each_event( &block )
      while data = @device.read( EVENT_SIZE ) do
        rawevent = data.unpack( "l!l!s!s!i") # tv_sec, tv_nsec, type, code, value
        event = Input_event.new
	rawevent[0] += 1 if rawevent[0] = 0    # sometimes time is not set
        event.time = Time.at( rawevent[0], rawevent[1])
        event.type = rawevent[2]
        event.code = rawevent[3]
        event.value = rawevent[4]
        yield event
      end
    end # each_event()

    ##
    # write an event into the device, some device use this to set their status
    def write_event( event )
      raise TypeError if event.class != Input_event
      
      ## encode Input_event into "struct input_event"
      struct_input_event = [0, 0,event.type, event.code, event.value].pack("l!l!s!s!i!")
      begin
        File.open(self.devnode, "w+"){|f| f.write(struct_input_event) }
      rescue Errno::EACCES
        @writable = false  ## can't seem to write, remember that
      end
    end # write_event()
  
  end # class Input
end # module Linux

##
# Interface to the Griffin PowerMate, a stainless steel dial like the
# volume regulator on a stereo
class PowerMate < Linux::Input

  ##
  # status of the LED
  # brightness:  LED-brightness (0-255)
  # speed:       pulse-speed (0-510)
  # mode:        pule-style (0,1,2)
  # sleep:       pulse while host is off
  # awake:       pulse while host is on
  LedStatus = Struct.new( :brightness, :speed, :mode, :pulse_asleep, :pulse_awake)

  ## 
  # find and open the first PowerMate in the system,
  # tries /dev/input/event0*, raises RuntimeError if no
  # readable PowerMate is found (check those permissions, if it doesn't work!) 
  def initialize 
    Dir.foreach( '/dev/input/' ){|file|
      next unless file =~ /^event\d+/  # only look at event*
     
      begin
        super( '/dev/input/' + file )
        case self.dev_name
        when "Griffin PowerMate"                           # normal ID 
          break
        when "Griffin Technology, Inc. Griffin PowerMate"  # grabed by HID?
          break
        when "Griffin SoundKnob"                           # old ID 
          break
        end
      rescue Errno::EACCES, Errno::ENODEV
        next
      end
      
    }

    ## could not find one
    raise RuntimeError.new("No PowerMate found in system") if !@device

    ## initialize instance variables
    @btn_pressed = false
    
    ## initialize LED Status flags
    @status = LedStatus.new
    @status.brightness = 0
    @status.speed = 0
    @status.mode = 0
    @status.pulse_asleep = false
    @status.pulse_awake = false 
  end # initialize 

  ##
  # Button status
  def button_pressed?
    @btn_pressed
  end

  ##
  # register button-press event-handler
  def on_button_press( &block )
    @btn_press_handler = block 
  end

  ##
  # register button-released event-handler
  def on_button_release( &block )
    @btn_release_handler = block
  end

  ##
  # register dial event-handler
  def on_rotate( &block )
    @rotate_handler = block
  end

  ##
  # register LED status-change event-handler
  # block gets a LedStatus Struct as argument
  def on_led_change( &block )
    @led_handler = block
  end

  ##
  # iterator over all events, dispatches to event specific hanlders before
  # handling &block 
  def each_event( &block )
    
    super{|event|
      case event.type

      ## key pressed
      when EV_KEY
        if event.code == BTN_0 or event.code == BTN_MOUSE then
          if event.value == 1 and @btn_press_handler then
	    @btn_pressed = true
            @btn_press_handler.call( event )
           elsif @btn_release_handler
	       @btn_pressed = false
               @btn_release_handler.call(event )
           end
        end

      ## dial rotated
      when EV_REL 
        if event.code == REL_DIAL or event.code == REL_X then
          @rotate_handler.call( event ) if @rotate_handler
        end

      ## LED status change
      when EV_MSC
	## decode status flag
	 #  bits  0- 7: 8 bits: LED brightness
	 #  bits  8-16: 9 bits: pulsing speed modifier 
	 #  bits 17-18: 2 bits: pulse table
	 #  bit     19: 1 bit : pulse whilst asleep?
	 #  bit     20: 1 bit : pulse constantly?
         @status.brightness = event.value & 0xff
         @status.speed = (event.value >> 8) & 0x1FF
         @status.mode = (event.value >> 17) & 0x3
         @status.pulse_asleep = (event.value >> 19) & 0x1
         if @status.pulse_asleep == 1 then
           @status.pulse_asleep = true
	 else 
           @status.pulse_asleep = false
         end
       	 @status.pulse_awake = (event.value >> 20) & 0x1
         if @status.pulse_awake == 1 then
           @status.pulse_awake = true
	 else 
           @status.pulse_awake = false
         end

         @led_handler.call( @status ) if @led_handler

      end # when

      ## handle generic event handler
      block.call( event ) if block
    }
      
  end # each_event

  ##
  # last known LED brightness
  def brightness
    @status.brightness
  end # brightness()

  ##
  # set LED brightness
  def brightness=( value )
    value = 0 if value < 0
    value = 255 if value > 255
    
    @status.brightness = value

    set_status( @status )
  end # brightness=()

  ##
  # last known pulse speed
  def pulse_speed
    @status.speed
  end # pulse_speed()

  ##
  # set pulse speed 0-510, only values close to 255 make much sense
  def pulse_speed=( value )
    value = 0 if value < 0
    value = 510 if value > 510

    @status.speed = value
    set_status( @status )
  end # pulse_speed=()
 
  ##
  # set pulse mode (0,1 or 2)
  def pulse_mode=( value )
    value = 0 if value < 0
    value = 2 if value > 0

    @status.mode = value
    set_status( @status )
  end #pulse_mode=()

  ##
  # last known pulse mode
  def pulse_mode
    @status.mode
  end # pulse_mode()

  ##
  # set pulse status when the host is running
  def pulse_awake=( value )
    @status.pulse_awake = value
    set_status( @status )
  end # pulse_awake=()

  ##
  # pulse when host is running? (last known status)
  def pulse_awake?
    @status.pulse_awake
  end # pulse_awake?()

  ##
  # set pulse status when the host is not running
  def pulse_asleep=( value )
    @status.pulse_asleep = value
    set_status( @status )
  end # pulse_asleep=()

  ##
  # pulse when host is not runnging? (last knwon status)
  def pulse_asleep?
    @status.pulse_asleep
  end # pulse_asleep?()

  ##
  # write LED status to device
  def set_status( status )
 
    event = Input_event.new
    event.type = EV_MSC
    event.code = MSC_PULSELED

    if status.pulse_asleep then
      asleep = 1
    else
      asleep = 0
    end
    if status.pulse_awake then
      awake = 1
    else
      awake = 0
    end

    ## encode status bits
    event.value = status.brightness | (status.speed << 8 ) | (status.mode << 17)
    event.value = event.value | ( asleep << 19 ) | (awake << 20 )

    self.write_event( event ) if self.writable?

  end
  private :set_status

end # class PowerMate

#### only execute if called directly ####
if $0 == __FILE__ then

##
# API demo, reportin envents coming from the PowerMate

## find and open the PowerMate
pmate = nil
begin
  pmate = PowerMate.new
rescue RuntimeError => e
  $stderr << "Error: " + e.to_s + "\n"
  exit
end

## found it
$stdout << "PowerMate found on #{pmate.devnode}\n"

## register event handler for button press, switch off LED
pmate.on_button_press{
  print "Button pressed\n"
  pmate.brightness = 0
}

## register event handler for button release, turn on LED
pmate.on_button_release{
  print "Button released\n"
  pmate.brightness = 255
}

## register event handler for button rotation
pmate.on_rotate{|event| 
  print "Button has been rotated #{event.value} units\n"
}

## register event handler for LED status change
pmate.on_led_change{|status|
  printf "new LED status: brightness: %i, speed: %i, mode: %i, pulse_asleep?: %s, pulse_awake? %s\n",  status.brightness, status.speed, status.mode, status.pulse_asleep, status.pulse_awake
}

## handle events endlessly
begin
 Thread.new{ pmate.each_event{} }.join
rescue Interrupt
 exit(0)
end

end  # if $0 = __FILE__

