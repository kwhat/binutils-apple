libexec_PROGRAMS = m88k-as

m88k_as_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include \
	-DM88K -Dm88110

m88k_as_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

m88k_as_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

m88k_as_SOURCES = \
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
	../m88k.c

install-exec-hook:
	mkdir -p $(DESTDIR)/$(libexecdir)/as/m88k
	mv $(DESTDIR)/$(libexecdir)/*-as $(DESTDIR)/$(libexecdir)/as/m88k/as
