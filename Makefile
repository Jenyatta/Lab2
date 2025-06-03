CXX = clang++
CXXFLAGS = -std=c++20
TARGET = main
LIBRARY = libfraction.dylib

all: $(TARGET)

$(TARGET): main.cpp $(LIBRARY)
	$(CXX) $(CXXFLAGS) main.cpp -L. -lmylib -o $(TARGET)

$(LIBRARY): fraction.cpp fraction.h
	$(CXX) $(CXXFLAGS) -dynamiclib fraction.cpp -o $(LIBRARY)

clean:
	rm -f $(TARGET) $(LIBRARY)
