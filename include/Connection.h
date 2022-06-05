
class Connection
{
public:
	Connection();
	virtual ~Connection();
	float getWeightedValue( float& _input );	// The output value of a node is weighted
	float getWeight();
	
private:
	float input;
	float output = 0;
	float weight = 0;
	float delta_weight = 0;
};
