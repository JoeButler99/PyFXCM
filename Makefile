CC=g++
BIN=bin/
TEST=test/
BUILD=build/
SRC=src/
CONF=conf/
INC=-Iinclude -I/usr/include/python2.7
LIBS=-Llib -lForexConnect -lfxmsg -lgsexpat -lgstool3 -lhttplib -llog4cplus -lpdas -lsample_tools -lyaml -lboost_python
CCFLAGS=$(INC) -Wall -Werror -O3 -g -mfpmath=sse -march=native -c -std=c++11 -fpic
CPPUNITLINKS=-lcppunit


#
#	Install the python module
#
install: /usr/local/lib/python2.7/dist-packages/PyFXCM.so

/usr/local/lib/python2.7/dist-packages/PyFXCM.so: python-module
	cp $(BIN)PyFXCM.so /usr/local/lib/python2.7/dist-packages/PyFXCM.so
	
#
#	PyFXM Python Module
#
python-module: $(BIN)PyFXCM.so

$(BIN)PyFXCM.so: $(BUILD)PyFXCM.o
	$(CC) -shared -Wl,-soname,"PyFXCM.so" $(INC) $(BUILD)*.o $(LIBS) -fpic -o $(BIN)PyFXCM.so

$(BUILD)PyFXCM.o: sources
	rm -rf $(BUILD)TestRunner.o $(BUILD)GlobalFXCMConnection.o
	$(CC) $(CCFLAGS) $(SRC)PyFXCM.cpp -o $(BUILD)PyFXCM.o


#
#	Test Suite
#
test: $(BIN)testRunner

$(BIN)testRunner: $(BUILD)TestRunner.o
	$(CC) $(BUILD)*.o $(CPPUNITLINKS) $(LIBS) -o $(BIN)testRunner

$(BUILD)TestRunner.o: sources $(BUILD)GlobalFXCMConnection.o
	$(CC) $(CCFLAGS) $(TEST)TestRunner.cpp -o $(BUILD)TestRunner.o

$(BUILD)GlobalFXCMConnection.o: sources
	$(CC) $(CCFLAGS) $(TEST)GlobalFXCMConnection.cpp -o $(BUILD)GlobalFXCMConnection.o




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

