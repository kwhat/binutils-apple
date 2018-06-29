noinst_LTLIBRARIES = libstuff.la

libstuff_la_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

libstuff_la_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

libstuff_la_LIBADD = \
	$(top_builddir)/libemulated/libemulated.la

libstuff_la_SOURCES = \
	allocate.c \
	apple_version.c \
	arch.c \
	arch_usage.c \
	best_arch.c \
	breakout.c \
	bytesex.c \
	checkout.c \
	crc32.c \
	dylib_roots.c \
	dylib_table.c \
	errors.c \
	execute.c \
	fatal_arch.c \
	fatals.c \
	get_arch_from_host.c \
	get_toc_byte_sex.c \
	guess_short_name.c \
	hash_string.c \
	hppa.c \
	llvm.c \
	lto.c \
	macosx_deployment_target.c \
	ofile.c \
	ofile_error.c \
	ofile_get_word.c \
	print.c \
	reloc.c \
	rnd.c \
	seg_addr_table.c \
	set_arch_flag_name.c \
	swap_headers.c \
	symbol_list.c \
	SymLoc.c \
	unix_standard_mode.c \
	version_number.c \
	writeout.c
