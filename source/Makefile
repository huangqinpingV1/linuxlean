#Makefile to build all programs in all subdirectories
#
#DIRS is a list of all subdirectories containing makefiles
#(The library directory is first so that the library gets built first)
DIRS = lib\
       fileio\
       backtrace

#The "namespace" and "seccomp" directories are delibrately excluded from
#the above list because much of the code in those directories requires a
#relatively recen kernel and userspace to build.Neverthless, each of those
#directories container a Makefile

BUILD_DIRS = ${DIRS}

#Dummy targets for building and clobbering  everything in all subdirectories

all:
	@ echo  ${BUILD_DIRS}
	@ for dir in ${BUILD_DIRS}; do (cd $${dir};${MAKE});\
		if test $$? -ne 0; then break;fi;done
allgen:
	@ for dir in ${BUILD_DIRS};do (cd $${dir};${MAKE} allgen);done

clean:
	@ for dir in ${BUILD_DIRS};do (cd $${dir};${MAKE} clean);done
