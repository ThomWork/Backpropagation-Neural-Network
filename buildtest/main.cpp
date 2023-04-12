#include <iostream>
#include <vector>
#include <string>


#include <assert.h>

#include "LoadData.cpp"
#include "BackpropNetwork.cpp"

// g++ main.cpp -o main.exe
// ./main.exe

// git init
// git add .
// git commit -m "first commit"
// git branch -M main
// git remote add origin git@github.com:"whatever-the-repository-is"
// git push -u origin main

// cmake .
// make

void networkSetup( BackpropNetwork& network );
void loadDataFromFile( std::vector<std::vector<float>>& data );

int main()
{
	BackpropNetwork myNetwork;
	networkSetup( myNetwork );
	
	std::vector<std::vector<float>> data;
	loadDataFromFile( data );
	
	std::vector<float> input = {0,0};
	myNetwork.feedForward( input );
	
	return 0;
}

void networkSetup( BackpropNetwork& network )
{
	std::vector<int> topography = {2,3,1};
	bool bias = true;
	std::string activation_function = "Sigmoid";
	std::string loss_function = "Half Squared";
	float learn_rate = 0.05;
	
	network.setTopography( topography, bias );
	network.setActivation( activation_function );
	network.setLoss( loss_function );
	network.setLearnRate( learn_rate );
}

void loadDataFromFile( std::vector<std::vector<float>>& data )
{
	std::string fileName = "buildtest/testdata.csv";	// Name of file
	char delimiter = ',';	// Delimiter used to seperate contents of file
	loadData( fileName, data, delimiter );	// Load the data from the file into vector
}
