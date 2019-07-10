AC_INIT([binutils-apple], [4.6], [https://github.com/kwhat/binutils-apple/])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_ARG_PROGRAM

# Force compiler to clang
CC=clang
CXX=clang++
CPP="clang -E"

AM_INIT_AUTOMAKE([1.10 subdir-objects no-define no-dist-gzip dist-bzip2 tar-ustar])

AC_CONFIG_MACRO_DIR([m4])
AM_MAINTAINER_MODE

AC_PREREQ([2.64])

# Specify GNU src.
AC_GNU_SOURCE

AC_CONFIG_SRCDIR([COPYING])
LT_PREREQ([2.2.6])
LT_INIT(disable-static)

AC_PROG_INSTALL

AC_PROG_CC([clang])
AC_PROG_CXX([clang++])

AM_PROG_CC_C_O
AC_PROG_OBJC([clang])
AM_PROG_AS([clang])

AC_PROG_CC_C99
AX_CXX_COMPILE_STDCXX_11()

# Setup LLVM Include and Lib dirs.
AC_CHECK_PROG([llvm_config], [llvm-config], [yes], [no])
if test "x$llvm-config" = "xno"; then
    AC_MSG_ERROR("Could not find llvm-config.")
fi


AC_CHECK_TOOL([HOST_RANLIB], [ranlib], :)
AC_CHECK_TOOL([HOST_AR], [ar], :)

#detect buggy unistd.h contains __block.
buggy_unistd=`grep "\*__block," /usr/include/unistd.h`
if test "$buggy_unistd"; then
  echo "==========================================="
  echo "Buggy unistd.h found"
  echo "\"__block\" is a reserved word of clang compiler for blocks support."
  echo "Please replace \"__block\" in /usr/include/unistd.h to \"__libc_block\""
  echo "==========================================="
  exit
fi

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_FORK
AC_CHECK_FUNCS([memset strdup strrchr strtoul])

#AC_CHECK_HEADERS([openssl/md5.h], [], [AC_MSG_ERROR([*** md5.h not found, Please install ssl dev packages according to your system])])
#AC_CHECK_HEADERS([uuid/uuid.h], [], [AC_MSG_ERROR([*** uuid.h not found, Please install uuid dev packages according to your system])])
#AC_CHECK_HEADERS([objc/runtime.h], [], [AC_MSG_ERROR([*** runtime.h not found, Please install objc dev packages according to your system])])


# For libstuff emulated.c
case $target_cpu in
    arm*)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 12, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])

        AC_DEFINE(SUPPORT_ARCH_armv4t)
        AC_DEFINE(SUPPORT_ARCH_armv5)
        AC_DEFINE(SUPPORT_ARCH_armv6)
        AC_DEFINE(SUPPORT_ARCH_armv7)
        AC_DEFINE(SUPPORT_ARCH_armv7f)
        AC_DEFINE(SUPPORT_ARCH_armv7k)
        AC_DEFINE(SUPPORT_ARCH_armv7s)
        
        ALL_SUPPORTED_ARCHS="arm"
    ;;
     arm64*|aarch64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777228, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])

        AC_DEFINE(SUPPORT_ARCH_armv4t)
        AC_DEFINE(SUPPORT_ARCH_armv5)
        AC_DEFINE(SUPPORT_ARCH_armv6)
        AC_DEFINE(SUPPORT_ARCH_armv7)
        AC_DEFINE(SUPPORT_ARCH_armv7f)
        AC_DEFINE(SUPPORT_ARCH_armv7k)
        AC_DEFINE(SUPPORT_ARCH_armv7s)
        
        ALL_SUPPORTED_ARCHS="arm"
    ;;
     powerpc)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 18, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 100, [Emulated CPU subtype])
        
        ALL_SUPPORTED_ARCHS="ppc ppc64"
    ;;
    powerpc64*)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777234, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])
        
        ALL_SUPPORTED_ARCHS="ppc ppc64"
       ;;
    i?86)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 7, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 10, [Emulated CPU subtype])
        
        ALL_SUPPORTED_ARCHS="i386"
    ;;
    x86_64|amd64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777223, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 3, [Emulated CPU subtype])
        
        ALL_SUPPORTED_ARCHS="x86_64"
    ;;
    *)
        AC_MSG_ERROR([Unsupported target $target_cpu])
    ;;
esac
AC_DEFINE([ALL_SUPPORTED_ARCHS])


AC_DEFINE(_POSIX_C_SOURCE)
AC_DEFINE(_DARWIN_C_SOURCE)
AC_DEFINE(__APPLE_CPP__)
AC_DEFINE(__DARWIN_UNIX03)
AC_DEFINE(NeXT_MOD)
AC_DEFINE(_SYS_UCRED_H_)
AC_DEFINE(__DYNAMIC__)

if test "$target_alias"; then
    AC_DEFINE(PROGRAM_PREFIX, "${target_alias}-")
else 
    AC_DEFINE(PROGRAM_PREFIX, "")
fi

AC_C_BIGENDIAN(
  [ AC_DEFINE(__BIG_ENDIAN__) ], 
  [ AC_DEFINE(__LITTLE_ENDIAN__) ]
)


CFLAGS+=" "`llvm-config --cflags`
CXXFLAGS+=" "`llvm-config --cxxflags`
LDFLAGS+=" "`llvm-config --ldflags`


AC_SEARCH_LIBS([dlopen], [dl dld], [], [
  AC_MSG_ERROR([unable to find the dlopen() function])
])

AC_CHECK_LIB([dl], [dlopen], [DL_LIBS=-ldl])

AC_ARG_ENABLE([apple-sdk],
	AS_HELP_STRING([--enable-apple-sdk=/], [Path to the Mac10.X.sdk to use for compiling (default: /)]),
	[OSX_SDKDIR="$enableval"],
	[OSX_SDKDIR="/"])

AC_CHECK_FILE([$OSX_SDKDIR/Library],
	AC_SUBST(OSX_SDKDIR),
	AC_MSG_ERROR([unable to find the apple-sdk]))


# Disable warnings.
WARNINGS=""

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wall"
AC_MSG_CHECKING([if -Wall is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wall"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-long-long"
AC_MSG_CHECKING([if -Wno-long-long is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-long-long"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-import"
AC_MSG_CHECKING([if -Wno-import is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-import"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-format"
AC_MSG_CHECKING([if -Wno-format is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-format"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-deprecated"
AC_MSG_CHECKING([if -Wno-deprecated is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-deprecated"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-unused-variable"
AC_MSG_CHECKING([if -Wno-unused-variable is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-unused-variable"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

ORIGCFLAGS=$CFLAGS
CFLAGS="$CFLAGS -Wno-invalid-offsetof"
AC_MSG_CHECKING([if -Wno-invalid-offsetof is supported])
AC_COMPILE_IFELSE(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])],
   [WARNINGS="$WARNINGS -Wno-invalid-offsetof"
    AC_MSG_RESULT([yes])],
   [AC_MSG_RESULT([no])]
)
CFLAGS=$ORIGCFLAGS

AC_SUBST([WARNINGS], [$WARNINGS])


AC_ARG_ENABLE([lto],
	AS_HELP_STRING([--disable-lto], [Disable support for the link-time-optimizer]),
	[AC_SEARCH_LIBS([lto_api_version], [LTO], [AC_DEFINE(LTO_SUPPORT)], [AC_MSG_ERROR([unable to find libLTO])])],
	[])


AC_SEARCH_LIBS([Block_size], [BlocksRuntime], [], [AC_MSG_ERROR([unable to find blocks runtime])])
AC_SEARCH_LIBS([MD5_Init], [crypto], [], [AC_MSG_ERROR([unable to find libcrypto])])
AC_SEARCH_LIBS([pthread_create], [pthread], [], [AC_MSG_ERROR([unable to find pthreads])])
AC_SEARCH_LIBS([uuid_generate_random], [uuid], [], [AC_MSG_ERROR([unable to find libuuid])])

AC_CONFIG_FILES([
	Makefile
	libemulated/Makefile
	libstuff/Makefile
	ar/Makefile
	as/Makefile
	as/arm/Makefile
	as/hppa/Makefile
	as/i386/Makefile
	as/i860/Makefile
	as/m68k/Makefile
	as/m88k/Makefile
	as/ppc/Makefile
	as/ppc64/Makefile
	as/sparc/Makefile
	as/x86_64/Makefile
	misc/Makefile
	otool/Makefile

	ld64/Makefile
	ld64/src/Makefile
	ld64/src/ld/Makefile
	ld64/src/ld/code-sign-blobs/Makefile
	ld64/src/ld/parsers/Makefile
	ld64/src/ld/passes/Makefile
	ld64/src/other/Makefile
])

AC_OUTPUT
