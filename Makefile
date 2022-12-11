NAME = libspeedwm
HEAD = main.h
SRC  = ${NAME}.c ${NAME}.h

include main.mk

default: ${NAME}

${NAME}.o: ${NAME}.c $(HEAD)
	${CC} -c ${NAME}.c -o ${NAME}.o

${NAME}: ${NAME}.o
	${CC} ${NAME}.o -o ${NAME} ${LDFLAGS}

clean:
	rm -f ${NAME}.o
	rm -f ${NAME}
	@echo "Cleaned."

install: all
	[ -f ${NAME} ] && cp -f ${NAME} ${DESTDIR}${PREFIX}/bin || :
	[ -f ${NAME} ] && chmod +x ${DESTDIR}${PREFIX}/bin/${NAME} || :
	@echo "Installed."

dist: clean
	mkdir -p libspeedwm-${VER}
	cp *.c *.h *.mk Makefile LICENSE README.md libspeedwm-${VER}
	tar -cf libspeedwm-${VER}.tar libspeedwm-${VER}
	gzip libspeedwm-${VER}.tar
	rm -rf libspeedwm-${VER}
	@echo "Created libspeedwm-${VER}.tar.gz"

.PHONY: clean all install dist default
