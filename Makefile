CC=gcc
TARGET1=snake-test
TARGET2=port-test

OBJ_DIR = ./build
TARGET_DIR = ./build
SRC_DIR = ./src
TEST_DIR = ./test
INCLUDE_DIR = -I"$(SRC_DIR)/"

all:
	@echo building $(TARGET1)...
	$(CC) -o $(OBJ_DIR)/snake.o -c $(SRC_DIR)/model/snake.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/snake-test.o -c $(TEST_DIR)/snake-test.c $(INCLUDE_DIR)
	$(CC) -o $(TARGET_DIR)/$(TARGET1) $(OBJ_DIR)/snake.o $(OBJ_DIR)/snake-test.o
	@echo done
	@echo building $(TARGET2)...
	$(CC) -o $(OBJ_DIR)/port.o -c $(SRC_DIR)/port/port.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/port-test.o -c $(TEST_DIR)/port-test.c $(INCLUDE_DIR)
	$(CC) -o $(TARGET_DIR)/$(TARGET2) $(OBJ_DIR)/port.o $(OBJ_DIR)/port-test.o
	@echo done


clean:
	@echo cleaning...
	@rm $(OBJ_DIR)/*.o
	@rm $(TARGET_DIR)/$(TARGET1)
	@rm $(TARGET_DIR)/$(TARGET2)
	@echo done
