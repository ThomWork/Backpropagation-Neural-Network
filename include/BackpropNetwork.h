#include <math.h>
#include "Losses.cpp"
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
	void backPropagation( std::vector<float>& target_vals );
	
	
private:
	std::vector<Layer> network;
	
	std::vector<float> networkInput;
	std::vector<float> networkOutput;
	std::vector<float> networkErrors;
	std::vector<float> networkErrorsDerivative;
	
	bool bias_in_network = true;
	int loss = 0;	// Default loss function
	float learn_rate = 0.05;
	
	void createInputLayer( int& nodes );
	void createHiddenLayers( std::vector<int>& layers );
	void createOutputLayer( int& nodes );
	void createLayer( int& nodes, bool& is_there_bias );
	void nameLayer( const std::string& layer_name );
	void connectLayers();
	void calculateErrors( std::vector<float>& target_vals );
};
