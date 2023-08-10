#
# Copyright (c) 2023 Jozef Nagy
# 
# Use of this source code is governed by an MIT-style
# license that can be found in the LICENSE file or at
# https://opensource.org/licenses/MIT.
#
#

CC := gcc
LD := $(CC)

INTERNAL_CFLAGS := -O2 -g3 -Wall -Wextra -Werror -pedantic -std=c99 -I../inc/
INTERNAL_LDFLAGS :=

CFLAGS += $(INTERNAL_CFLAGS)
LDFLAGS += $(INTERNAL_LDFLAGS)

CFILES := $(shell find . -name "*.c")
OBJ := $(CFILES:.c=.o)

PROGRAM := test

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	@printf " LD   $@\n"
	@$(LD) $(LDFLAGS) $(OBJ) ../libm.a -o $@

%.o: %.c
	@printf " CC   $^\n"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@printf " CLEAN\n"
	@rm -rf $(OBJ) $(PROGRAM)
