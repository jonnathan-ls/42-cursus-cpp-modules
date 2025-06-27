# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlacerda <jlacerda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 12:02:46 by jlacerda          #+#    #+#              #
#    Updated: 2025/06/27 00:07:16 by jlacerda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = megaphone

SRCS = PhoneBook.cpp Contact.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

TOTAL_FILES := $(words $(SRCS))
BAR_LENGTH = 33
COMPILED_COUNT = 0

all: header $(NAME)

header:
	@if [ ! -f .header_lock ]; then \
		touch .header_lock; \
		echo; \
		echo "$(MAGENTA)$(BOLD)🔥  CPP MODULE 01$(RESET)"; \
		echo "$(GREEN)$(BOLD)👥  Autor:$(RESET) $(YELLOW)jonnathan-ls$(RESET)"; \
	fi

$(NAME): $(OBJS)
	@printf "\n$(BLUE)$(BOLD)🔗  Linking files ...$(RESET)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)🚀  Megaphone compiled successfully!$(RESET)"
	@echo
	@rm -f .header_lock

%.o: %.cpp 
	@mkdir -p $(dir $@)
	@$(eval COMPILED_COUNT=$(shell echo $$(($(COMPILED_COUNT)+1))))
	@$(eval SHORT_PATH=$(shell echo $< | sed 's|sources/||'))
	@$(CC) $(CFLAGS) -c $< -o $@
	@if [ $(COMPILED_COUNT) -eq 1 ]; then \
		echo ""; \
		printf "$(BLUE)$(BOLD)🏗️   Building Megaphone $(RESET)\n"; \
	fi
	@if [ $(COMPILED_COUNT) -gt 1 ]; then \
		printf "\033[2A\r"; \
		printf "                                                       \r"; \
	fi
	@printf "$(CYAN)$(BOLD)📄  Processing $(RESET)($(COMPILED_COUNT)/$(TOTAL_FILES)) \
	$(CYAN)$(SHORT_PATH)$(RESET)%*s\r\n" $$(( 60 - $${#SHORT_PATH} )) " "
	@$(eval FILLED=$(shell echo $$(($(COMPILED_COUNT)*$(BAR_LENGTH)/$(TOTAL_FILES)))))
	@printf "$(YELLOW)$(BOLD)🔄  $(RESET)$(YELLOW)%s$(RESET) \n" "$(shell printf '▓%.0s' $$(seq 1 $(FILLED)))"
	@if [ $(COMPILED_COUNT) -eq $(TOTAL_FILES) ]; then \
		sleep 0.25; \
		printf "\033[3A\r"; \
		printf "                                                       \r"; \
		printf "$(BLUE)$(BOLD)🏗️   Building the program $(GREEN)$(BOLD)✓ Completed!$(RESET)\n"; \
		printf "                                                       \r"; \
		printf "$(CYAN)$(BOLD)📄  Processing $(RESET)($(COMPILED_COUNT)/$(TOTAL_FILES)) \
		$(CYAN)$(SHORT_PATH)$(RESET)%*s\n" $$(( 60 - $${#SHORT_PATH} )) " "; \
		printf "$(YELLOW)$(BOLD)🔄  $(RESET)$(YELLOW)%s$(RESET) \n" "$(shell printf '▓%.0s' $$(seq 1 $(FILLED)))"; \
	fi


clean: header
	@printf "\n$(MAGENTA)$(BOLD)🗑️   Cleaning up object files $(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)$(BOLD)✓ Removed objects!$(RESET)\n"
	@rm -f .header_lock

fclean: header
	@printf "\n$(MAGENTA)$(BOLD)🗑️   Cleaning up object files $(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)$(BOLD)✓ Completed!$(RESET)"
	@printf "$(MAGENTA)$(BOLD)🗑️   Cleaning executable $(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Completed!$(RESET)"
	@rm -f .header_lock
	@echo

re:
	@rm -f .header_lock
	@$(MAKE) --no-print-directory -s fclean all

.PHONY: all clean fclean re header