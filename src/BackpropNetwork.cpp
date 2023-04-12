#include "BackpropNetwork.h"


BackpropNetwork::BackpropNetwork()
{
	
}

BackpropNetwork::~BackpropNetwork()
{
	
}

void BackpropNetwork::setTopography( std::vector<int>& topography, bool& bias )
{
	assert( topography.size() > 1 );	// Change to verify at some point(?)
	bias_in_network = bias;
	
	// Input and output nodes
	int input_nodes = topography.front();
	int output_nodes = topography.back();
	
	// Hidden layer nodes
	std::vector<int> hidden_layers = topography;
	hidden_layers.erase( hidden_layers.begin() );
	hidden_layers.pop_back();
	
	// Functions to create the layers
	createInputLayer( input_nodes );
	createHiddenLayers( hidden_layers );
	createOutputLayer( output_nodes );
	
	// Connect all the layers
	connectLayers();
	
	// Initialise errors vector
	for ( int i = 0; i < output_nodes; i++ )
	{
		networkErrors.push_back( 0 );
		networkErrorsDerivative.push_back( 0 );
	}
}

void BackpropNetwork::setActivation( const std::string& activFunction )
{
	for ( int i = 1; i < network.size(); i++ )
	{
		network[i].setLayerActivation( activFunction );
	}
}

void BackpropNetwork::setLoss( const std::string& lossFunction )
{
	loss = setLossFunction( lossFunction );
}

void BackpropNetwork::setLearnRate( float& rate )
{
	learn_rate = rate;
}

void BackpropNetwork::feedForward( std::vector<float>& inputVals )
{
	networkInput = inputVals;
	
	for ( int i = 0; i < networkInput.size(); i++ )
	{
		network[0].output[i] = inputVals[i];
	}
	
	for ( int i = 1; i < network.size(); i++ )
	{
		network[i].layerFeedForward();
	}
	
	networkOutput = network[ network.size() - 1 ].output;	// Last layer outputs are network outputs
	
	std::cout << "Fedforward" << std::endl;
}

void BackpropNetwork::backPropagation( std::vector<float>& target_vals )
{
	calculateErrors( target_vals );
	
	int i = network.size() - 1;
	
	network[i].layerBackPropagation( target_vals );
	
	while ( i > 0 )
	{
		
		
		
		i--;
	}
}

void BackpropNetwork::createInputLayer( int& nodes )
{
	createLayer( nodes, bias_in_network );
	
	std::string layer_name = "Input";
	nameLayer( layer_name );
}

void BackpropNetwork::createHiddenLayers( std::vector<int>& layers )
{
	int hidden_layers = layers.size();
	
	for (int i = 0; i < hidden_layers; i++ )
	{
		int nodes = layers[i];
		createLayer( nodes, bias_in_network );
		
		std::string layer_name = "Hidden";
		nameLayer( layer_name );
	}
	
}

void BackpropNetwork::createOutputLayer( int& nodes )
{
	bool bias_in_output = false;
	createLayer( nodes, bias_in_output );
	
	std::string layer_name = "Output";
	nameLayer( layer_name );
}

void BackpropNetwork::createLayer( int& nodes, bool& bias )
{
	Layer layer( nodes, bias );
	network.push_back( layer );
}

void BackpropNetwork::nameLayer( const std::string& layer_name )
{
	network.back().setLayerName( layer_name );
}

void BackpropNetwork::connectLayers()
{
	for ( int i = 1; i < network.size(); i++ )
	{
		network[i].connectingLayer( network[i-1].output );	// Connect to output values of previous layer
	}
	
	std::cout << "Connected Layers" << std::endl;
}

void BackpropNetwork::calculateErrors( std::vector<float>& target_vals )
{
	for ( int i = 0; i < networkErrors.size(); i++ )
	{
		networkErrors[i] = lossError( loss, networkOutput[i], target_vals[i] );
		networkErrorsDerivative[i] = lossDerivative( loss, networkOutput[i], target_vals[i] );
	}
}

