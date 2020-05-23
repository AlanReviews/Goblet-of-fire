CXX     = g++
RM      = rm -f
DEFINES =
LIBS    =
INCLUDE = -I. -I./include
WARNING = -Wall -Wextra -Werror=return-type
FLAGS   = -g -std=c++11 -O2
CFLAGS  = $(INCLUDE) $(LIBS) $(WARNING) $(FLAGS) $(DEFINES)

NAME    = executable

SOURCES = $(wildcard *.cc)
SRC_OBJECTS = $(patsubst %.cc,%.o,$(SOURCES))

# Add any .o files that aren't built specifically by this project
# (.o files from other sources), otherwise do not change this line
NONSRC_OBJECTS =

all:	$(NAME)

$(NAME):	$(SRC_OBJECTS) $(NONSRC_OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(SRC_OBJECTS) $(NAME)

.PHONY: run
run:	$(NAME)
	./$(NAME)

.PHONY: test
test:	$(NAME)
	./$(NAME) < in.txt

submission:	clean
	$(RM) submission_filename.tar
	tar -cf submission_filename.tar *

%.o:	%.cc
	$(CXX) -c $(CFLAGS) $*.cc -o $*.o
