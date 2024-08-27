CC = g++
LDFLAGS = -lSDL2

OBJS = Emulator.o CPU.o Cartridge.o ROM.o
EXECUTABLE = Emulator

default: $(EXECUTABLE)

%.o: %.cpp %.h
	$(CC) -c -o $@ $<

%.o: %.cpp
	$(CC) -c -o $@ $<

$(EXECUTABLE): $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(LDFLAGS)

clean:
	-rm $(OBJS) $(EXECUTABLE)
