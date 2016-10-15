noinst_LTLIBRARIES = libPasses.la
noinst_HEADERS =  \
	bitcode_bundle.h \
	branch_island.h  \
	branch_shim.h  \
	code_dedup.h \
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
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/include/foreign \
	-I$(top_srcdir)/ld64/abstraction \
	-I$(top_srcdir)/ld64/parsers \
	-I$(top_srcdir)/ld64/3rd \
	-I$(top_srcdir)/ld64

libPasses_la_SOURCES =  \
	bitcode_bundle.cpp \
	branch_island.cpp  \
	branch_shim.cpp  \
	code_dedup.cpp \
	compact_unwind.cpp  \
	dtrace_dof.cpp  \
	dylibs.cpp  \
	got.cpp  \
	huge.cpp  \
	objc.cpp  \
	order.cpp  \
	tlvp.cpp \
	stubs/stubs.cpp 
