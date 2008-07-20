require 'cigihost'
require 'powermate'

host = CigiHost.new(:receiveport => 8005, :ig_address => '127.0.0.1', :ig_port => 8000)

if false
  pmate = PowerMate.new
  pmate.on_rotate do |event|
    host.yaw += event.value
  end
  Thread.new { pmate.each_event{} }
end

25

direction = 1

host.roll = -90
yaw = 0
host.run do
  yaw += 0.01 * direction
  host.yaw = yaw
  direction *= -1 if yaw > 25.0 or yaw < -25.0
end
