bin_PROGRAMS =  \
	dyldinfo \
	objcimageinfo \
	ObjectDump \
	unwinddump \
	machochecker 

AM_CXXFLAGS = \
	-fblocks \
	-D__DARWIN_UNIX03 \
	$(WARNINGS) \
	$(LTO_DEFS) \
	$(ENDIAN_FLAGS) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/include/foreign \
	-I$(top_srcdir)/ld64/3rd \
	-I$(top_srcdir)/ld64/abstraction \
	-I$(top_srcdir)/ld64 \
	-I$(top_srcdir)/ld64/parsers \
	-I$(top_srcdir)/ld64/passes

AM_CFLAGS = \
    -fblocks \
    -D__DARWIN_UNIX03 \
    $(WARNINGS) \
    $(LTO_DEFS) \
    $(ENDIAN_FLAGS) \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)/include/foreign \
	-I$(top_srcdir)/ld64/3rd \
	-I$(top_srcdir)/ld64/abstraction \
	-I$(top_srcdir)/ld64 \
	-I$(top_srcdir)/ld64/parsers \
	-I$(top_srcdir)/ld64/passes

unwinddump_SOURCES = unwinddump.cpp

machochecker_SOURCES = machochecker.cpp
machochecker_LDADD = $(top_builddir)/ld64/3rd/libhelper.la

ObjectDump_SOURCES = \
	ObjectDump.cpp \
	../debugline.c 

ObjectDump_LDADD =  \
	$(top_builddir)/ld64/parsers/libParsers.la \
	$(LTO_LIBS)

dyldinfo_SOURCES = dyldinfo.cpp
dyldinfo_LDADD = $(top_builddir)/ld64/3rd/libhelper.la

objcimageinfo_SOURCES = objcimageinfo.cpp
objcimageinfo_LDADD = $(top_builddir)/ld64/3rd/libhelper.la
