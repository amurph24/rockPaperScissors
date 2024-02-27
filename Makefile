COMPILER = gcc
COMPILER_FLAGS = -Wall -Wextra -pedantic-errors
INCLUDE_PATH = -I include
OBJECT_FILES = ./*.o
TARGET = rps
INSTALL_PATH = /usr/local
SCORE_DATA_PATH = /var/lib



all : $(TARGET)

$(TARGET): object
	$(COMPILER) $@ -c $(OBJECT_FILES)

object: 
	$(COMPILER) $(COMPILER_FLAGS) $(INCLUDE_PATH) src/*.c

install: $(TARGET)
	install -m755 $(TARGET) $(INSTALL_PATH)/bin
	mkdir -p $(SCORE_DATA_PATH)/$(TARGET)

clean: 
	rm -f $(OBJECT_FILES) $(TARGET)

uninstall:
	rm -f $(INSTALL_PATH)/bin/$(TARGET)
	rm -f $(SCORE_DATA_PATH/$(TARGET))