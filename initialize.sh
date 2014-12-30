#!/bin/sh

CCV=862
LDV=241.9

wget http://opensource.apple.com/tarballs/cctools/cctools-${CCV}.tar.gz
wget http://opensource.apple.com/tarballs/ld64/ld64-${LDV}.tar.gz

tar xzvf cctools-${CCV}.tar.gz
tar xzvf ld64-${LDV}.tar.gz

rm cctools-${CCV}.tar.gz ld64-${LDV}.tar.gz

chmod -Rvf o+w *

# Remove junk Makefile's
find ./ -name Makefile -exec rm -fv {} \;

#
find ./ -type f -name \*.[ch] | xargs sed -i 's/^#import/#include/g'
#find ./ -type f -name \*.h | xargs sed -i 's/^__private_extern__/extern/g'

# Clean things we dont use.
rm -Rvf ./cctools-${CCV}/cbtlibs/
rm -Rvf ./cctools-${CCV}/efitools/
rm -Rvf ./cctools-${CCV}/gprof/
rm -Rvf ./cctools-${CCV}/libmacho/
rm -vf ./cctools-${CCV}/PB.project
rm -Rvf ./ld64-${LDV}/ld64.xcodeproj/
rm -vf ./ld64-${LDV}/compile_stubs
rm -vf ./-${LDV}/src/create_configure

cp ./cctools-${CCV}/APPLE_LICENSE ./COPYING
echo "Alexander Barker <alex@1stleg.com>" > ./AUTHORS
touch ChangeLog NEWS README
