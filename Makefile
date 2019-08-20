EXECUTABLE = tracer

QUIET = @

# Directory structure
BINARY_DIR  = Binary
BUILD_DIR   = Build
INCLUDE_DIR = Include
SOUCRE_DIR  = Source

TARGET = $(BINARY_DIR)/$(EXECUTABLE)

# List of source files from source directory and its subdirectories
SOURCES = $(shell find $(SOUCRE_DIR) -name *.cpp)
# List of object files
OBJECTS = $(patsubst $(SOUCRE_DIR)/%, $(BUILD_DIR)/%, $(SOURCES:.cpp=.o))
# List of dependencies
DEPENDS = $(OBJECTS:.o=.d)

# Compiler and compiler flags
CXX = g++-9
CXXFLAGS = -O2 -std=c++17 -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast                \
	-Wcast-align -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation      \
	-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion \

# Cppcheck integration
CHECK = cppcheck
CHECKFLAGS = -I $(INCLUDE_DIR) --language=c++ --std=c++17 --enable=all --suppress=missingIncludeSystem .

.PHONY: all
all: $(TARGET)

.PHONY: check
check:
	$(QUIET)$(CHECK) $(CHECKFLAGS) $(SOUCRE_DIR)

.PHONY: run
run:
	$(QUIET)./$(TARGET)

.PHONY: clean
clean:
	$(QUIET)$(RM) -r $(BUILD_DIR)

-include $(DEPENDS)

$(TARGET): $(OBJECTS)
	$(QUIET)mkdir -p $(@D)
	$(QUIET)$(CXX) $^ -o $@

$(BUILD_DIR)/%.o: $(SOUCRE_DIR)/%.cpp
	$(QUIET)mkdir -p $(@D)
	$(QUIET)$(CXX) -I $(INCLUDE_DIR) $(CXXFLAGS) -MMD -c $< -o $@
