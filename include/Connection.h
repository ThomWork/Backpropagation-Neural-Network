
class Connection
{
public:
	Connection();
	virtual ~Connection();
	void initialiseWeight();
	float getWeightedValue( float& _input );	// The output value of a node is weighted
	float getWeight();
	
private:
	float input = 0;
	float output = 0;
	float weight = 0;
	float delta_weight = 0;
};
