bin_PROGRAMS = otool 

otool_LDADD =  \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la \
	$(DL_LIBS) 

otool_LDFLAGS = \
	$(AM_LDFLAGS) \
	$(PTHREAD_FLAGS)

otool_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	-I$(top_srcdir)/include \
	$(LLVM_CFLAGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	-idirafter/opt/MacOSX10.8.sdk/usr/include \
	-DOTOOL -UPC

otool_SOURCES = \
	main.c \
	ofile_print.c \
	m68k_disasm.c \
	i860_disasm.c \
	m88k_disasm.c \
	i386_disasm.c \
	ppc_disasm.c \
	hppa_disasm.c \
	sparc_disasm.c \
	arm_disasm.c \
	print_objc.c \
	print_objc2_32bit.c \
	print_objc2_64bit.c
