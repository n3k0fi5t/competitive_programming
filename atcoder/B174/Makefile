.PHONY = clean all run

CC      = g++-8
CPPFLASGS = -std=c++14 -Wshadow -fsanitize=address

TARGET  := run
objs    := ${CPPCOMPILE}

all: $(objs)
	$(CC) $(CPPFLASGS) -o $(TARGET) $(objs) 

%.o:%.cpp
	$(CC) $(CPPFLASGS) -c $^ -o $@
run:
	$(TARGET)

clean:
	rm -f *.o $(TARGET)
