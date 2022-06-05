#include "Connection.h"

Connection::Connection()
{
	
}

Connection::~Connection()
{
	
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
