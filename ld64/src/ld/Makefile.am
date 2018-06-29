SUBDIRS = code-sign-blobs parsers passes

bin_PROGRAMS = ld64

ld64_LDFLAGS = \
	$(PTHREAD_FLAGS) \
	-lcrypto -lobjcxx -luuid

ld64_CFLAGS =  \
	${CFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

ld64_CXXFLAGS =  \
	${CXXFLAGS} \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld/parsers \
	-I$(top_srcdir)/ld64/src/ld \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la \
	$(top_builddir)/ld64/src/ld/code-sign-blobs/libCodeSignBlobs.la \
	$(top_builddir)/ld64/src/ld/parsers/libParsers.la \
	$(top_builddir)/ld64/src/ld/passes/libPasses.la

ld64_SOURCES = \
	InputFiles.cpp \
	Options.cpp \
	OutputFile.cpp \
	Resolver.cpp \
	Snapshot.cpp \
	SymbolTable.cpp \
	debugline.c \
	ld.cpp \
	qsort_r.c
