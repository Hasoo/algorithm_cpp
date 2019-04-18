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
CXXFLAGS += -c -g -Wall -std=c++17 -DPOCO_WIN32_UTF8
LIBFLAGS := -L$(POCO_PATH)/lib -lPocoUtil -lPocoFoundation
INCLUDEFLAGS := -I$(BOOST_PATH)/include -I$(POCO_PATH)/include
else
CXXFLAGS += -c -g -Wall -std=c++17
LIBFLAGS := -lPocoFoundation -lPocoUtil
INCLUDEFLAGS :=
endif

TARGET := test

HEADERDIR := .
SRCDIR := .
OBJDIR := .
BINDIR := .

HEADERS := $(wildcard $(HEADERDIR)/*.h)
SRCS := $(wildcard $(SRCDIR)/*.cc)
OBJS := $(subst $(SRCDIR)/,$(OBJDIR)/,$(SRCS:.cc=.o))

CXXFLAGS += $(INCLUDEFLAGS) -I$(HEADERDIR)
LDFLAGS += $(LIBFLAGS)

.PHONY: all clean distclean

all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(TARGET)
	rm -f core
	cd gtest && make clean

distclean: clean
