#include "Node.cpp"

class Layer
{
public:
	Layer( int& nodes, bool& is_there_bias );
	virtual ~Layer();
	void setLayerName( const std::string& layer_name );
	void setLayerActivation( const std::string& activFunction );
	
	void connectingLayer( std::vector<float>& prevOutputs );
	
	std::vector<float> output = {};//new std::vector<float>;
	
private:
	std::vector<Node> layer;
	bool bias_in_layer = false;	// default value is false
	
	void createNodes( int& nodes );
	void createBias();
	void initialiseOutputVector();
	
	std::string layerName = "Default";	// default name is Default
};
