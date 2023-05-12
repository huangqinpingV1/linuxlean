include ../Makefile.inc

GEN_EXE = backtrace
EXE =${GEN_EXE}

all:${GEN_EXE}

clean:
	${RM} ${EXE} *.o
showall:
	@echo ${EXE}

${EXE}:${TLPI_LIB}  #True as rough appproximation
