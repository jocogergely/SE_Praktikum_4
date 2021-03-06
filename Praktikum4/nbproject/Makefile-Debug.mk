#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/2037729719/FestoProcessAccess.o \
	${OBJECTDIR}/_ext/2037729719/HeightSensor.o \
	${OBJECTDIR}/_ext/2037729719/TestClass.o \
	${OBJECTDIR}/_ext/2037729719/factory.o \
	${OBJECTDIR}/_ext/2037729719/fsm.o \
	${OBJECTDIR}/_ext/2037729719/main.o \
	${OBJECTDIR}/_ext/2037729719/minilab1008processimage.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/praktikum4

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/praktikum4: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/praktikum4 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/2037729719/FestoProcessAccess.o: ../Sources/FestoProcessAccess.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/FestoProcessAccess.o ../Sources/FestoProcessAccess.cpp

${OBJECTDIR}/_ext/2037729719/FestoProcessAccess.h.gch: ../Sources/FestoProcessAccess.h 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o "$@" ../Sources/FestoProcessAccess.h

${OBJECTDIR}/_ext/2037729719/HeightSensor.o: ../Sources/HeightSensor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/HeightSensor.o ../Sources/HeightSensor.cpp

${OBJECTDIR}/_ext/2037729719/TestClass.o: ../Sources/TestClass.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/TestClass.o ../Sources/TestClass.cpp

${OBJECTDIR}/_ext/2037729719/factory.o: ../Sources/factory.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/factory.o ../Sources/factory.cpp

${OBJECTDIR}/_ext/2037729719/fsm.o: ../Sources/fsm.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/fsm.o ../Sources/fsm.cpp

${OBJECTDIR}/_ext/2037729719/main.o: ../Sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/main.o ../Sources/main.cpp

${OBJECTDIR}/_ext/2037729719/minilab1008processimage.o: ../Sources/minilab1008processimage.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2037729719
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2037729719/minilab1008processimage.o ../Sources/minilab1008processimage.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/praktikum4

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
