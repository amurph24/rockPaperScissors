COMPILER = gcc
COMPILER_FLAGS = -Wall -Wextra -pedantic-errors
INCLUDE_PATH = -I include/
OBJECT_FILES = ./*.o
TARGET = rps
INSTALL_PATH = /usr/local
SCORE_DATA_PATH = /var/lib



all : $(TARGET)

$(TARGET): object
	$(COMPILER) -o $@ $(OBJECT_FILES)

object: 
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH) -c src/*.c

install: $(TARGET)
	install -m777 $(TARGET) $(INSTALL_PATH)/bin
	mkdir -p $(SCORE_DATA_PATH)/$(TARGET)
	chmod a+rw $(SCORE_DATA_PATH)/$(TARGET)

clean: 
	rm -f $(OBJECT_FILES) $(TARGET)

uninstall:
	rm -f $(INSTALL_PATH)/bin/$(TARGET)
	rm -f $(SCORE_DATA_PATH)/$(TARGET)/score.txt
	rm -df $(SCORE_DATA_PATH)/$(TARGET)
