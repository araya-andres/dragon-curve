UNAME=$(shell uname)
CXXFLAGS=-std=c++17 -Wall -pedantic
LDLIBS+=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
TARGET=app
OBJS=$(patsubst %.cc, %.o, $(wildcard *.cc))

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CXX) $(CFLAGS) -c $<

clean:
	rm $(TARGET) $(OBJS)
