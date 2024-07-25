CC ?= gcc

SRC_DIR := src
BUILD_DIR := build

CFLAGS := -Wall -Wextra -std=c99 -Iinclude
LDFLAGS := -shared

ifeq ($(DEBUG), 1)
CFLAGS += -O0 -g -DDEBUG
else
CFLAGS += -O3
endif

LIB_CFILES := $(shell find src -type f -name '*.c')
LIB_OBJS := $(LIB_CFILES:src/%.c=$(BUILD_DIR)/lib/%.o)

TEST_CFILES := $(shell find test -type f -name '*.c')
TEST_OBJS := $(TEST_CFILES:src/%.c=$(BUILD_DIR)/test/%.o)

LIBRARY := $(BUILD_DIR)/libmath.so
TEST := $(BUILD_DIR)/test

.PHONY: all
all: $(LIBRARY)

.PHONY: $(LIBRARY) test
test: $(LIBRARY) $(TEST)
	@$(TEST)

$(LIBRARY): $(LIB_OBJS)
	@mkdir -p $(@D)
	@printf "  LD\t$(notdir $@)\n"
	@$(CC) $^ $(LDFLAGS) -o $@

$(TEST):$(TEST_OBJS)
	@$(CC) $(CFLAGS) -L./$(BUILD_DIR) -lmath $^ -o $@

$(BUILD_DIR)/lib/%.o: src/%.c
	@mkdir -p $(@D)
	@printf "  CC\t$(notdir $<)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/test/%.o: test/%.c
	@mkdir -p $(@D)
	@printf "  CC\t$(notdir $<)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)
