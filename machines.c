#include "eclab.h"

// initializes a machine and returns the machine
machine_t init(machine_t* machine, char* _name, unsigned char _addr[4]) {
	memcpy(machine->addr, _addr, 4);
	strcpy(machine->name, _name);
	return *machine;
}

// checks if two machines are on the same local network,
// and also that their aliases aren't the same
boolean_t same_network(machine_t m1, machine_t m2) {
	return m1.addr[0] == m2.addr[0] && strcmp(m1.name, m2.name);
}

// Prints the contents of a machine to stdout
void display(machine_t machine) {
	printf("Machine %s has address %hhu.%hhu.%hhu.%hhu\n",
		machine.name, machine.addr[0], machine.addr[1], machine.addr[2], machine.addr[3]);
}
