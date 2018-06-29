noinst_LTLIBRARIES = libPasses.la
noinst_HEADERS = \
	branch_island.h \
	branch_shim.h \
	compact_unwind.h \
	dtrace_dof.h \
	dylibs.h \
	got.h \
	huge.h \
	objc.h \
	order.h \
	tlvp.h

libPasses_la_CXXFLAGS = \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

libPasses_la_SOURCES = \
	branch_island.cpp \
	branch_shim.cpp \
	compact_unwind.cpp \
	dtrace_dof.cpp \
	dylibs.cpp \
	got.cpp \
	huge.cpp \
	objc.cpp \
	order.cpp \
	tlvp.cpp \
	stubs/stubs.cpp 
