SUBDIRS = code-sign-blobs parsers passes

bin_PROGRAMS = ld.64

ld_64_CFLAGS =  \
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

ld_64_CXXFLAGS =  \
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

ld_64_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS) \
	-lBlocksRuntime -lcrypto -lLTO -luuid

ld_64_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la \
	$(top_builddir)/ld64/src/ld/code-sign-blobs/libCodeSignBlobs.la \
	$(top_builddir)/ld64/src/ld/parsers/libParsers.la \
	$(top_builddir)/ld64/src/ld/passes/libPasses.la

ld_64_SOURCES = \
	InputFiles.cpp \
	Options.cpp \
	OutputFile.cpp \
	Resolver.cpp \
	Snapshot.cpp \
	SymbolTable.cpp \
	debugline.c \
	ld.cpp \
	qsort_r.c
