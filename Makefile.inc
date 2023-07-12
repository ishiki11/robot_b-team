mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += \
  DirectionControl.o \
  DistanceMonitoring.o \
  LineMonitoring.o \
  ColorSensor.o \
  Motor.o \
  DirectionControl.o \
  Linetracer.o \
  LineTracerWithStarter.o \
  Starter.o \
  app.c
APPL_LIBS += -lm
APPL_DIRS += \
  $(mkfile_path)basic\control \
  $(mkfile_path)basic\device \
  $(mkfile_path)basic\system
INCLUDES += \
  -I$(mkfile_path)basic\control \
  -I$(mkfile_path)basic\device \
  -I$(mkfile_path)basic\system