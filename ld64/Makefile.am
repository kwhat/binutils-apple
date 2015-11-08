SUBDIRS = 3rd parsers passes other 

bin_PROGRAMS = ld
ld_LDADD =  \
    $(top_builddir)/ld64/3rd/libhelper.la  \
    $(top_builddir)/ld64/3rd/BlocksRuntime/libBlocksRuntime.la  \
	$(top_builddir)/ld64/parsers/libParsers.la \
	$(top_builddir)/ld64/passes/libPasses.la \
	$(DL_LIBS) \
	$(CRYPT_LIBS) \
	$(UUID_LIBS) \
	$(LTO_LIBS)

ld_LDFLAGS = $(PTHREAD_FLAGS) -lssl

ld_CXXFLAGS =  \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAG) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/include/foreign \
	-I$(top_srcdir)/ld64/abstraction \
	-I$(top_srcdir)/ld64/3rd \
	-I$(top_srcdir)/ld64/3rd/BlocksRuntime \
	-I$(top_srcdir)/ld64 \
	-I$(top_srcdir)/ld64/parsers \
    -I$(top_srcdir)/ld64/passes \
    -DPROGRAM_PREFIX="\"$(PROGRAM_PREFIX)\"" 

ld_CFLAGS =  \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAG) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/include/foreign \
	-I$(top_srcdir)/ld64/abstraction \
	-I$(top_srcdir)/ld64/3rd \
	-I$(top_srcdir)/ld64/3rd/BlocksRuntime \
	-I$(top_srcdir)/ld64 \
	-I$(top_srcdir)/ld64/parsers \
	-I$(top_srcdir)/ld64/passes \
	-DPROGRAM_PREFIX="\"$(PROGRAM_PREFIX)\"" 

ld_SOURCES =  \
	debugline.c  \
	InputFiles.cpp  \
	ld.cpp  \
	Options.cpp  \
	OutputFile.cpp  \
	Resolver.cpp  \
	Snapshot.cpp  \
	SymbolTable.cpp \
	code-sign-blobs/blob.cpp \ 
	parsers/textstub_dylib_file.cpp \
	passes/bitcode_bundle.cpp
