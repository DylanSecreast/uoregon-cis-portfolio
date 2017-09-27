const int SIZE = 50;
int nElems;
int arrayA[SIZE];

void addElement(int *arrayA, int element){
	if (nElems == SIZE){
		const int NEW_SIZE = 100;
		int arrayB[NEW_SIZE];
		
		for (int index = 0; index < SIZE; index++){
			arrayA[index] = arrayB[index];
		}
	}
	
	int i = SIZE - 1;
	for (; i > 0 && arrayA[i - 1] > element; --i){
		arrayA[i] = arrayA[i - 1];
	}
	arrayA[i]= element;
	nElems++;
}