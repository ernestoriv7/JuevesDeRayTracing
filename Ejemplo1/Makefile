CC=gcc
CFLAGS=-I./src -Wall -Wextra -O2
LDFLAGS=-lm
SRC=src/main.c src/vector.c src/sphere.c src/raytracer.c
OBJ=$(SRC:.c=.o)
TARGET=raytracer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) output.ppm output.png

run: $(TARGET)
	./$(TARGET)

view: $(TARGET)
	./$(TARGET)
	convert output.ppm output.png
	explorer.exe output.png