INCLUDE=-I../
cdpwd:cdpwd.c
	gcc -I../ cdpwd.c ../lib/error.c ../lib/pathalloc.c

devrdev:devrdev.c
	gcc ${INCLUDE} $^ ../lib/error.c -o $@
