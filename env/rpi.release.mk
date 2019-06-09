CC := g++-8.1.0
CFLAGS := -Wfatal-errors -Wunreachable-code -Wextra -Wall -std=c++17 -fdiagnostics-color=always
MAX_PARALLEL_JOBS := 4

CFLAGS := -Os -s $(CFLAGS)

LIB_DIRS := \
	/usr/local/gcc-8.1.0/lib \
	/usr/local/lib

INCLUDE_DIRS := \
	/usr/local/gcc-8.1.0/include \
	/usr/local/include

BUILD_DEPENDENCIES :=

LINK_LIBRARIES := \
	$(LINK_LIBRARIES) \
	X11

BUILD_FLAGS := \
	-pthread
