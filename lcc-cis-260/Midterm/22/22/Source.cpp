void push(int n){
	array[++top] = n;
}

int pop(){
	return array[top--];
}