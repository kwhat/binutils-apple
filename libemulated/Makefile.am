noinst_LTLIBRARIES = libemulated.la

libemulated_la_CFLAGS = \
	$(CFLAGS) \
	$(WARNINGS) \
	$(CPU_DEFINES) \
	$(ENDIAN_FLAG) \
	$(LLVM_CFLAGS) \
	-I$(top_srcdir)/include \
	-idirafter/opt/MacOSX10.8.sdk/usr/include

libemulated_la_LDFLAGS = \
	$(LDFLAGS) \
	$(LLVM_LDFLAGS)

libemulated_la_SOURCES = \
	darwin.c \
	mach.c \
	mach_absolute_time.c \
	mach_time.c \
	mach-o.c \
	strlcat.c \
	strlcpy.c \
	strmode.c
