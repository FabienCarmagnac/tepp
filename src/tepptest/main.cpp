#include <UnitTest++/UnitTest++.h>

#include <iostream>

// run all tests
int main(int argc, char **argv)
{
	std::cout<<"===BEGIN==="<< std::endl;
	int ret=UnitTest::RunAllTests();
	std::cout<<"===END==="<< std::endl;
	return ret;
}
