bin_PROGRAMS = unwinddump rebase ObjectDump machocheck

AM_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS) \
	-lBlocksRuntime -lcrypto -lLTO -luuid

LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la


noinst_LTLIBRARIES = libprunetrie.la

libprunetrie_la_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

libprunetrie_la_SOURCES = PruneTrie.cpp


unwinddump_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

unwinddump_SOURCES = unwinddump.cpp


rebase_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

rebase_SOURCES = rebase.cpp


ObjectDump_CFLAGS =  \
	${CFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

ObjectDump_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

ObjectDump_LDFLAGS = \
	$(PTHREAD_FLAGS) \
	-lcrypto -lBlocksRuntime -lLTO -luuid

ObjectDump_LADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

ObjectDump_SOURCES = \
	$(top_builddir)/ld64/src/ld/debugline.c \
	$(top_builddir)/ld64/src/ld/qsort_r.c \
	$(top_builddir)/ld64/src/ld/InputFiles.cpp \
	$(top_builddir)/ld64/src/ld/Options.cpp \
	$(top_builddir)/ld64/src/ld/Snapshot.cpp \
	$(top_builddir)/ld64/src/ld/parsers/archive_file.cpp \
	$(top_builddir)/ld64/src/ld/parsers/macho_dylib_file.cpp \
	$(top_builddir)/ld64/src/ld/parsers/lto_file.cpp \
	$(top_builddir)/ld64/src/ld/parsers/opaque_section_file.cpp \
	$(top_builddir)/ld64/src/ld/parsers/macho_relocatable_file.cpp \
	ObjectDump.cpp


machocheck_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

machocheck_LDFLAGS = \
	$(PTHREAD_FLAGS) \
	-lcrypto -lBlocksRuntime -lLTO -luuid

machocheck_LADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

machocheck_SOURCES = machochecker.cpp
