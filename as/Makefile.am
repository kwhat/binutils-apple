SUBDIRS = arm i386 x86_64 ppc ppc64

bin_PROGRAMS = as 

as_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

as_LDFLAGS = \
	$(LDFLAGS)
	$(LLVM_LDFLAGS)

as_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

as_SOURCES = driver.c 
