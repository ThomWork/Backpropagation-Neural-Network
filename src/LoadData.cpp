#include <fstream>	// Used for reading to and from a file
#include <sstream>	// Used to convert between string and number


void loadData ( const std::string& fileName, std::vector<std::vector<float>>& data, const char& delimiter )
{
	std::cout << "Loading data" << std::endl;
	std::ifstream dataFile( fileName ); // Open the file
	
	if( !dataFile.is_open() ) // Check the file opened
	{
		std::cout << "Error opening file" << std::endl;
	}
	else
	{
		std::string line;  // Used to hold the line of the csv file
		//int lineCount = 1;
		while( dataFile.good() && getline( dataFile,line ) ) // While the file is good and we're getting lines
		{
			//std::cout << "Line " << lineCount << std::endl;
			std::istringstream lineStream( line ); // Load the line into a stringstream so we can separate at commas
			std::vector <float> dummyLine; // Dummy that will store line of numbers after conversion
			
			std::string dummyStr; // Numbers (as strings) we're interested in
			float dummyNum = 0; // Dummy where the string will be converted to a number
			
			while ( getline( lineStream, dummyStr, delimiter ) )
			{
				std::stringstream convertStream; // Provides conversion of string to double
				convertStream << dummyStr;  // Load string into stream
				convertStream >> dummyNum;  // Take it out as a number

				dummyLine.push_back( dummyNum ); // Put the number into a vector array
			}
			data.push_back( dummyLine ); // Put the array of numbers back into another vector array
			dummyLine.clear();
			//lineCount++;
		}
		dataFile.close();
		std::cout << "Loaded data" << std::endl;
	}
}
