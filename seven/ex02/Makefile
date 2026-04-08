CC = c++
NAME = array

SRCS = main.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

INCLUDES = -I ./includes

CFLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDES)

ESC = \033[
RESET = $(ESC)0m
BOLD = $(ESC)1m
GREEN = $(ESC)32m
YELLOW = $(ESC)33m
BLUE = $(ESC)34m
MAGENTA = $(ESC)35m
CYAN = $(ESC)36m
WHITE = $(ESC)37m

all: header $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(BLUE)$(BOLD)🔗  Linking files ...$(RESET)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)🚀  Bank compiled successfully!$(RESET)"
	@echo
	@rm -f .header_lock

$(OBJDIR)/%.o: %.cpp 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call show_progress,$<)

clean: header
	@printf "$(MAGENTA)$(BOLD)🗑️   Cleaning up object files $(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)$(BOLD)✓ Removed objects!$(RESET)\n"
	@rm -f .header_lock

fclean: header
	@printf "$(MAGENTA)$(BOLD)🗑️   Cleaning up object files $(RESET)"
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)$(BOLD)✓ Completed!$(RESET)"
	@printf "$(MAGENTA)$(BOLD)🗑️   Cleaning executable $(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Completed!$(RESET)\n"
	@rm -f .header_lock

re: fclean all

.PHONY: all clean fclean re header

header:
	@if [ ! -f .header_lock ]; then \
		touch .header_lock; \
		echo; \
		echo "$(MAGENTA)$(BOLD)🔥  CPP Module 07 Exercise 02$(RESET)"; \
		echo "$(GREEN)$(BOLD)👥  Autor:$(RESET) $(YELLOW)jonnathan-ls$(RESET)"; \
		echo ;\
	fi

# **************************************************************************** #
# Detect terminal width and adjust behavior
# **************************************************************************** #
TERM_WIDTH := $(shell tput cols 2>/dev/null || echo 80)
SAFE_WIDTH := $(shell echo $$(($(TERM_WIDTH) - 10)))
PROGRESS_WIDTH := $(shell echo $$(($(SAFE_WIDTH) > 50 ? 30 : $(SAFE_WIDTH) - 20)))

# **************************************************************************** #
# Define the progress bar and verbose output functions - CLEAN & SIMPLE
# **************************************************************************** #
TOTAL_FILES := $(words $(SRCS))
COMPILED_COUNT = 0
VERBOSE ?= 0

define show_progress
    @$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1))))
    @$(eval SHORT_PATH=$(shell echo $(1) | sed 's|^.*/||'))
    @$(eval PERCENT=$(shell echo $$(($(COMPILED_COUNT)*100/$(TOTAL_FILES)))))
    @$(eval BAR_SIZE=20)
    @$(eval BARS=$(shell echo $$(($(COMPILED_COUNT)*$(BAR_SIZE)/$(TOTAL_FILES)))))
    @$(eval REMAINING=$(shell echo $$(($(BAR_SIZE) - $(BARS)))))
    @$(eval PROGRESS=$(shell printf '█%.0s' $$(seq 1 $(BARS))))
    @$(eval EMPTY=$(shell printf '░%.0s' $$(seq 1 $(REMAINING))))

    @if [ $(VERBOSE) -eq 1 ]; then \
        echo "$(CYAN)$(BOLD)📄  Compiling $(RESET)$(CYAN)$(SHORT_PATH)$(RESET) ($(COMPILED_COUNT)/$(TOTAL_FILES))"; \
    else \
        printf "\r\033[K$(YELLOW)$(BOLD)🔄  $(RESET)$(GREEN)$(PROGRESS)$(WHITE)$(EMPTY)$(RESET) $(PERCENT)%% $(CYAN)$(SHORT_PATH)$(RESET)"; \
        if [ $(COMPILED_COUNT) -eq $(TOTAL_FILES) ]; then \
            printf "\n$(GREEN)$(BOLD)✅  Compilation completed!$(RESET)\n"; \
        fi; \
    fi
endef