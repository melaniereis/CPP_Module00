# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 15:56:54 by meferraz          #+#    #+#              #
#    Updated: 2025/03/18 16:14:43 by meferraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = megaphone

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
CYAN        = \033[0;36m
WHITE       = \033[0;37m
RESET       = \033[0m
BOLD        = \033[1m
DIM         = \033[2m
CHECK       = ✔️
CROSS       = ❌
CLEAN       = 🧹
BUILD       = 🔨
ROCKET      = 🚀
BOOK        = 📚

#------------------------------------------------------------------------------#
#                             NAMES AND PATHS                                  #
#------------------------------------------------------------------------------#

BUILD_PATH  = .build
SRC_PATH    = .
INC_PATH    = .

HEADERS     = $(addprefix $(INC_PATH)/, )

SRCS        = $(SRC_PATH)/megaphone.cpp

OBJS        = $(SRCS:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

#------------------------------------------------------------------------------#
#                             FLAGS & COMMANDS                                 #
#------------------------------------------------------------------------------#

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -g
RM          = rm -fr
MKDIR       = mkdir -p
INCLUDES    = -I$(INC_PATH)


# Valgrind options
V_ARGS      = --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

all: $(NAME)
	@printf "\n${GREEN}${BOLD}${CHECK} Build completed successfully!${RESET}\n"

$(NAME): $(OBJS) | $(BUILD_PATH)
	@printf "${CYAN}${DIM}Linking megaphone...${RESET}\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@printf "${GREEN}${BOLD}${CHECK} Megaphone compiled!${RESET}\n"

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp $(HEADERS) | $(BUILD_PATH)
	@$(MKDIR) $(@D)
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-35s${RESET}\r" "$(notdir $<)"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_PATH):
	@printf "${BLUE}${BOLD}${BUILD} Creating build directory...${RESET}\n"
	@$(MKDIR) $(BUILD_PATH)
	@printf "${GREEN}${CHECK} Build directory ready${RESET}\n"

#------------------------------------------------------------------------------#
#                                TESTING RULES                                 #
#------------------------------------------------------------------------------#

val: $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind...${RESET}\n"
	@valgrind $(V_ARGS) ./$(NAME)

vgdb: $(NAME)
	@printf "${BLUE}${BOLD}Running Valgrind with GDB...${RESET}\n"
	@valgrind --vgdb-error=0 $(V_ARGS) ./$(NAME)

gdb: all
	@printf "${BLUE}${BOLD}Launching GDB...${RESET}\n"
	@gdb -tui -q ./$(NAME) -x .gdbinit

test: all
	@printf "${BLUE}${BOLD}Testing megaphone...${RESET}\n"
	@./$(NAME)

#------------------------------------------------------------------------------#
#                                CLEANING RULES                                #
#------------------------------------------------------------------------------#

clean:
	@printf "${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@$(RM) $(OBJS)
	@printf "${GREEN}${BOLD}${CHECK} Object files removed${RESET}\n"

fclean: clean
	@printf "${YELLOW}${BOLD}${CLEAN} Removing all build artifacts...${RESET}\n"
	@$(RM) $(NAME) $(BUILD_PATH) $(LIBFT_PATH)
	@printf "${GREEN}${BOLD}${CHECK} Full cleanup completed${RESET}\n"

re: fclean all
	@printf "${GREEN}${BOLD}${ROCKET} Rebuild finished${RESET}\n"

.PHONY: all clean fclean re val vgdb gdb test
