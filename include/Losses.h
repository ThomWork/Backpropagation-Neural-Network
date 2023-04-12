
int setLossFunction( const std::string& lossFunction )
{
	if( lossFunction == "Half Squared" )
	{
		std::cout << "Loss function chosen is " << lossFunction << std::endl;
		return 0;
	}
	else if( lossFunction == "Wish" )
	{
		std::cout << "Loss function chosen is " << lossFunction << std::endl;
		return 1;
	}
	else if( lossFunction == "Linear" )
	{
		std::cout << "Loss function chosen is " << lossFunction << std::endl;
		return 2;
	}
	else
	{
		std::cout << lossFunction << " is not an available loss function" << std::endl;
		return -1;
	}
}

float lossError( const int& loss, const float& result, const float& targetVal )
{
	switch( loss )
	{
		case 0:
			return 0.5*(targetVal-result)*(targetVal-result);
		default:
			std::cout << "Please choose available loss function" << std::endl;
			return 0;
	}
}

float lossDerivative( const int& loss, const float& result, const float& targetVal )
{
	switch( loss )
	{
		case 0:
			return (result - targetVal);
		default:
			std::cout << "Please choose available loss function derivative" << std::endl;
			return 0;
	}
}
