#include "eclab.h"

int main(void) {
	// Construct and fill array by reading from a file
	machine_t machines[NUM_MACHINES];
	FILE* in = fopen("inpa.txt", "r");
	if(in == NULL) {
		printf("ERROR | Could not open file. Exiting...\n");
		exit(1);
	}
	read_machines(in, machines);
	boolean_t used[NUM_MACHINES];
	for(int i = 0; i < NUM_MACHINES; i++) {
		used[i] = false;
	}
	// compare two arrays and check to see if they are on the same network
	printf("Local Pairs:\n");
	for(int i = 0; i < NUM_MACHINES; i++) {
		for(int j = 0; j < NUM_MACHINES; j++) {
			if(same_network(machines[i], machines[j])) {
				// set addr so that each combo only gets printed once
				if(!(used[i] || used[j])) {
					printf("Machines %s and %s are on the same network.\n",
					machines[i].name, machines[j].name);
					used[i] = true;
				}
			}
		}
	}
	printf("\nList of all addresses:\n");
	for(int i = 0; i < NUM_MACHINES; i++)
		(strcmp(machines[i].name, "NULL")) ? display(machines[i]) : 0;
	return 0;
}
