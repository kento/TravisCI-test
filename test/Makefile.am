SUBDIRS=../src

AM_CFLAGS = -g 

noinst_PROGRAMS = \
	mpi_test

mpi_test_SOURCES = mpi_test.cpp
mpi_test_CFLAGS  = -I../src
mpi_test_LDFLAGS =


.PHONY: clean_core
clean_core:
	-rm -f *.core
	-rm -f *.btr


