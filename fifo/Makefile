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
LDFLAGS +=
ifeq ($(OS),Windows_NT)
CXXFLAGS += -g -Wall -std=c++17 -MD -DPOCO_WIN32_UTF8
LIBFLAGS := -lPocoFoundation -lPocoUtil
INCLUDEFLAGS :=
else
CXXFLAGS += -g -Wall -std=c++17 -MD
LIBFLAGS := -L$(POCO_PATH)/lib -lPocoUtil -lPocoFoundation
INCLUDEFLAGS := -I$(BOOST_PATH)/include -I$(POCO_PATH)/include
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

.PHONY: all clean distclean gtest gtest-clean

all: $(BINDIR)/$(TARGET) gtest

$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	$(CXX) -c -o $@ $(CXXFLAGS) $<

gtest:
	make -C ./gtest

gtest-clean:
	make -C ./gtest clean

clean: gtest-clean
	rm -f $(OBJS)
	rm -f $(TARGET)
	rm -f $(DEPS)

distclean: clean

-include $(DEPS)
