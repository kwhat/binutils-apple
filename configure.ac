AC_INIT([binutils-apple], [7.3.1], [https://github.com/kwhat/binutils-apple/])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_ARG_PROGRAM

#force compiler to clang
CC=clang
CXX=clang++
# I am not sure why this is here or if it is needed.
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

if test "$CC" != "clang"; then
AC_MSG_ERROR("You must use clang to compile it")
fi

if test "$CXX" != "clang++"; then
AC_MSG_ERROR("You must use clang to compile it")
fi

AC_CHECK_HEADERS([llvm-c/lto.h], [], [AC_MSG_ERROR([*** lto.h not found, Please install llvm dev packages according to your system])])
AC_CHECK_HEADERS([openssl/md5.h], [], [AC_MSG_ERROR([*** md5.h not found, Please install ssl dev packages according to your system])])
AC_CHECK_HEADERS([uuid/uuid.h], [], [AC_MSG_ERROR([*** uuid.h not found, Please install uuid dev packages according to your system])])
AC_CHECK_HEADERS([objc/runtime.h], [], [AC_MSG_ERROR([*** runtime.h not found, Please install objc dev packages according to your system])])

#for libstuff emulated.c
case $target_cpu in
     powerpc)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 18, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 100, [Emulated CPU subtype])
    ;;
     powerpc64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777234, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])
       ;;
     i?86)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 7, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 10, [Emulated CPU subtype])
    ;;
     x86_64)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 16777223, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 3, [Emulated CPU subtype])
    ;;
     arm)
        AC_DEFINE(EMULATED_HOST_CPU_TYPE, 12, [Emulated CPU type])
        AC_DEFINE(EMULATED_HOST_CPU_SUBTYPE, 0, [Emulated CPU subtype])
    ;;
     *)
    AC_MSG_ERROR([Unsupported target $target_cpu])
    ;;
esac

#as reported, some users may use llvm-c/Disassembler.h instead of local copy in include dir.
#add these macros for avoid compilation failed.

AC_DEFINE(__STDC_LIMIT_MACROS)
AC_DEFINE(__STDC_CONSTANT_MACROS)



#for as wrapper.
AC_SUBST([ASLIBEXECDIR], ['${libexecdir}/as'])

#for ld_class involk in ld64 and other command call.
if test "$target_alias"; then
AC_SUBST([PROGRAM_PREFIX], ['${target_alias}-'])
fi

#disable warnings.

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


# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL
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

AC_CHECK_LIB([dl],[dlopen],[
         DL_LIBS=-ldl
         ])
AC_SUBST(DL_LIBS)

AC_CHECK_LIB([pthread],[pthread_create],[
         PTHREAD_FLAGS=-pthread
         ])
AC_SUBST(PTHREAD_FLAGS)

AC_CHECK_LIB([uuid],[uuid_generate_random],[
         UUID_LIBS=-luuid
         ])
AC_SUBST(UUID_LIBS)

AC_CHECK_LIB([crypto],[MD5_Init],[
         CRYPT_LIBS=-lcrypto
         ])
AC_SUBST(CRYPT_LIBS)

AC_CHECK_LIB([xar], [xar_open],[
         XAR_LIBS=-lxar
         ])
AC_SUBST(XAR_LIBS)

AC_C_BIGENDIAN([AC_SUBST([ENDIAN_FLAG],[-D__BIG_ENDIAN__=1])],
			[AC_SUBST([ENDIAN_FLAG],[-D__LITTLE_ENDIAN__=1])])

# Check LTO
AC_CHECK_PROG(HAVE_LLVM_CONFIG, llvm-config, true, false)

#if test "x$HAVE_LLVM_CONFIG" = "xfalse"; then
#        AC_CHECK_PROG(HAVE_LLVM_CONFIG_32, llvm-config-3.2, true, false)
#        if test "x$HAVE_LLVM_CONFIG_32" = "xfalse"; then
#                AC_MSG_ERROR([llvm-config or llvm-config-3.2 not found on your system,please install related packages])
#        else
#	        LLVM_LIBDIR=`llvm-config-3.2 --libdir`
#        	if test -f $LLVM_LIBDIR/libLTO.so;then
#                	LTO_LIBS="-L`llvm-config-3.2 --libdir` -lLTO"
#                	LTO_DEFS="-DLTO_SUPPORT=1"
#        	fi
#        fi
#else
#        LLVM_LIBDIR=`llvm-config --libdir`
#        if test -f $LLVM_LIBDIR/libLTO.so;then
#                LTO_LIBS="-L`llvm-config --libdir` -lLTO"
#                LTO_DEFS="-DLTO_SUPPORT=1"
#        fi
#fi

# Check LTO
AC_CHECK_PROG([llvm_config], [llvm-config],[yes],[no])
if test "x$llvm-config" = "xno"; then
        AC_MSG_ERROR("Could not find llvm-config.")
else
        LLVM_LIBDIR=`llvm-config --libdir`
        if test -f $LLVM_LIBDIR/libLTO.so;then
                LTO_LIBS="-L`llvm-config --libdir` -lLTO"
                LTO_DEFS="-DLTO_SUPPORT=1"
        fi
fi

AC_SUBST(LTO_LIBS)
AC_SUBST(LTO_DEFS)

#compile ld_classic or not. only for 32bit.
# LD32=""
# cat > conftest.c <<EOF
# #if defined(__x86_64__) || (!defined(__i386__) && defined(__LP64__))
# host_address=64
# #else
# host_address=32
# #endif
# EOF
# OSBIT=`${CC-cc} -E conftest.c | grep host_address=`
# rm -f conftest.c

# if test "$OSBIT" = "host_address=32"; then
# AC_MSG_NOTICE(["Your system is 32bit, enable ld_classic build"])
# LD32="ld"
# else
# AC_MSG_NOTICE(["Your system is 64bit, disable ld_classic"])
# fi

#AC_SUBST([CCTOOLS], [cctools-846.2.1])
#AC_CHECK_SIZEOF([long]) 
#AS_IF([test "$ac_cv_sizeof_long" -eq 8], 
#    [AC_SUBST([LD], [ld64-224.1])], 
#    [AC_SUBST([LD], [cctools-846.2.1/ld])]) 


# sed 's/cctools-846.2.1/cctools-###' to change version numbers until
# AC_CONFIG_FILES([$fu], [], [fu='fu']) does what it and the 
# documentation and examples claim it should!
AC_CONFIG_FILES([
	Makefile
	libstuff/Makefile
	ar/Makefile
	as/arm/Makefile
	as/arm64/Makefile
	as/i386/Makefile
	as/x86_64/Makefile
	as/ppc/Makefile
	as/ppc64/Makefile
	as/Makefile
	man/Makefile
	misc/Makefile
	otool/Makefile
	ld/Makefile

	ld64/Makefile
	ld64/3rd/Makefile
	ld64/3rd/BlocksRuntime/Makefile
	ld64/parsers/Makefile
	ld64/passes/Makefile
	ld64/other/Makefile
])

AC_OUTPUT
