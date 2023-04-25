mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += Walker.o  Starter.o Scenario.o SimpleTimer.o ScenarioTracer.o ScenarioTracerWithStarter.o
APPL_DIRS += \
    $(mkfile_path)app\
    $(mkfile_path)unit
INCLUDES += \
    -I$(mkfile_path)app\
    -I$(mkfile_path)unit

