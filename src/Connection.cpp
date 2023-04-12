#include <time.h>
#include <random>
#include "Connection.h"

Connection::Connection()
{
	initialiseWeight();
}

Connection::~Connection()
{
	
}

void Connection::initialiseWeight()
{
	time_t seconds = time(NULL);
	
	std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator( rd() ); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> distribution( -5.0f , 5.0f );
    
    weight = distribution( generator );
	std::cout << "Created weight" << std::endl;
}

float Connection::getWeightedValue( float& _input )
{
	input = _input;
	output = input*weight;
	
	return output;
}

float Connection::getWeight()
{
	return weight;
}
