# libspeedwm - simple speedwm library
# See LICENSE file for more information

# Compiler
CC="tcc"

VER = 1.8

PREFIX = /usr

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

INCS = -L${X11INC}
LIBS = -L${X11LIB} -lX11

CFLAGS = -march=native -Ofast -lX11 ${INCS}
LDFLAGS = ${LIBS} -g
