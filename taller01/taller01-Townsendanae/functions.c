/*
	Descripcion: functions file that contains the functions for counting words
	Last Modify: 2020-06-15
	Modify by: @rafariva
*/

#include "functions.h"

int count_words(FILE *file){
	int count = -1;
	/* TODO: add code for counting words */
	/* TIP: use function fscanf for read file/words */
	int carac = 0;
	char word[MAXWORD];

	while (carac >= 0){
		carac = fscanf(file, "%s", word );
		count++;
	}

	return count;
}
