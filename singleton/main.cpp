#include <iostream>

using namespace std;

// only one instance of class
// one global point of access
// no access to creation or deletion of instance
// just-in-time realization
// thread-safe access as race condition during initialization can lead to multiple instances
//
// cons: 
// poor design as data is being stored globally


class Singleton
{
	private:
	int data; // demo member

	protected:
	~Singleton() { }
	Singleton() { data = 2015; }
	Singleton(const Singleton& s) { data = s.data; }
	Singleton& operator=(const Singleton& s) { data = s.data; }

	public:
	static Singleton& getInstance();
	int getData() { return data; } // demo method
	void setData(int d) { data = d; } //demo mehthod 
};

Singleton& Singleton::getInstance()
{
	// acquire mutex lock
	static int callCount = 1; // demo
	cout << "getInstance() : callCount = " << callCount++ << '\n'; // demo
	static Singleton instance;
	return instance;
	// release mutex lock when scope ends
}

int main()
{
	Singleton &obj1 = Singleton::getInstance();
	Singleton *pobj1 = &obj1;

	cout << obj1.getData() << '\n';
	cout << pobj1->getData() << '\n';

	return 0;
}
