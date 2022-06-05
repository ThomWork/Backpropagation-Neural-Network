#include "Node.h"

Node::Node()
{
	
}

Node::~Node()
{
	
}

void Node::initialise()
{
	weighted_sum = 0;
	output = 0;
}

void Node::setNodeActivation( const std::string& activ_function )
{
	activation_function = activ_function;
	activ = setActivationFunction ( activation_function );
}

void Node::assignInputNode( float& input_node )
{
	inputNodes.push_back( &input_node );
	
	assignConnectionWeight();
}

void Node::assignConnectionWeight()
{
	Connection temp_connection;
	weights.push_back( temp_connection );
}

void Node::computeOutput()
{
	assert( inputNodes.size() == weights.size() );	// Each input node has a weight
	
	calculateWeightedSum();
	calculateActivation();
}

void Node::calculateWeightedSum()
{
	weighted_sum = 0;
	float temp_output;	// temp variable
	
	for ( int i = 0; i < inputNodes.size(); i++ )
	{
		temp_output = *inputNodes[i];
		weighted_sum += weights[i].getWeightedValue( temp_output );
	}
}

void Node::calculateActivation()
{
	output = activationFunction( activ , weighted_sum );
}

float Node::getOutput()
{
	return output;
}


