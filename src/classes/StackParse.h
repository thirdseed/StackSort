#include <fstream>
#include <stack>
#include <sstream>
#include <string>

class StackParse
{
	public:
		static std::stack<int> NLSV2Stack(std::string&, std::string);
		static std::string Stack2CSV(std::stack<int>);
		
	private:
		StackParse();
};

