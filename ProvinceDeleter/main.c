#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


void main() {
	FILE* definitionFile = fopen("definition.csv", "r");
	if (definitionFile == NULL) {
		printf("Error opening definition.csv");
		char fucc = 0;
		fucc = getc(&fucc);
		return;
	}
	FILE* definitionOutput = fopen("definitionNew.csv", "w");
	


	printf("Glorwyn's Province Deleter.\nEnter ID of province to delete:   ");
	int provinceIDToDelete;
	scanf("%d", &provinceIDToDelete);
	char currentLine[100];
	int id = 0;
	int searching = 1;
	while (1) {	
		if (fgets(currentLine, 99, definitionFile) == NULL) {
			break;
		}

		if (searching) {
			int c = 0;
			char currentID[10];
			while (1) {
				if (currentLine[c] != ';') {
					currentID[c] = currentLine[c];
					c++;
				}else {
					currentID[c] = '\0';
					break;
				}				
			}

			if (atoi(currentID) == provinceIDToDelete) {
				printf("\nFound province to remove.\n");
				searching = 0;
				continue;
			}else {
				fputs(currentLine, definitionOutput);
			}
		}
		else {
			int c = 0;
			char currentID[10];
			while (1) {
				if (currentLine[c] != ';') {
					currentID[c] = currentLine[c];
					c++;
				}else {
					currentID[c] = '\0';
					break;
				}
			}
			int newID = atoi(currentID);
			int ImLazyFlag = 0;
			if (newID % 10 == 0 && currentID[0] == '1') {
				ImLazyFlag = 1;
			}
			newID--;
			_itoa(newID, &currentID, 10);
			
			c = 0;
			while (1) {
				if (currentID[c] != '\0') {
					currentLine[c] = currentID[c];
				}else {
					if (ImLazyFlag) {
						while (currentLine[c] != '\0') {
							currentLine[c] = currentLine[c + 1];
							c++;
						}
					}
					break;
				}
				c++;
			}
			fputs(currentLine, definitionOutput);
		}
		

	}
}