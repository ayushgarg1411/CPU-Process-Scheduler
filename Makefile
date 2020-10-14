#Makefile for assignment 3


CC = gcc
WFLAG = -Wall
CFLAG = -c
DFLAG = -ggdb
IFLAG = -I

BINARY = bin
OBJECT = build
INCLUDE = include
SOURCE = src
RESOURCE = resource



all: ${BINARY}/fcfs ${BINARY}/sjf ${BINARY}/priority ${BINARY}/rr ${BINARY}/priority_rr 


${BINARY}/fcfs: ${OBJECT}/scheduler.o ${OBJECT}/list.o ${OBJECT}/cpu.o ${OBJECT}/schedule_fcfs.o
	$(CC) $(WFLAG) ${IFLAG} ${INCLUDE} -o ${BINARY}/fcfs ${OBJECT}/scheduler.o \
		${OBJECT}/schedule_fcfs.o ${OBJECT}/list.o ${OBJECT}/cpu.o


${BINARY}/sjf: ${OBJECT}/scheduler.o ${OBJECT}/list.o ${OBJECT}/cpu.o ${OBJECT}/schedule_sjf.o
	$(CC) $(WFLAG) ${IFLAG} ${INCLUDE} -o ${BINARY}/sjf ${OBJECT}/scheduler.o \
		${OBJECT}/schedule_sjf.o ${OBJECT}/list.o ${OBJECT}/cpu.o


${BINARY}/priority: ${OBJECT}/scheduler.o ${OBJECT}/list.o ${OBJECT}/cpu.o ${OBJECT}/schedule_priority.o
	$(CC) $(WFLAG) ${IFLAG} ${INCLUDE} -o ${BINARY}/priority ${OBJECT}/scheduler.o \
		${OBJECT}/schedule_priority.o ${OBJECT}/list.o ${OBJECT}/cpu.o


${BINARY}/rr: ${OBJECT}/scheduler.o ${OBJECT}/list.o ${OBJECT}/cpu.o ${OBJECT}/schedule_rr.o
	$(CC) $(WFLAG) ${IFLAG} ${INCLUDE} -o ${BINARY}/rr ${OBJECT}/scheduler.o \
		${OBJECT}/schedule_rr.o ${OBJECT}/list.o ${OBJECT}/cpu.o 


${BINARY}/priority_rr: ${OBJECT}/scheduler.o ${OBJECT}/list.o ${OBJECT}/cpu.o ${OBJECT}/schedule_priority_rr.o
	$(CC) $(WFLAG) ${IFLAG} ${INCLUDE} -o ${BINARY}/priority_rr ${OBJECT}/scheduler.o \
		${OBJECT}/schedule_priority_rr.o ${OBJECT}/list.o ${OBJECT}/cpu.o 


${OBJECT}/scheduler.o: ${SOURCE}/scheduler.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/scheduler.o ${SOURCE}/scheduler.c


${OBJECT}/schedule_fcfs.o: ${SOURCE}/schedule_fcfs.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/schedule_fcfs.o ${SOURCE}/schedule_fcfs.c


${OBJECT}/schedule_sjf.o: ${SOURCE}/schedule_sjf.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/schedule_sjf.o ${SOURCE}/schedule_sjf.c


${OBJECT}/schedule_priority.o: ${SOURCE}/schedule_priority.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/schedule_priority.o ${SOURCE}/schedule_priority.c


${OBJECT}/schedule_rr.o: ${SOURCE}/schedule_rr.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/schedule_rr.o ${SOURCE}/schedule_rr.c


${OBJECT}/schedule_priority_rr.o: ${SOURCE}/schedule_priority_rr.c ${INCLUDE}/schedule.h ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/schedule_priority_rr.o ${SOURCE}/schedule_priority_rr.c


${OBJECT}/list.o: ${SOURCE}/list.c ${INCLUDE}/list.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/list.o ${SOURCE}/list.c


${OBJECT}/cpu.o: ${SOURCE}/cpu.c ${INCLUDE}/cpu.h ${INCLUDE}/task.h
	$(CC) $(WFLAG) ${CFLAG} ${IFLAG} ${INCLUDE} -o ${OBJECT}/cpu.o ${SOURCE}/cpu.c


.PHONY: clean run


clean:
	rm -rf ${OBJECT}/*  ${BINARY}/*


run: ${BINARY}/fcfs ${BINARY}/sjf ${BINARY}/priority ${BINARY}/rr ${BINARY}/priority_rr ${RESOURCE}/tasks.txt
	${BINARY}/fcfs ${RESOURCE}/tasks.txt
	${BINARY}/sjf ${RESOURCE}/tasks.txt
	${BINARY}/priority ${RESOURCE}/tasks.txt
	${BINARY}/rr ${RESOURCE}/tasks.txt
	${BINARY}/priority_rr ${RESOURCE}/tasks.txt








