CXX = g++
CXXFLAGS = -Wall -std=c++17 -I. -I./GUI -I./backend `pkg-config --cflags gtkmm-4.0`
LDLIBS = `pkg-config --libs gtkmm-4.0`

TARGET = osm

SRCS = main.cpp GUI/GUIinit.cpp backend/config.cpp backend/findPaths.cpp backend/getSaves.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)