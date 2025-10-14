CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=main.c vector.c list_ops.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=vect_calc

all: $(SOURCES) $(EXECUTABLE)

-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
		$(CC) $(CFLAGS) $< -o $@
		$(CC) -MM $<> $*.d

clean:
		rm -rf $(OBJECTS) $(EXECUTABLE) *.d
