#
# Copyright (c) 2023 Jozef Nagy
# 
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.
#
#

CC := gcc
AR := ar

INTERNAL_CFLAGS := -O2 -g3 -Wall -Wextra -Werror -pedantic -std=c99 -Iinc/

CFLAGS += $(INTERNAL_CFLAGS)
ARFLAGS := rcs

CFILES := $(shell find src -name "*.c")
OBJ := $(CFILES:.c=.o)

LIBRARY := libm.a

.PHONY: all
all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	@printf " AR   $@\n"
	@$(AR) $(ARFLAGS) $@ $(OBJ)

%.o: %.c
	@printf " CC   $^\n"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: format
format:
	@clang-format -i $(shell find src inc -name "*.c" -o -name "*.h")

.PHONY: test
test: $(LIBRARY)
	@$(MAKE) -C test all
	@test/test

.PHONY: docs
docs:
	@printf " DOXY docs/html\n"
	@mkdir -p docs
	@doxygen
	@printf " DOXY docs/latex\n"
	@make -C docs/latex 1>/dev/null
	@mv docs/latex/refman.pdf docs

.PHONY: clean
clean:
	@printf " CLEAN\n"
	@rm -rf $(OBJ) $(LIBRARY) docs/
	@$(MAKE) -C test clean