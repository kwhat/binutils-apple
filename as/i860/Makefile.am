libexec_PROGRAMS = i860-as

i860_as_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include \
	-DI860

i860_as_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

i860_as_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

i860_as_SOURCES = \
	../app.c \
	../as.c \
	../atof-generic.c \
	../atof-ieee.c \
	../expr.c \
	../fixes.c \
	../flonum-const.c \
	../flonum-copy.c \
	../flonum-mult.c \
	../frags.c \
	../hash.c \
	../hex-value.c \
	../input-file.c \
	../input-scrub.c \
	../layout.c \
	../messages.c \
	../obstack.c \
	../read.c \
	../sections.c \
	../symbols.c \
	../write_object.c \
	../xmalloc.c \
	../dwarf2dbg.c \
	../i860.c

install-exec-hook:
	mkdir -p $(DESTDIR)/$(libexecdir)/as/i860
	mv $(DESTDIR)/$(libexecdir)/*-as $(DESTDIR)/$(libexecdir)/as/i860/as
