#!/bin/sh

echo "Initializing XCode 4.6 CCTools (10.8.4)";

curl -L https://opensource.apple.com/tarballs/cctools/cctools-839.tar.gz | tar xzv --strip 1

#mkdir ./libunwind
#curl -L http://opensource.apple.com/tarballs/libunwind/libunwind-35.1.tar.gz | tar xzv -C ./libunwind --strip 1
#find ./libunwind -name *.s -exec mv -v {} {}x \;

mkdir ./ld64
curl -L https://opensource.apple.com/tarballs/ld64/ld64-136.tar.gz | tar xzv -C ./ld64 --strip 1
curl -L https://opensource.apple.com/tarballs/dyld/dyld-210.2.3.tar.gz | tar xzv -C ./ld64/src/abstraction/ --strip 2 dyld-210.2.3/include/mach-o/
curl -L http://opensource.apple.com/tarballs/libunwind/libunwind-35.1.tar.gz | tar xzv -C ./ld64/src/abstraction/ --strip 2 libunwind-35.1/include/
touch ./ld64/src/ld/configure.h

mkdir ./include/i386
curl -L https://opensource.apple.com/source/xnu/xnu-2050.24.15/osfmk/mach/mig_errors.h > ./include/mach/mig_errors.h
curl -L https://opensource.apple.com/source/xnu/xnu-2050.24.15/bsd/i386/_types.h > ./include/i386/_types.h

mkdir ./libemulated
curl -L https://opensource.apple.com/source/Libc/Libc-825.26/string/strlcpy.c > libemulated/strlcpy.c
curl -L https://opensource.apple.com/source/Libc/Libc-825.26/string/strlcat.c > libemulated/strlcat.c
curl -L https://opensource.apple.com/source/Libc/Libc-825.26/string/FreeBSD/strmode.c > libemulated/strmode.c
touch libemulated/config.h


# Remove junk Makefile's
find ./ -name Makefile -exec rm -fv {} \;
find ./ -type f -name notes -exec chmod 444 -vf {} \;
find ./ -type f -name \*.[ch] -exec chmod 644 -vf {} \;
find ./ -type d -exec chmod 755 -vf {} \;

# Fix private extern
find ./ -type f -a \( -name \*.h -o -name \*.c \) -exec sed -i 's/^__private_extern__/__attribute__((visibility("hidden")))/g' {} \;

find ./patches -maxdepth 1 -name *.patch -exec patch -p1 -i {} \;

echo "Alexander Barker <alex@1stleg.com>" > ./AUTHORS
touch ChangeLog NEWS README
mv APPLE_LICENSE COPYING
