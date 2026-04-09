#compilador 
CC=gcc

#bandera de compilación
CFLAGS = -Wall -Wextra -Include

#Archivos a compilar
SRC = src/*.c main.c

#Nombre del ejecutable
TARGET = lista_ligada

#Regla principal para compilar
all: 
	$(CC) $(CFLAGS) $(SCR) -o $(TARGET)

#Regla para ejecutar
run: all
	./$(TARGET)

#Regla para borrar los archuvos generados al compilar
clean: 
	rm -f $(TARGET)