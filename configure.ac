AC_INIT([CIGI Class Library], [3.3.2], 
        [http://cigi.sourceforge.net], 
        [cigicl])
AM_INIT_AUTOMAKE
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# check the endian-ness of the compiling machine
AC_C_BIGENDIAN
# the variable ac_cv_c_bigendian is defined by the AC_C_BIGENDIAN macro
if test $ac_cv_c_bigendian = no; then
  # the following will append a -D argument to the compiler's argument list   
  AC_DEFINE(CIGI_LITTLE_ENDIAN)
fi

AC_CONFIG_FILES([
	cigicl.pc
	Makefile
	include/Makefile
	source/Makefile])
AC_OUTPUT
