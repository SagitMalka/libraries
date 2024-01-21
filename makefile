CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin

# List of source files
SOURCES = $(SRC_DIR)/basicClassification.c $(SRC_DIR)/advancedClassificationLoop.c $(SRC_DIR)/advancedClassificationRecursion.c
HEADERS = $(SRC_DIR)/Numclass.h

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Static libraries
LIB_LOOPS = $(LIB_DIR)/libclassloops.a
LIB_REC = $(LIB_DIR)/libclassrec.a

# Dynamic libraries
LIB_LOOPS_SO = $(LIB_DIR)/libclassloops.so
LIB_REC_SO = $(LIB_DIR)/libclassrec.so

# Main programs
MAIN_S = $(BIN_DIR)/mains
MAIN_D_LOOP = $(BIN_DIR)/maindloop
MAIN_D_REC = $(BIN_DIR)/maindrec

.PHONY: all clean loops recursives recursive loopd mains maindloop maindrec

all: loops recursives recursive loopd mains maindloop maindrec

# Compilation rules for object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation rules for static libraries
$(LIB_LOOPS): $(OBJECTS)
	ar rcs $@ $^

$(LIB_REC): $(OBJECTS)
	ar rcs $@ $^

# Compilation rules for dynamic libraries
$(LIB_LOOPS_SO): $(OBJECTS)
	$(CC) -shared -o $@ $^

$(LIB_REC_SO): $(OBJECTS)
	$(CC) -shared -o $@ $^

# Compilation rules for main programs
$(MAIN_S): $(SRC_DIR)/main.c $(HEADERS) $(LIB_REC)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) -lclassrec

$(MAIN_D_LOOP): $(SRC_DIR)/main.c $(HEADERS) $(LIB_LOOPS_SO)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) -lclassloops -Wl,-rpath,$(LIB_DIR)

$(MAIN_D_REC): $(SRC_DIR)/main.c $(HEADERS) $(LIB_REC_SO)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) -lclassrec -Wl,-rpath,$(LIB_DIR)

# Make targets
loops: $(LIB_LOOPS)

recursives: $(LIB_REC)

recursive: $(LIB_REC_SO)

loopd: $(LIB_LOOPS_SO)

mains: $(MAIN_S)

maindloop: $(MAIN_D_LOOP)

maindrec: $(MAIN_D_REC)

clean:
	rm -f $(OBJECTS) $(LIB_LOOPS) $(LIB_REC) $(LIB_LOOPS_SO) $(LIB_REC_SO) $(MAIN_S) $(MAIN_D_LOOP) $(MAIN_D_REC)
