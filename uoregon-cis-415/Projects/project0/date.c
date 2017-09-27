/* Dylan Secreast
 * dsecrea2@uoregon.edu
 * CIS 415 Project 0
 * This is my own work except for the following:
 * - strtok() functions in *date_create() modeled
 *	after gist.github.com/efeciftci/9120921
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"


struct date {
	int day;
	int month;
	int year;
};


Date *date_create(char *datestr) {

	Date *newStruct = (Date *) malloc(sizeof(Date));
	char *datestrCopy = strdup(datestr);

	sscanf(strtok(datestrCopy, "/"), "%i", &newStruct->day);
	sscanf(strtok(NULL, "/"), "%i", &newStruct->month);
	sscanf(strtok(NULL, "/"), "%i", &newStruct->year);

	free(datestrCopy);
	return newStruct;

} // end *date_create


Date *date_duplicate(Date *d) {

	Date *duplicate = (Date *)malloc(sizeof(*d));
	memcpy(duplicate, d, sizeof(*duplicate));
	return duplicate;

} // end *date_duplicate


int date_compare(Date *date1, Date *date2) {

	if (date1->year < date2->year) {
		return -1;
	} else if (date1->year > date2->year) {
		return 1;
	} else if (date1->year == date2->year) {
		if (date1->month < date2->month) {
			return 1;
		} else if (date1->month > date2->month) {
			return -1;
		} else if (date1->month == date2->month) {
			if (date1->day < date2->day) {
				return 1;
			} else if (date1->day > date2->day) {
				return -1;
			} else if (date1->day == date2->day) {
				return 0;
			}
		}
	}

	int invalidCompare = NULL;
	return invalidCompare;

} // end date_compare


void date_destroy(Date *d) {

	if (d != NULL) {
		free(d);
	}

} // end date_destroy
