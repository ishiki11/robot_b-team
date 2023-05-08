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
  $(mkfile_path)app\
  $(mkfile_path)unit
INCLUDES += \
  -I$(mkfile_path)app\
  -I$(mkfile_path)unit