noinst_LTLIBRARIES = libPasses.la
noinst_HEADERS =  \
	branch_island.h  \
	branch_shim.h  \
	compact_unwind.h  \
	dtrace_dof.h  \
	dylibs.h  \
	got.h  \
	huge.h  \
	objc.h  \
	order.h  \
	tlvp.h

libPasses_la_CXXFLAGS = \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAGS) \
	-I$(top_srcdir)/$(CCTOOLS)/include \
	-I$(top_srcdir)/$(CCTOOLS)/include/foreign \
	-I$(top_srcdir)/$(LD)/src/abstraction \
	-I$(top_srcdir)/$(LD)/src/ld \
	-I$(top_srcdir)/$(LD)/src/3rd \
	-I$(top_srcdir)/$(LD)/src 

libPasses_la_SOURCES =  \
	branch_island.cpp  \
	branch_shim.cpp  \
	compact_unwind.cpp  \
	dtrace_dof.cpp  \
	dylibs.cpp  \
	got.cpp  \
	huge.cpp  \
	objc.cpp  \
	order.cpp  \
	tlvp.cpp \
	stubs/stubs.cpp 
