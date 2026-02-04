CXX = g++
CXXFLAGS = -Wall -std=c++17 -I. -I./GUI -I./backend/config -I./backend/saves `pkg-config --cflags gtkmm-4.0`
LDLIBS = `pkg-config --libs gtkmm-4.0`

TARGET = osm

SRCS = main.cpp GUI/GUIinit.cpp backend/config/config.cpp backend/config/findPaths.cpp backend/saves/getSaves.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)