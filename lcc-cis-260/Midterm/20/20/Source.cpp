bool find(int x, node* next){
	if (next == NULL){
		return false;
	}
	else if (next->value == x){
		return true;
	}
	else{
		find(x, next->next);
	}
}