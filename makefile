#Set this to @ to keep the makefile quiet
SILENCE=@

#---- Outputs ----#
CPPUTEST_HOME = cpputest/cpputest_build
CPPUTEST_CXXFLAGS = -std=c++11
COMPONENT_NAME = TDAI-TPI
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a
	
TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = Gcc

SRC_DIRS = \
	src \

TEST_SRC_DIRS = \
	tests\
	tests/*\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  $(PROJECT_HOME_DIR)/include\

CPPUTEST_USE_MEM_LEAK_DETECTION = Y  
CPPUTEST_USE_GCOV = Y

include MakefileWorker.mk
