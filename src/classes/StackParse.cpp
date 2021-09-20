#include "StackParse.h"

std::stack<int> StackParse::NLSV2Stack(std::string file_path)
{
	using namespace std;
	
	ifstream file(file_path);
	
	stack<int> out;
	string line;
		
	while(getline(file, line))
	{
		istringstream iss(line);
		int n;
			
	   	while (iss >> n) out.push(n);
	}
		
	return out;
}
	
	/* Stack of ints to string CSV */
std::string StackParse::Stack2CSV(std::stack<int> s)
{
	using namespace std;
	
	string out = "";
	
	// write all but last value
	while(s.size() > 1)
	{
		out += to_string(s.top()) + ", ";
		s.pop();
	}
	
	// write last value without comma
	out += to_string(s.top());
	
	return out;
}
