SUBDIRS = parsers passes

bin_PROGRAMS = ld
ld_LDADD =  \
    $(top_srcdir)/$(LD)/src/3rd/libhelper.la  \
    $(top_srcdir)/$(LD)/src/3rd/BlocksRuntime/libBlocksRuntime.la  \
	$(top_srcdir)/$(LD)/src/ld/parsers/libParsers.la \
	$(top_srcdir)/$(LD)/src/ld/passes/libPasses.la \
	$(DL_LIBS) \
	$(CRYPT_LIBS) \
	$(UUID_LIBS) \
	$(LTO_LIBS)

ld_LDFLAGS = $(PTHREAD_LDFLAG) -lssl

ld_CXXFLAGS =  \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAG) \
	-I$(top_srcdir)/$(CCTOOLS)/include \
	-I$(top_srcdir)/$(CCTOOLS)/include/foreign \
	-I$(top_srcdir)/$(LD)/src \
	-I$(top_srcdir)/$(LD)/src/abstraction \
	-I$(top_srcdir)/$(LD)/src/3rd \
	-I$(top_srcdir)/$(LD)/src/3rd/BlocksRuntime \
	-I$(top_srcdir)/$(LD)/src/ld \
	-I$(top_srcdir)/$(LD)/src/ld/parsers \
    -I$(top_srcdir)/$(LD)/src/ld/passes \
    -DPROGRAM_PREFIX="\"$(PROGRAM_PREFIX)\"" 

ld_CFLAGS =  \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAG) \
	-I$(top_srcdir)/$(CCTOOLS)/include \
	-I$(top_srcdir)/$(CCTOOLS)/include/foreign \
	-I$(top_srcdir)/$(LD)/src \
	-I$(top_srcdir)/$(LD)/src/abstraction \
	-I$(top_srcdir)/$(LD)/src/3rd \
	-I$(top_srcdir)/$(LD)/src/3rd/BlocksRuntime \
	-I$(top_srcdir)/$(LD)/src/ld \
	-I$(top_srcdir)/$(LD)/src/ld/parsers \
	-I$(top_srcdir)/$(LD)/src/ld/passes \
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
	code-sign-blobs/blob.cpp
