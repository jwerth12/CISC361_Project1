slist: student.o
	gcc student.o -g -o slist

student.o: student.c student.h
	gcc -g -c student.c

clean: 
	\rm *.o student
