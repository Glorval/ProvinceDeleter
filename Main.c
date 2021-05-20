#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char breaker[] = ";";

	printf("Thank you for using Glorwyn's Province Deleter.\n:3\nRemember, put in IDs in highest to lowest.\n\n");
	int provinceIDToDelete;
	while (1) {
		FILE* definitionFile = fopen("definition.csv", "r");
		if (definitionFile == NULL) {
			printf("Error opening definition.csv");
			char fucc = 0;
			fucc = getc(&fucc);
			return;
		}
		FILE* definitionOutput = fopen("definition.csv~", "w");


		printf("Enter province ID to remove: ");
		scanf("%d", &provinceIDToDelete);
		if (provinceIDToDelete < 0) {
			printf("Done. Thank you. Let me know of any problems and have a nice day.");
			break;
		}
		char currentLine[100];
		int searching = 1;
		int currentOffset = 1;
		while (1) {
			if (fgets(currentLine, 99, definitionFile) == NULL) {
				break;
			}

			if (searching) {
				int c = 0;
				char* currentID;
				currentID = strtok(currentLine, breaker);
				if (atoi(currentID) == provinceIDToDelete) {
					printf("Found province to remove.\n\n");
					searching = 0;
					continue;
				}
				else {
					fputs(currentLine, definitionOutput);
					fputc(';', definitionOutput);
					fputs(strtok(NULL, ""), definitionOutput);
				}
			}
			else {
				int c = 0;
				char* currentID;
				currentID = strtok(currentLine, ";");
				int newID = atoi(currentID);
				newID = newID - currentOffset;
				_itoa(newID, currentID, 10);
				fputs(currentID, definitionOutput);
				fputc(';', definitionOutput);
				fputs(strtok(NULL, ""), definitionOutput);
			}

		}
		fclose(definitionFile);
		fclose(definitionOutput);
		definitionFile = fopen("definition.csv~", "r");
		definitionOutput = fopen("definition.csv", "w");
		while (1) {
			char line[100];
			if (fgets(&line, 99, definitionFile) == NULL) {
				break;
			}
			fputs(line, definitionOutput);
		}
		fclose(definitionFile);
		fclose(definitionOutput);

	}
	int errorRemoving = remove("definition.csv~");
	if (errorRemoving) {
		printf("\n\nRemove condition: %d\n", errorRemoving);
		printf("Error for removal of file: %s\n", strerror(errno));
	}


	getche();

}