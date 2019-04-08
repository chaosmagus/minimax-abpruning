#
# Makefile
#
#

CXX = g++
LD = g++
CXXFLAGS = -g -pthread -std=c++11 #-DBOOST_LOG_DYN_LINK
LDFLAGS = -g -pthread

#
# You should be able to add object files here without changing anything else
#
TARGET = maxconnect4
OBJ_FILES = ${TARGET}.o gameStatus.o
INC_FILES = ${TARGET}.hpp gameStatus.hpp

#
# Any libraries we might need.
#
LIBRARYS = #-lboost_log_setup -lboost_log -lboost_thread -lboost_system -lpthread


${TARGET}: ${OBJ_FILES}
	${LD} ${LDFLAGS} ${OBJ_FILES} -o $@ ${LIBRARYS}

%.o : %.cc ${INC_FILES}
	${CXX} -c ${CXXFLAGS} -o $@ $<

#
# Please remember not to submit objects or binarys.
#
clean:
	rm -f core ${TARGET} ${OBJ_FILES}

#
# This might work to create the submission tarball in the formal I asked for.
#
submit:
	rm -f core project1 ${OBJ_FILES}
	mkdir `whoami`
	cp Makefile README.txt *.hpp *.cpp `whoami`
	tar cf `whoami`.tar `whoami`
