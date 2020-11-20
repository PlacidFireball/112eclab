#include "eclab.h"

void read_machines(FILE* in, machine_t machines[NUM_MACHINES]) {
	// buffer string and a pointer for strtok
	char buff[100], *tok;
	// temporary address array
	unsigned char addr[4];
	int i = 0;
	while(fgets(buff, 100, in) != NULL) {
		tok = strtok(buff, " ");
		// read the address in
		sscanf(tok, "%hhu.%hhu.%hhu.%hhu", &addr[0], &addr[1], &addr[2], &addr[3]);
		tok = strtok(NULL, "\n"); 	// grab the name
		init(&machines[i++], tok, addr);// initialize a machine from the data read in
	}
	// set the rest of the machines to be default values
	unsigned char default_addr[4] = { 0, 0, 0, 0 };
	for (int j = i; j < NUM_MACHINES; j++) {
		init(&machines[j], "NULL", default_addr);
	}

}

