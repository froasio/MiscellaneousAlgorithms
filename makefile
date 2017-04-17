#Set this to @ to keep the makefile quiet
SILENCE=@

#---- Outputs ----#
CPPUTEST_HOME = cpputest/cpputest_build
CPPUTEST_CXXFLAGS = -std=c++11 -Wno-switch-enum
COMPONENT_NAME = MISCELLANEUS-ALGORITHMS
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a
	
TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = Gcc

SRC_DIRS = \
	src \
	src/TagParser\

TEST_SRC_DIRS = \
	tests\
	tests/*\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  $(PROJECT_HOME_DIR)/include\
  $(PROJECT_HOME_DIR)/include/TagParser\

CPPUTEST_USE_MEM_LEAK_DETECTION = N
CPPUTEST_USE_GCOV = Y

include MakefileWorker.mk
