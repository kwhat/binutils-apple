bin_PROGRAMS = ar 
ar_LDADD =  \
        $(top_srcdir)/$(CCTOOLS)/libstuff/libstuff.la

ar_CFLAGS = -D__DARWIN_UNIX03 -I$(top_srcdir)/$(CCTOOLS)/include -I$(top_srcdir)/$(CCTOOLS)/include/foreign -I$(top_srcdir)/$(CCTOOLS)/libstuff $(WARNINGS) $(LTO_DEFS) $(ENDIAN_FLAG)

ar_SOURCES =  \
	append.c  \
	ar.c  \
	archive.c  \
	contents.c  \
	delete.c  \
	extract.c  \
	misc.c  \
	move.c  \
	print.c  \
	replace.c
