NAME := test.exe
LIBFT := ../libft.a
LIBFT_HEADER := ../.

TEST_DIR := src
OBJ_DIR := obj

TEST_FILES := $(notdir $(wildcard $(TEST_DIR)/*.c))
OBJ := $(addprefix $(OBJ_DIR)/, $(TEST_FILES:.c=.o))
DEP := $(addprefix $(OBJ_DIR)/, $(TEST_FILES:.c=.d))
TEST_FILES := $(addprefix $(TEST_DIR)/,$(TEST_FILES))


UNITY_DIR := unity
UNITY_FILES := unity.c \
			   unity.h \
			   unity_internals.h
UNITY_FILES := $(addprefix $(UNITY_DIR)/,$(UNITY_FILES))

UNITY_URL_BASE := https://raw.githubusercontent.com/ThrowTheSwitch/Unity/refs/heads/master/src

CFLAGS := -I$(LIBFT_HEADER) -I$(TEST_DIR) -I$(UNITY_DIR) -MMD -MP -Wall -Wextra -Werror -g
CLINKER := $(UNITY_DIR)/unity.c $(LIBFT) -lbsd

# ------------------------------------------------------------------------
# Methods ----------------------------------------------------------------
# ------------------------------------------------------------------------

####################
# Tester compilation
####################

all: test

test: $(UNITY_FILES) $(LIBFT) $(OBJ)
	cc $(OBJ) $(CLINKER) -g -o $(NAME)
	./$(NAME)

$(LIBFT):
	@$(MAKE) --no-print-directory -C ../.

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	cc $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf obj

fclean: clean unity_clean
	rm -f $(NAME)

# ###########
# Unity setup
# ###########

unity_init: $(UNITY_FILES)

unity_clean:
	rm -rf unity

$(UNITY_DIR):
	mkdir -p $@

$(UNITY_DIR)/unity.c: | $(UNITY_DIR)
	wget --quiet -O $@ $(UNITY_URL_BASE)/unity.c

$(UNITY_DIR)/unity.h: | $(UNITY_DIR)
	wget --quiet -O $@ $(UNITY_URL_BASE)/unity.h

$(UNITY_DIR)/unity_internals.h: | $(UNITY_DIR)
	wget --quiet -O $@ $(UNITY_URL_BASE)/unity_internals.h

-include $(DEP)

.PHONY: all test $(LIBFT) clean unity_init unity_clean
