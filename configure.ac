#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.60/html_node/index.html#Top

AC_PREREQ([2.63])
AC_INIT([Ttavis-test],
        m4_esyscmd([git describe --always | awk '/.*/ {sub(/^v/, ""); printf "%s",$1; exit}']), 
	[kento@llnl.gov])

AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign -Wall -Werror], [0.1])

### Action Macros
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])



#AC_SUBST([LIB_CURRENT], [1])
AC_SUBST([LIB_CURRENT], [0])
AC_SUBST([LIB_REVISION], [0])
AC_SUBST([LIB_AGE], [0])


#### Checks for programs.
AC_LANG_PUSH(C)
LX_FIND_MPI
test "x$have_C_mpi" = xyes || AC_MSG_ERROR([Failed to find C MPI Wrapper.])
AC_LANG_POP()
AC_LANG_PUSH(C++)
LX_FIND_MPI
test "x$have_CXX_mpi" = xyes || AC_MSG_ERROR([Failed to find C++ MPI Wrapper.])
AC_LANG_POP()
AC_LANG_PUSH(Fortran)
LX_FIND_MPI
test "x$have_F_mpi" = xyes || AC_MSG_ERROR([Failed to find Fortran MPI Wrapper.])
AC_LANG_POP()
CC="$MPICC"
CXX="$MPICXX"
FC="$MPIFC"
AC_PROG_CXX

AC_CHECK_PROGS([MAKE], [make], [:])
if test "$MAKE" = :; then
   AC_MSG_ERROR([This package needs make.])
fi
AC_PROG_LIBTOOL


#### Checks for libraries.

AC_ARG_WITH([zlib-static],
            [AS_HELP_STRING([--with-zlib-static],
              [path to installation directory for libz])],
            [libz_DIR=$withval],
            [libz_DIR=""])

check_zlib="yes"
if test "$libz_DIR" = ""; then
   AC_CHECK_LIB([z], [deflate], [], [check_zlib="no"])
   AC_CHECK_LIB([z], [inflate], [], [check_zlib="no"])
if test "$check_zlib" = "no"; then
   AC_MSG_ERROR([This package needs zlib.])
fi		    
else
   AC_SUBST([libz_a_INCLUDE], [$libz_DIR/include/])
   AC_SUBST([libz_a_LIB], [$libz_DIR/lib/libz.a])
fi

#AC_CHECK_LIB([mpi], [MPI_Init])

#### Checks for header files.

if test "$libz_DIR" = :; then
   AC_CHECK_HEADERS([zlib.h])
fi

#### Checks for typedefs, structures, and compiler characteristics.

#### Checks for library functions.


#### Output files.

AC_CONFIG_HEADERS(config.h)
AC_CONFIG_FILES([
	Makefile 
	src/Makefile
	test/Makefile])
AC_OUTPUT
