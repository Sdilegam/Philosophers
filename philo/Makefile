# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 11:25:36 by sdi-lega          #+#    #+#              #
#    Updated: 2022/07/18 04:24:34 by sdi-lega         ###   ########.fr        #
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


#Other#
LIB_DIR				=	libraries/

#####################################
#									#
#			Sources & objects		#
#									#
#####################################

#Common#
SRCS				=	main_philo.c\
						test.c

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
			
sources/headers/%.h:		${DIR}%.c
			@ echo updating header files
			@ echo $@
			../Makeheaders $(shell find ${DIR} -name "*.c" | sed 's/${DIR:/=\/}//' | awk 'BEGIN {FS="."}{print "${DIR}"$$1".c:${DIR}headers/"$$1".h"}')
			touch $@
			@ sleep ${SLEEP_TIME}

#EXECUTABLES#
${NAME}:				${OBJS_DIR} headers ${OBJS}
			@ echo "\r\"$@\" executable created\033[K"
			${SILENT} ${CC} ${OBJS} -o $@
			@ sleep ${SLEEP_TIME}

# ./a.out $(find srcs -name "*.c" | sed 's/srcs\///' | awk 'BEGIN {FS="."}{print "srcs/" $1 ".c:includes/"$1".h"}')

headers:
			../Makeheaders $(shell find ${DIR} -name "*.c" | sed 's/${DIR:/=\/}//' | awk 'BEGIN {FS="."}{print "${DIR}"$$1".c:${DIR}headers/"$$1".h"}')


-include ${DEPENDS}

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

${OBJECTS_DIR}:
			mkdir ${OBJS_DIR}

start:				
			${SILENT} mkdir -p sources/objects
			${SILENT} mkdir -p sources/headers
			
.phony: 	fclean clean clean_bonus clean_libs clean_exe start all mandatory bonus re 

