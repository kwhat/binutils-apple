noinst_LTLIBRARIES = libCodeSignBlobs.la

noinst_HEADERS = blob.h endian.h memutils.h superblob.h

libCodeSignBlobs_la_CXXFLAGS = \
	-fblocks \
	$(ENDIAN_FLAG) \
	$(WARNINGS) \
	$(LLVM_CXXFLAGS) \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/ld64/src/abstraction \
	-I$(top_srcdir)/ld64/src/ld \
	-idirafter${OSX_SDKDIR}/usr/include \
	-DOTOOL

libCodeSignBlobs_la_SOURCES = blob.cpp
