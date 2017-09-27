bool search(int value){
	for (int i = 0; i < ARRAY_SIZE; i++){
		if (array[i] == value){
			for (int index = i; index < ARRAY_SIZE; index++){
				array[i] = array[i + 1];
				array[ARRAY_SIZE - 1] = 0;
			}
			return true;
		}
	}
	return false;
}



