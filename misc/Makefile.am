bin_PROGRAMS =  \
	checksyms \
	lipo \
	size \
	strings \
	nm \
	libtool \
	redo_prebinding \
	seg_addr_table \
	seg_hack \
	install_name_tool \
	indr \
	strip \
	nmedit \
	segedit \
	pagestuff \
	ranlib \
	codesign_allocate

AM_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(LLVM_CFLAGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	-I$(top_srcdir)/include \
	-isystem /usr/include \
	-idirafter${OSX_SDKDIR}/usr/include \
	-DI386 -Di486 -Di586 -Di686 -DARCH64

AM_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

LDADD = \
	$(top_builddir)/libemulated/libemulated.la \
	$(top_builddir)/libstuff/libstuff.la \
	$(DL_LIBS)

checksyms_SOURCES = checksyms.c

codesign_allocate_SOURCES = codesign_allocate.c

indr_SOURCES = indr.c

install_name_tool_SOURCES = install_name_tool.c

libtool_SOURCES = libtool.c

lipo_SOURCES = lipo.c

nmedit_SOURCES = strip.c
nmedit_CFLAGS = -DNMEDIT $(AM_CFLAGS)

nm_SOURCES = nm.c
pagestuff_SOURCES=pagestuff.c

ranlib_SOURCES = libtool.c
ranlib_CFLAGS = -DRANLIB $(AM_CFLAGS)

redo_prebinding_SOURCES = redo_prebinding.c

seg_addr_table_SOURCES = seg_addr_table.c

seg_hack_SOURCES = seg_hack.c

segedit_SOURCES = segedit.c

size_SOURCES = size.c

strings_SOURCES = strings.c

strip_SOURCES = strip.c
