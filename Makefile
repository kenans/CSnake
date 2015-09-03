CC=gcc
TARGET0=snake
TARGET1=snake-test
TARGET2=port-test
TARGET3=game-test

OBJ_DIR = ./build
TARGET_DIR = ./build
SRC_DIR = ./src
TEST_DIR = ./test
INCLUDE_DIR = -I"$(SRC_DIR)/"
LIBS = -l"curses"

all:
	@echo building objs...
	$(CC) -o $(OBJ_DIR)/snake.o -c $(SRC_DIR)/model/snake.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/smap.o -c $(SRC_DIR)/model/smap.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/food.o -c $(SRC_DIR)/model/food.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/paint.o -c $(SRC_DIR)/view/paint.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/key.o -c $(SRC_DIR)/controller/key.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/port.o -c $(SRC_DIR)/port/port.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/game.o -c $(SRC_DIR)/game.c $(INCLUDE_DIR) 
	@echo done
	@echo building $(TARGET0)...
	$(CC) -o $(OBJ_DIR)/main.o -c $(SRC_DIR)/main.c $(INCLUDE_DIR) 
	$(CC) -o $(TARGET_DIR)/$(TARGET0) $(LIBS) $(OBJ_DIR)/snake.o $(OBJ_DIR)/main.o $(OBJ_DIR)/paint.o $(OBJ_DIR)/food.o $(OBJ_DIR)/smap.o $(OBJ_DIR)/key.o $(OBJ_DIR)/port.o $(OBJ_DIR)/game.o
	@echo done
tests:
	@echo building objs...
	$(CC) -o $(OBJ_DIR)/snake.o -c $(SRC_DIR)/model/snake.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/smap.o -c $(SRC_DIR)/model/smap.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/food.o -c $(SRC_DIR)/model/food.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/paint.o -c $(SRC_DIR)/view/paint.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/key.o -c $(SRC_DIR)/controller/key.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/port.o -c $(SRC_DIR)/port/port.c $(INCLUDE_DIR) 
	$(CC) -o $(OBJ_DIR)/game.o -c $(SRC_DIR)/game.c $(INCLUDE_DIR) 
	@echo done
	@echo building $(TARGET1)...
	$(CC) -o $(OBJ_DIR)/snake-test.o -c $(TEST_DIR)/snake-test.c $(INCLUDE_DIR)
	$(CC) -o $(TARGET_DIR)/$(TARGET1) $(OBJ_DIR)/snake.o $(OBJ_DIR)/snake-test.o
	@echo done
	@echo building $(TARGET2)...
	$(CC) -o $(OBJ_DIR)/port-test.o -c $(TEST_DIR)/port-test.c $(INCLUDE_DIR)
	$(CC) -o $(TARGET_DIR)/$(TARGET2) $(LIBS) $(OBJ_DIR)/port.o $(OBJ_DIR)/port-test.o
	@echo done
	@echo building $(TARGET3)...
	$(CC) -o $(OBJ_DIR)/game-test.o -c $(TEST_DIR)/game-test.c $(INCLUDE_DIR)
	$(CC) -o $(TARGET_DIR)/$(TARGET3) $(LIBS) $(OBJ_DIR)/snake.o $(OBJ_DIR)/game-test.o $(OBJ_DIR)/paint.o $(OBJ_DIR)/food.o $(OBJ_DIR)/smap.o $(OBJ_DIR)/key.o $(OBJ_DIR)/port.o $(OBJ_DIR)/game.o
	@echo done


clean:
	@echo cleaning...
	@rm $(OBJ_DIR)/*.o
	@rm $(TARGET_DIR)/$(TARGET0)
	@rm $(TARGET_DIR)/$(TARGET1)
	@rm $(TARGET_DIR)/$(TARGET2)
	@rm $(TARGET_DIR)/$(TARGET3)
	@echo done
