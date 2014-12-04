CC=g++
BIN=bin/
TEST=test/
BUILD=build/
SRC=src/
CONF=conf/
INC=-Iinclude
LIBS=-Llib -lForexConnect -lfxmsg -lgsexpat -lgstool3 -lhttplib -llog4cplus -lpdas -lsample_tools -lyaml
CCFLAGS=$(INC) -Wall -Werror -O3 -mfpmath=sse -march=native -c -std=c++11
CPPUNITLINKS=-lcppunit
	
#
#	Test Suite
#
test: $(BIN)testRunner

$(BIN)testRunner: $(BUILD)TestRunner.o
	$(CC) $(BUILD)*.o $(CPPUNITLINKS) $(LIBS) -o $(BIN)testRunner

$(BUILD)TestRunner.o: sources
	$(CC) $(CCFLAGS) $(TEST)TestRunner.cpp -o $(BUILD)TestRunner.o



#
#	General Source Files
#
	
sources: $(BUILD)YamlConfigLoader.o $(BUILD)PriceCollector.o $(BUILD)SessionHandler.o


$(BUILD)PriceCollector.o: $(BUILD)PriceDataRecord.o $(BUILD)ResponseListener.o
	$(CC) $(CCFLAGS) $(SRC)PriceCollector.cpp -o $(BUILD)PriceCollector.o

$(BUILD)PriceDataRecord.o:
	$(CC) $(CCFLAGS) $(SRC)PriceDataRecord.cpp -o $(BUILD)PriceDataRecord.o

$(BUILD)SessionHandler.o: $(BUILD)SessionStatusListener.o
	$(CC) $(CCFLAGS) $(SRC)SessionHandler.cpp -o $(BUILD)SessionHandler.o
	
$(BUILD)ResponseListener.o:
	$(CC) $(CCFLAGS) $(SRC)ResponseListener.cpp -o $(BUILD)ResponseListener.o

$(BUILD)SessionStatusListener.o: $(BUILD)LoginParams.o $(BUILD)OptionParams.o
	$(CC) $(CCFLAGS) $(SRC)SessionStatusListener.cpp -o $(BUILD)SessionStatusListener.o

$(BUILD)OptionParams.o: $(BUILD)FXCMAPIException.o
	$(CC) $(CCFLAGS) $(SRC)OptionParams.cpp -o $(BUILD)OptionParams.o

$(BUILD)LoginParams.o: $(BUILD)FXCMAPIException.o
	$(CC) $(CCFLAGS) $(SRC)LoginParams.cpp -o $(BUILD)LoginParams.o

$(BUILD)YamlConfigLoader.o: $(BUILD)FXCMAPIException.o
	$(CC) $(CCFLAGS) $(SRC)YamlConfigLoader.cpp -o $(BUILD)YamlConfigLoader.o

$(BUILD)FXCMAPIException.o:
	$(CC) $(CCFLAGS) $(SRC)FXCMAPIException.cpp -o $(BUILD)FXCMAPIException.o
	



#
#	Clean Build
#
clean:
	rm -rf build/*
	rm -f *~

