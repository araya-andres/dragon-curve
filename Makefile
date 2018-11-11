CXXFLAGS=-std=c++17 -Wall -pedantic
LDLIBS+=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
TARGET=app
OBJS=$(patsubst %.cc, %.o, $(wildcard *.cc))

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS)

clean:
	rm $(TARGET) $(OBJS)
