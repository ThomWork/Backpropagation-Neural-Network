#include "Activations.h"
#include "Connection.cpp"

class Node
{
public:
	Node();
	virtual ~Node();
	void initialise();
	void setNodeActivation( const std::string& activ_function );
	void assignInputNode( float& input_node );
	void nodeFeedForward();
	float getOutput();
	
	
	
private:
	float weighted_sum = 1;
	float output = 1;
	
	std::string activation_function = "Linear";	// default is linear
	int activ = 0;	// default number for linear
	
	void assignConnectionWeight();
	void calculateWeightedSum();
	void calculateActivation();
	
	std::vector<float*> inputNodes = {};	// These are the inputs that will be feeding in to this node
	std::vector<Connection> weights = {};	// These are weights of the nodes with inputs to this node
	
};
