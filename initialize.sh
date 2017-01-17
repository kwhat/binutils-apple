#!/bin/sh

CCV=886
LDV=264.3.102

wget http://opensource.apple.com/tarballs/cctools/cctools-${CCV}.tar.gz
wget http://opensource.apple.com/tarballs/ld64/ld64-${LDV}.tar.gz

tar xzvf cctools-${CCV}.tar.gz
tar xzvf ld64-${LDV}.tar.gz

rm cctools-${CCV}.tar.gz ld64-${LDV}.tar.gz

find ./ -type f -name notes -exec chmod 444 -vf {} \;
find ./ -type f -name \*.[ch] -exec chmod 644 -vf {} \;
find ./ -type d -exec chmod 755 -vf {} \;

# Remove junk Makefile's
find ./ -name Makefile -exec rm -fv {} \;

#
find ./ -type f -name \*.[ch] | xargs sed -i 's/^#import/#include/g'
#find ./ -type f -name \*.h | xargs sed -i 's/^__private_extern__/extern/g'

# Relocate man files
mv -vf ./cctools-${CCV}/ar/ar.1 ./cctools-${CCV}/man
mv -vf ./cctools-${CCV}/ar/ar.5 ./cctools-${CCV}/man

# Clean things we dont use.
rm -Rvf ./cctools-${CCV}/cbtlibs/
rm -Rvf ./cctools-${CCV}/efitools/
rm -Rvf ./cctools-${CCV}/gprof/
rm -Rvf ./cctools-${CCV}/libmacho/
rm -vf ./cctools-${CCV}/PB.project
rm -Rvf ./ld64-${LDV}/ld64.xcodeproj/
rm -vf ./ld64-${LDV}/compile_stubs
rm -vf ./ld64-${LDV}/src/create_configure
mv -vf ./ld64-${LDV}/src/* ./ld64-${LDV}/
mv -vf ./ld64-${LDV}/ld/* ./ld64-${LDV}/
rm -Rvf ./ld64-${LDV}/ld ./ld64-${LDV}/src

cp ./cctools-${CCV}/APPLE_LICENSE ./COPYING
echo "Alexander Barker <alex@1stleg.com>" > ./AUTHORS
touch ChangeLog NEWS README
