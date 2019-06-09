CFLAGS := -g -Og $(CFLAGS) -pg

BUILD_FLAGS := \
	-pthread \
	-pg

BUILD_MACROS := \
	_DEBUG