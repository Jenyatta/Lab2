CXX := g++
CXXFLAGS := -Wall -I.
LDFLAGS := -L. -lfractions

all: fractions.dll main.exe

main.exe: main.cpp fractions.dll
 $(CXX) $(CXXFLAGS) main.cpp -o main.exe $(LDFLAGS)

fractions.dll: fractions.cpp fractions.h
 $(CXX) -shared fractions.cpp -o fractions.dll

clean:
 del main.exe fractions.dll
