require 'socket'
require 'cigi'

class CigiHost

  def self.define_own_accessors(*methods)
    for method in methods do
      self.class_eval("def #{method}=(v); @own.Set#{method.to_s.capitalize}(v); end")
      self.class_eval("def #{method}; @own.Get#{method.to_s.capitalize}; end")
    end
  end

  define_own_accessors :yaw,:pitch,:roll,:alt,:alpha,:xoff,:yoff,:zoff,:lat,:lon

  def initialize(params)
    raise ":receiveport not given" unless params.has_key?(:receiveport)
    raise ":ig_address not given" unless params.has_key?(:ig_address)
    raise ":ig_port not given" unless params.has_key?(:ig_port)

    @socket = UDPSocket.new
    @socket.bind(0,params[:receiveport])
    @sendhost = params[:ig_address]
    @sendport = params[:ig_port]

    @session = Cigi::CigiHostSession.new


    @own = Cigi::CigiEntityCtrlV3.new

    @own.SetEntityID(0)
    @own.SetEntityType(0)
    @own.SetEntityState(Cigi::CigiBaseEntityCtrl::Active)

    self.lat = 35.0
    self.lon = -119
    self.alt = 0
    self.yaw = 0
    self.pitch = 0
    self.roll = 0
  end

  def yaw=(v)
    @own.SetYaw(limit(v,0.0,360.0))
  end

  def pitch=(v)
    @own.SetPitch(limit(v,0.0,360.0))
  end

  def run
    out = @session.GetOutgoingMsgMgr
    cigic = Cigi::CigiIGCtrlV3_2.new
    cigic.SetIGMode(Cigi::CigiBaseIGCtrl::Operate)
    
    loop do
      out.BeginMsg

      yield self

      out << cigic
      out << @own

      out.LockMsg
      buf = out.GetBufferString

      indata = @socket.recv 65536
      @socket.send buf,0,@sendhost,@sendport

      out.UnlockMsg

    end
  end

  protected

  def limit(v,min,max)
    v -= max while v >= max
    v += max while v < min
    v
  end
end
