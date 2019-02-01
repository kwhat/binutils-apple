bin_PROGRAMS = ar

ar_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

ar_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

ar_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

ar_SOURCES = \
	append.c \
	ar.c \
	archive.c \
	contents.c \
	delete.c \
	extract.c \
	misc.c \
	move.c \
	print.c \
	replace.c

ar_MANPAGES1 = ar.1

ar_MANPAGES5 = ar.5
