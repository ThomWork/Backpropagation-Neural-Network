
int setActivationFunction( const std::string& activFunction )
{
	if( activFunction == "Linear" )
	{
		std::cout << "Activation function chosen is " << activFunction << std::endl;
		return 0;
	}
	else if( activFunction == "Wish" )
	{
		std::cout << "Activation function chosen is " << activFunction << std::endl;
		return 1;
	}
	else if( activFunction == "Sigmoid" )
	{
		std::cout << "Activation function chosen is " << activFunction << std::endl;
		
		return 2;
	}
	else if( activFunction == "ReLU" )
	{
		std::cout << "Activation function chosen is " << activFunction << std::endl;
		return 3;
	}
	else
	{
		std::cout << activFunction << " is not an available activation function" << std::endl;
		return -1;
	}
}

float activationFunction( const int& function, float& value )
{
	switch( function )
	{
		case 0:
			return value;
		case 1:
			return value*(1.0/(1.0 + exp(-1.0*value)));
		case 2:
			return 1.0/(1.0 + exp(-1.0*value));
		case 3:
			return ( 0 < value ) ? value:0;
		default:
			std::cout << function << " is not an available function" << std::endl;
			return 0;
	}
}

float activFuncDerivative( const int& function, float& value )
{
	switch( function )
	{
		case 0:
			return 1.0;
		case 1:
			return (1.0+exp(-1.0*value)+value*exp(-1.0*value))/pow(1.0+exp(-1.0*value),2);
		case 2:
			return activationFunction(function,value)*(1.0 - activationFunction(function,value));
		case 3:
			return ( 0 < value ) ? 1:0;
		default:
			std::cout << function << " is not an available function" << std::endl;
			return 0;
	}
}
