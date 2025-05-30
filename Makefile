CC = g++

CFLAGS = -Wall -Wextra -std=c++11 -I.

SRCS = main.cpp fraction.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = fraction_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

test: all
	./$(TARGET) --help

depend:
	$(CC) -MM $(SRCS) > Makefile.dep

-include Makefile.dep

.PHONY: all clean test