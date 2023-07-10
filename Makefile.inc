mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += \
  SimpleTimer.o\
  Starter.o\
  Walker.o\
  ScenarioTracer.o\
  ScenarioTracerWithStarter.o\
  LineTracer.o\
APPL_LIBS += -lm
APPL_DIRS += \
  $(mkfile_path)basic\control
  $(mkfile_path)basic\device
  $(mkfile_path)basic\system
INCLUDES += \
  -I$(mkfile_path)basic\control
  -I$(mkfile_path)basic\device
  -I$(mkfile_path)basic\system