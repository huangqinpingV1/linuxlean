include  ../Makefile.inc

GEN_EXE = copy seek_io  bad_exclusive_open  t_readv atomic_append  multi_descriptors\
	  t_truncate

LINUX_EXE = large_file

EXE =${GEN_EXE} ${LINUX_EXE}

all: ${EXE}

allgen:  ${GEN_EXE}
clean:
	${RM} ${EXE} *.o

showall:
	@echo ${EXE}

${EXE}:${TLPI_LIB}    #True as a rough approximation
