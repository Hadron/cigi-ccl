echo Note - you should install the CCL before running this script.  This 
echo script uses pkg-config, which means that the installed version of 
echo the CCL will be used to generate the wrapper interface.
echo 

echo Using swig to generate wrapper code...
swig -c++ -ruby -DCIGI_SPEC `pkg-config --cflags cigicl` -outdir . -o ./swig_wrap.cxx ../swig.i

echo Compiling wrapper code...
g++ -I. -I/usr/local/lib/ruby/1.8/i686-linux -I/usr/lib/ruby/1.8/i486-linux `pkg-config --cflags cigicl` -fPIC -g -O2  -fPIC -c swig_wrap.cxx

echo Linking wrapper code...
gcc -shared -o cigi.so swig_wrap.o `pkg-config --libs cigicl` -L'.' -L'/usr/local/lib' -Wl,-R'/usr/local/lib' -L.  -rdynamic -Wl,-export-dynamic    -Wl,-R -Wl,/usr/local/lib -L/usr/local/lib -lruby  -ldl -lcrypt -lm -lc
