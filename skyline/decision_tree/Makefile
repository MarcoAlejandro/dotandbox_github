# La ruta de tu instalación de Aleph-w
ALEPH = /home/juandiego/Aleph-w/

# La ruta de tu instalación de clang o g++
CXX =  /usr/bin/clang++-3.8 -std=c++14

OPTIMIZATION = -O0

WARN = -Wall -Wextra -Wcast-align -Wno-sign-compare \
	-Wno-write-strings -Wno-parentheses 

FLAGS = -DDEBUG -D_GLIBCXX__PTHREADS -g $(OPTIMIZATION) $(WARN)

INCLUDE = -I. -I../../map/ -I../../dot_H/ -I $(ALEPH) 

LIBS = -L $(ALEPH) \
       -lAleph -lc -lm -lgsl -lgslcblas -lgmp -lmpfr -lasprintf  \
	-lpthread

default: d_tree_node.H main.C
	$(CXX) $(FLAGS) $(INCLUDE) main.C -o main $(LIBS) 

clean:
	$(RM) *~ *.o main 
