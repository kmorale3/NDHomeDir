//Katie Morales
//4/6/21
//statesmain.c
//this is the main driver for the states program
#include "statesfunc.h"


int main(int argc, char *argv[]) {
	FILE *fp;
	char fileName[30];
	if (argc==1) {
		printf("Please enter a file name; ");
		scanf("%s", fileName);
		fp=fopen(fileName, "r");
	} else if (argc==2) {
		fp=fopen(argv[1], "r");
	} else {
		printf("Error: too many inputs!\n");
		return 0;
	}

	State states_arr[statesNum]; 

	int count = readstates(fp, states_arr);
	State lower_states_arr[count];
	lowercaseState(states_arr, lower_states_arr, count);//same as the other array but lowercase for all strings
	int choice;

	while (1) {
		printf("\n");
		choice=takeInput();
		printf("\n");
		switch (choice) {//switch statement to enter correct function
			case 1:
				listAllData(states_arr, count);
				break;
			case 2:  
				infoFromAbb(states_arr, lower_states_arr, count);	
				break; 
			case 3:
				capital(states_arr, lower_states_arr, count);
				break;
			case 4:
				stateYear(states_arr, count);
				break;
			case 5: 
				chronologicalOrder(states_arr, count);
				break;
			case 6:
				return 0;
			default:
				printf("Error: unacceptable input");
				break;
		}
	}
}
