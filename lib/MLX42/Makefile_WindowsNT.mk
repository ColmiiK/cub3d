# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_WindowsNT.mk                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/26 21:32:00 by W2Wizard          #+#    #+#              #
#    Updated: 2024/05/23 16:30:32 by alvega-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# While windows does have support for nmake it offers nowhere near the amount of
# features GnuWin does.

#//= Colors =//#
# Nope :(

CC		:= clang # We need to explicitly mention GCC/CC here.
WINSTFU	:= > NUL 2>&1 # In some cases we want windows to just stfu

# Switch file paths to windows \ delimiter
SHDR	:= $(subst /,\,$(SHDR))
LIB		:= $(subst /,\,$(LIB))
SRCS	:= $(subst /,\,$(SRCS))
OBJS	:= $(subst /,\,$(OBJS))
HDRS 	:= $(subst /,\,$(HDRS))

#//= Make Rules =//#

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo Done

%.o: %.c $(HDRS)
	@echo Compiling: $(notdir $<)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)\mlx_%_shader.c: $(SHADER_DIR)\default.%
	@echo Shader to C: $< -^> $@
	@.\tools\compile_shader.bat $< > $@

clean:
	@echo Cleaning
	@del /F /Q $(OBJS) $(SHDR) $(WINSTFU)

fclean: clean
	@del /F /Q $(NAME) $(WINSTFU)
