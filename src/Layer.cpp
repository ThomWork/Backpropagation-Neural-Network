#include "Layer.h"


Layer::Layer( int& nodes, bool& is_there_bias )
{
	createNodes( nodes );
	
	if ( is_there_bias )
	{
		bias_in_layer = true;
		createBias();
	}
	
	initialiseOutputVector();
}

Layer::~Layer()
{
	
}

void Layer::setLayerName( const std::string& layer_name )
{
	layerName = layer_name;
}

void Layer::setLayerActivation( const std::string& activFunction )
{
	int limit = layer.size() - 1*( bias_in_layer );
	
	for ( int i = 0; i < limit; i++ )
	{
		layer[i].setNodeActivation( activFunction );
	}
}

void Layer::connectingLayer( std::vector<float>& prevOutputs )
{
	// Code here to connect this layer to previous one
	int limit = layer.size() - 1*( bias_in_layer );
	
	for ( int i = 0; i < limit; i++ )
	{
		for ( int j = 0; j < prevOutputs.size(); j++ )
		{
			layer[i].assignInputNode( prevOutputs[j] );
		}
	}
}

void Layer::createNodes( int& nodes )
{
	for ( int i = 0; i < nodes; i++ )
	{
		Node node;
		node.initialise();
		layer.push_back( node );
	}
	
}

void Layer::createBias()
{
	Node node;
	layer.push_back( node );
}

void Layer::initialiseOutputVector()
{
	for ( int i = 0; i < layer.size(); i++ )
	{
		output.push_back( layer[i].getOutput() );
	}
}
