CC = gcc
CFLAGS = -Wall -std=c99 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -lm -ldl -lpthread -framework OpenGL -lX11

SRCDIR = src
OUTDIR = bin
TARGET = $(OUTDIR)/game

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(OUTDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)


