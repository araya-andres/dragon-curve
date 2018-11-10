CXXFLAGS=-std=c++17 -Wall -pedantic
TARGET=app
OBJS=$(patsubst %.cc, %.o, $(wildcard *.cc))

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(TARGET) $(OBJS)
