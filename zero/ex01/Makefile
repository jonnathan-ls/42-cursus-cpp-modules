# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 12:02:46 by jlacerda          #+#    #+#              #
#    Updated: 2025/07/05 16:23:43 by jlacerda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = phonebook

SRCS = PhoneBook.cpp Contact.cpp main.cpp utils.cpp

OBJDIR = objects
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

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
	@rm -f $(OBJS)
	@echo "$(GREEN)$(BOLD)✓ Removed objects!$(RESET)\n"
	@rm -f .header_lock

fclean: header
	@printf "$(MAGENTA)$(BOLD)🗑️   Cleaning up object files $(RESET)"
	@rm -f $(OBJS)
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
		echo "$(MAGENTA)$(BOLD)🔥  CPP Module 00 Exercise 01$(RESET)"; \
		echo "$(GREEN)$(BOLD)👥  Autor:$(RESET) $(YELLOW)jonnathan-ls$(RESET)"; \
		echo ;\
	fi

# **************************************************************************** #
# Define the progress bar and verbose output functions
# **************************************************************************** #
TOTAL_FILES := $(words $(SRCS))
BAR_LENGTH = 27
COMPILED_COUNT = 0
VERBOSE ?= 0
TRUNCATE_FOLDER = '' # 's|sources/||'

FILLED_FN = $(shell echo $$(($(COMPILED_COUNT)*$(BAR_LENGTH)/$(TOTAL_FILES))))

CLEAR_LINE = printf "\033[2A\r"; printf "%60s\r";
COMPILE_TITLE = printf "$(BLUE)$(BOLD)🏗️   Building $(NAME) $(RESET)\n";

define show_progress
	@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1))))
	@$(eval SHORT_PATH=$(shell echo $(1) | sed ${TRUNCATE_FOLDER}))
	@if [ $(VERBOSE) -eq 1 ]; then \
		echo "$(CYAN)$(BOLD)📄  Compiling \
		$(RESET)$(CYAN)$(SHORT_PATH)$(RESET) \
		($(COMPILED_COUNT)/$(TOTAL_FILES))"; \
	else \
		$(eval FILLED=$(FILLED_FN)) \
		$(eval PROGRESS_BAR=$(shell printf '▓%.0s' $$(seq 1 $(FILLED)))) \
		[ $(COMPILED_COUNT) -eq 1 ] && { ${COMPILE_TITLE} } || true; \
		[ $(COMPILED_COUNT) -gt 1 ] && { ${CLEAR_LINE} } || true; \
		printf "$(CYAN)$(BOLD)📄  Processing $(RESET)($(COMPILED_COUNT)/$(TOTAL_FILES)) \
		$(CYAN)$(SHORT_PATH)$(RESET)%*s\r\n" $$(( 60 - $${#SHORT_PATH} )) " "; \
		printf "$(YELLOW)$(BOLD)🔄  $(RESET)$(YELLOW)%s$(RESET) \n" "$(PROGRESS_BAR)"; \
		[ $(COMPILED_COUNT) -eq $(TOTAL_FILES) ] && { \
			sleep 0.25; \
			printf "\033[3A\r%60s\r" ""; \
			printf "$(BLUE)$(BOLD)🏗️   Building $(NAME) $(GREEN)$(BOLD)✓ Completed!$(RESET)\n%60s\r" ""; \
			printf "$(CYAN)$(BOLD)📄  Processing $(RESET)($(COMPILED_COUNT)/$(TOTAL_FILES)) \
			$(CYAN)$(SHORT_PATH)$(RESET)%*s\n" $$(( 60 - $${#SHORT_PATH} )) " "; \
			printf "$(YELLOW)$(BOLD)🔄  $(RESET)$(YELLOW)%s$(RESET) \n" "$(PROGRESS_BAR)"; \
		} || true; \
	fi
endef
