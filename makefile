SHELL = /bin/bash
RM = rm -rf

CC = arm-linux-gnueabihf-gcc  
CFLAGS = -ol -Wall -Werror -gdwarf-2
LDFLAGS =
CPPFLAGS = $(foreach directory,$(INCDIRS),-I$(directory))


INCDIRS = $(sort $(dir $(HDRS)))

SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
 OBJS = $(SRCS:.c=.o)
#OBJS = $(SRCS:.c*.o)

TARGET = $(lastword $(subst /, ,$(CURDIR)))

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	
.PHONY: run clean

run: $(TARGET)
	@$(SHELL) -c ./$(TARGET)

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)