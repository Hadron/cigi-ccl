require 'socket'
require 'cigi'
require 'powermate'

socket = UDPSocket.new
socket.bind(0,9000)

session = Cigi::CigiHostSession.new

#session.SetCigiVersion(3,3)

out = session.GetOutgoingMsgMgr

cigic = Cigi::CigiIGCtrlV3_2.new
cigic.SetIGMode(Cigi::CigiBaseIGCtrl::Operate)

own = Cigi::CigiEntityCtrlV3.new

own.SetEntityID(0)
own.SetEntityType(0)
own.SetEntityState(Cigi::CigiBaseEntityCtrl::Active)
own.SetLat(35.5)
own.SetLon(-119)
own.SetAlt(1000)
own.SetYaw(0)
own.SetPitch(0)
own.SetRoll(0)

@yaw = 0

pmate = PowerMate.new

pmate.on_rotate do |event|
  @yaw += event.value
  @yaw -= 360.0 while @yaw >= 360.0
  @yaw += 360.0 while @yaw < 0
end

Thread.new { pmate.each_event{} }

loop do
  out.BeginMsg

  out << cigic

  own.SetYaw(@yaw)

  puts "yaw is #{@yaw}"

  out << own

  out.LockMsg
  buf = out.GetBuffer

  indata = socket.recv 65536
  socket.send buf,0,"127.0.0.1",8000

  out.UnlockMsg
end

