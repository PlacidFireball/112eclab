#ifndef ECLAB
#define ECLAB

#define STR_LEN 10	// default string length
#define NUM_MACHINES 10 // default number of machines

#include <stdio.h>	// I/O
#include <string.h>	// string functions
#include <stdlib.h>	// for cool standard library things

// boolean type
typedef enum { false, true } boolean_t;

// machine type
typedef struct {
	char name[STR_LEN];
	unsigned char addr[4];
} machine_t;

// reads in machines from a file and stores them in an array of size NUM_MACHINES
void 		read_machines(FILE* in, machine_t machines[NUM_MACHINES]);
// initializies a machine
machine_t 	init(machine_t* machine, char* _name, unsigned char _addr[4]);
// checks if two machines are on the same network
boolean_t	same_network(machine_t m1, machine_t m2);
// prints the contents of a machine to stdout
void 		display(machine_t machine);

#endif
