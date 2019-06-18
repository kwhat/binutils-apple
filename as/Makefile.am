SUBDIRS = $(AS_ARCH)

bin_PROGRAMS = as 

as_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter${OSX_SDKDIR}/usr/include

as_LDFLAGS = \
	$(LDFLAGS)
	$(LLVM_LDFLAGS)

as_LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la

as_SOURCES = driver.c 
