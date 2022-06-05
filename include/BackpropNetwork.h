#include <math.h>
#include "Layer.cpp"


class BackpropNetwork
{
	
public:
	BackpropNetwork();
	virtual ~BackpropNetwork();
	
	void setTopography( std::vector<int>& topography, bool& bias );
	void setActivation( const std::string& activ_function );
	void setLoss( const std::string& loss_function );
	void setLearnRate( float& rate );
	void feedForward( std::vector<float>& input_vals );
	
	
private:
	std::vector<Layer> network;
	bool bias_in_network = true;
	float learn_rate = 0.05;
	
	void createInputLayer( int& nodes );
	void createHiddenLayers( std::vector<int>& layers );
	void createOutputLayer( int& nodes );
	void createLayer( int& nodes, bool& is_there_bias );
	void nameLayer( const std::string& layer_name );
	void connectLayers();
};
