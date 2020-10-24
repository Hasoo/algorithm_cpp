# ------------------------------------------------
# Generic Makefile
#
# Author: Hasoo Kim<vaxzeem@i-heart.co.kr>
# Date  : 2010-11-05
#
# Changelog :
#   0.01 - first version
# ------------------------------------------------

CXX := g++
CXXFLAGS += -g -Wall -std=c++17 -MD
LDFLAGS +=
ifeq ($(OS),Windows_NT)
LIBFLAGS := -L$(GTEST_PATH)/lib -lgtest -pthread
INCLUDEFLAGS := -I$(GTEST_PATH)/include
else
LIBFLAGS := -L$(GTEST_PATH)/lib -lgtest -pthread
INCLUDEFLAGS := -I$(GTEST_PATH)/include
endif

TARGET := test

HEADERDIR := .
SRCDIR := .
OBJDIR := .
BINDIR := .

HEADERS := $(wildcard $(HEADERDIR)/*.h)
SRCS := $(wildcard $(SRCDIR)/*.cc)
OBJS := $(subst $(SRCDIR)/,$(OBJDIR)/,$(SRCS:.cc=.o))
DEPS = $(OBJS:.o=.d)

CXXFLAGS += $(INCLUDEFLAGS) -I$(HEADERDIR)
LDFLAGS += $(LIBFLAGS)

.PHONY: all clean distclean

all: $(BINDIR)/$(TARGET) test-exec

$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	$(CXX) -c -o $@ $(CXXFLAGS) $<

test-exec:
	./test

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
	rm -f $(DEPS)

distclean: clean

-include $(DEPS)
