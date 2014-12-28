bin_PROGRAMS = otool 

#$(top_builddir)/libobjc2/libobjc.la 
otool_LDADD =  \
	$(top_builddir)/libstuff/libstuff.la \
	$(DL_LIBS) 

otool_LDFLAGS = $(PTHREAD_FLAGS) -lobjc

otool_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/include/foreign -I$(top_srcdir)/libstuff -D__DARWIN_UNIX03 $(WARNINGS) $(LTO_DEFS) -D__DARWIN_UNIX03 $(ENDIAN_FLAG) -DOTOOL

otool_SOURCES =  \
	main.c \
	../libstuff/ofile.c \
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

