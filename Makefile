CC = gcc
CFLAGS = -W -Wall
TARGET = mini_project
OBJECTS = main.o product.o
#all : $(TARGET)
#$(TARGET) : $(OBJECTS)
#	$(CC) $(CFLAGS) o $@ $^

mini_project : main.c product.o
	$(CC) -o $@ $^
mini_project_deb : main.c product.o
	$(CC) -DDEBUG -o $@ $^
clean : rm *.o mini_project
