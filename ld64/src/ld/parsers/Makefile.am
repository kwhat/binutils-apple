noinst_LTLIBRARIES = libParsers.la

noinst_HEADERS = \
	archive_file.h \
	lto_file.h \
	macho_dylib_file.h \
	macho_relocatable_file.h \
	opaque_section_file.h 

libParsers_la_CXXFLAGS = \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

libParsers_la_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS) \
	-lBlocksRuntime -lcrypto -lLTO -luuid

libParsers_la_SOURCES = \
	archive_file.cpp \
	lto_file.cpp \
	macho_dylib_file.cpp \
	macho_relocatable_file.cpp \
	opaque_section_file.cpp
