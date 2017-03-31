CC		= g++
CFLAGS		= -c -Wall
LDFLAGS		= -lpthread
SOURCES		= ant.cpp ../l_thread.cpp ./food.cpp
INCLUDES	= -I.
OBJECTS		= $(SOURCES:.cpp=.o)
TARGET		= queen

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
