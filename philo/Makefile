# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 12:28:37 by sdi-lega          #+#    #+#              #
#    Updated: 2022/09/14 13:39:25 by sdi-lega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#																			   #
#									VARIABLES								   #
#																			   #
################################################################################

NAME				=	philo#Name of project.

#####################################
#									#
#			Directories				#
#									#
#####################################

#Common#
DIR					=	sources/
OBJ_DIR				=	${DIR}objects/
HDR_DIR				=	${DIR}headers/


#Other#
LIB_DIR				=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

#Common#
C_SRCS				=	main_Philosophers\
						ft_atoi\
						philosophers_list\
						time_handling\
						actions\
						death_handler\
						clean_exit\
						program_initiation\
						philosophers_initiation
						
SRCS				=	${addsuffix .c, ${C_SRCS}}


OBJS				=	${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

HDRS				= 	${addprefix sources/headers/, ${SRCS:.c=.h}}
DEPENDS				=	${OBJS:.o=.d}
EXECUTABLES			=	${NAME} #Modify if other executables needed#

#####################################
#									#
#				OTHERS				#
#									#
#####################################

CC					=	cc
INCLUDE				=	-Iincludes -I${DIR}headers/

CC_FLAGS			=	${INCLUDE} -MMD -Wall -Werror -Wextra
RM					=	rm -f
SLEEP_TIME			=	0.2
SILENT				=	@

################################################################################
#																			   #
#										RULES								   #
#																			   #
################################################################################

#####################################
#									#
#				GENERAL				#
#									#
#####################################

all:				mandatory 
re:					fclean all

mandatory:			${NAME}

#####################################
#									#
#				COMPILING			#
#									#
#####################################
#OBJECTS#
${OBJ_DIR}%.o:		${DIR}%.c
			@ echo  "\rCreating common \"${@F:.c=.o}\" object file.\033[K\c"
			${SILENT} ${CC} ${CC_FLAGS} -c $< -o $@
			@ sleep ${SLEEP_TIME}

#EXECUTABLES#
${NAME}:				${OBJ_DIR} ${OBJS}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${OBJS} -o $@
			@ sleep ${SLEEP_TIME}

# ./a.out $(find srcs -name "*.c" | sed 's/srcs\///' | awk 'BEGIN {FS="."}{print "srcs/" $1 ".c:includes/"$1".h"}')

headers:
			../Makeheaders $(shell find ${DIR} -name "*.c" | sed 's/${DIR:/=\/}//' | awk 'BEGIN {FS="."}{print "${DIR:/=}"$$1".c:${DIR}headers"$$1".h"}')


-include ${DEPENDS}

debug: CC_FLAGS += -g
debug: re

norm:
		python3 -m c_formatter_42 ${addprefix ${DIR}, ${SRCS}}
		python3 -m c_formatter_42 ${addprefix ${DIR}headers/, ${SRCS:.c=.h}} sources/headers/Philosophers.h

#####################################
#									#
#				CLEANING			#
#									#
#####################################

clean:
			@ echo "\rRemoving objects files (${notdir ${OBJS}} ${notdir ${MANDA_OBJS}}).\033[K\c"
			${SILENT} ${RM} ${OBJECTS} ${OBJS} ${DEPENDS}
			@ sleep ${SLEEP_TIME}

clean_bonus:
			@ echo "\rRemoving bonnus objects files (${notdir ${BONUS_OBJS}}).\033[K\c"
			${SILENT} ${RM} ${BONUS_OBJS} ${DEPENDS}
			@ sleep ${SLEEP_TIME}

${addprefix clean_,${dir ${ALL_LIBS}}}:
			@ echo "\rRemoving libraries (${patsubst clean_%,%, $@}).\033[K\c"
			${SILENT} make clean -sC ${patsubst clean_%, libraries/%, $@}
			@ sleep ${SLEEP_TIME}

clean_exe:
			@ echo "\rRemoving executables (${notdir ${EXECUTABLES}}).\033[K\c"
			${SILENT} ${RM} ${EXECUTABLES}
			@ sleep ${SLEEP_TIME}

fclean:			clean ${addprefix clean_,${dir ${ALL_LIBS}}} clean_exe clean_bonus
			@ echo "\rEverything removed.\033[K"
				
#####################################
#									#
#			INITIALIZATION			#
#									#
#####################################

${OBJ_DIR}:
			mkdir -p ${OBJ_DIR}
${HDR_DIR}:
			mkdir -p ${HDR_DIR}

start:				${OBJ_DIR} ${HDR_DIR}
			
.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 

