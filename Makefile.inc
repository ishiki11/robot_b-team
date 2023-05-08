mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += \
  Scenario.o\
  SimpleTimer.o\
  Starter.o\
  Walker.o\
  ScenarioTracer.o\
  ScenarioTracerWithStarter.o\
  LineTracer.o\
APPL_LIBS += -lm
APPL_DIRS += \
  $(mkfile_path)control\
  $(mkfile_path)device\
  $(mkfile_path)system\
INCLUDES += \
  -I$(mkfile_path)control\
  -I$(mkfile_path)device\
  -I$(mkfile_path)system\