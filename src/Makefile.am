AM_CFLAGS = -fPIC -g -Wall -std=c++0x -pthread -I$(libz_a_INCLUDE) 
AM_CXXFLAGS = $(AM_CFLAGS)

apio_SOURCES =  \
		pmpi.cpp

lib_LTLIBRARIES = libpmpi.la
libpmpi_la_SOURCES  = $(pmpi_SOURCES)
libpmpi_la_LIBADD =  $(libz_a_LIB)
#libpmpi_la_CFLAGS = -lz -lstdc++ -lintlc
libpmpi_la_CFLAGS = -lz
libpmpi_la_CPPFLAGS =
#libpmpi_la_LDFLAGS = -version-info @LIB_CURRENT@:@LIB_REVISION@:@LIB_AGE@ -L/opt/ibm/xlC/13.1.5/lib 
libpmpi_la_LDFLAGS = -version-info @LIB_CURRENT@:@LIB_REVISION@:@LIB_AGE@

# ===== Header file installation =====
include_HEADERS   = pmpi.h
