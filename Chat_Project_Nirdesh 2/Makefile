BUILD_FILES = server.c client.c
TARGET_FILES = server client

CC = gcc -pthread  

all: $(BUILD_FILES) $(INCLUDE_FILES)
	$(CC) server.c -o server
	$(CC) client.c -o client

clean: 
	rm -f $(TARGET_FILES)
