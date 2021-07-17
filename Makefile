EXECUTABLE = tracer

QUIET = @

BINARY_DIR  = Binary
BUILD_DIR   = Build
INCLUDE_DIR = Include
SOUCRE_DIR  = Source

TARGET = $(BINARY_DIR)/$(EXECUTABLE)

SOURCES = $(shell find $(SOUCRE_DIR) -name *.cpp)
OBJECTS = $(patsubst $(SOUCRE_DIR)/%, $(BUILD_DIR)/%, $(SOURCES:.cpp=.o))
DEPENDS = $(OBJECTS:.o=.d)

CXX = g++-9
CXX_FLAGS = -O2 -std=c++17 -Werror -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast               \
	-Wcast-align -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation      \
	-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion \

CHECK = cppcheck
CHECK_FLAGS = -I $(INCLUDE_DIR) --std=c++17 --enable=all --quiet --suppress=missingIncludeSystem .

.PHONY: all
all: $(TARGET)

.PHONY: check
check:
	$(QUIET)$(CHECK) $(CHECK_FLAGS) $(SOUCRE_DIR)

.PHONY: run
run:
	$(QUIET)./$(TARGET)

.PHONY: clean
clean:
	$(QUIET)$(RM) -r $(BUILD_DIR)

.PHONY: wipe
wipe:
	$(QUIET)$(RM) -r $(BUILD_DIR) $(BINARY_DIR)

-include $(DEPENDS)

$(TARGET): $(OBJECTS)
	$(QUIET)mkdir -p $(@D)
	$(QUIET)$(CXX) $^ -o $@

$(BUILD_DIR)/%.o: $(SOUCRE_DIR)/%.cpp
	$(QUIET)mkdir -p $(@D)
	$(QUIET)$(CXX) -I $(INCLUDE_DIR) $(CXX_FLAGS) -MMD -c $< -o $@
