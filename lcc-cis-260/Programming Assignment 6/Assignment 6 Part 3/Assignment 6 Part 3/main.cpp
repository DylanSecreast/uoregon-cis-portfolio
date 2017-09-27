#include "priorityQ.cpp"

int main(int argc, char * argv[])
{
	PriorityQ thePQ(5);

	thePQ.insert(30);
	thePQ.insert(50);
	thePQ.insert(10);
	thePQ.insert(40);
	thePQ.insert(20);

	while (!thePQ.isEmpty())
		cout << thePQ.remove() << " ";

	cout << endl;
}
