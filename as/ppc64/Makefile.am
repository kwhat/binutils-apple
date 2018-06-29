libexec_PROGRAMS = ppc64-as

ppc64_as_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include \
	-DPPC -DARCH64 

ppc64_as_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

ppc64_as_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

ppc64_as_SOURCES = \
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
	../ppc.c

install-exec-hook:
	mkdir -p $(DESTDIR)/$(libexecdir)/as/ppc64
	mv $(DESTDIR)/$(libexecdir)/*ppc64-as $(DESTDIR)/$(libexecdir)/as/ppc64/as
