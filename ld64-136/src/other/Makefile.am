bin_PROGRAMS =  \
	dyldinfo \
	ObjectDump \
	unwinddump \
	machochecker 

AM_CXXFLAGS = \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAGS) \
	-I$(top_srcdir)/src/include \
	-I$(top_srcdir)/src/include/foreign \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/3rd \
	-I$(top_srcdir)/src/abstraction \
	-I$(top_srcdir)/src/ld \
	-I$(top_srcdir)/src/ld/parsers \
	-I$(top_srcdir)/src/ld/passes

AM_CFLAGS = \
    -fblocks \
    -D__DARWIN_UNIX03 \
    $(WARNINGS) \
    $(LTO_DEFS) \
    $(ENDIAN_FLAGS) \
    -I$(top_srcdir)/src/include \
    -I$(top_srcdir)/src/include/foreign \
    -I$(top_srcdir)/src \
    -I$(top_srcdir)/src/3rd \
    -I$(top_srcdir)/src/abstraction \
    -I$(top_srcdir)/src/ld \
    -I$(top_srcdir)/src/ld/parsers \
    -I$(top_srcdir)/src/ld/passes 

unwinddump_SOURCES = unwinddump.cpp
machochecker_SOURCES = machochecker.cpp
ObjectDump_SOURCES = \
	ObjectDump.cpp \
	$(top_srcdir)/src/ld/debugline.c 
ObjectDump_LDADD =  \
	$(top_srcdir)/src/ld/parsers/libParsers.la \
	$(LTO_LIBS)  


dyldinfo_SOURCES =  dyldinfo.cpp
dyldinfo_LDADD =  \
	$(top_srcdir)/src/3rd/libhelper.la


