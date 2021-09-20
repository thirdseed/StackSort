#include "main.h"

int main()
{
	using namespace std;
	
	int usr_input;
	
	// create collection of all possible input file name numbers
	array<int, KNOWN_SETS> f_name;
	iota(f_name.begin(), f_name.end(), 0);
	
	// stacks to hold input/output/buffer
	stack<int> s1, s2, s3;
	
	// start engagement
	cout << "Known files:\n{";
	for(size_t i = 0; i < f_name.size()-1; ++i)
	{
		cout << f_name[i]<< ", ";
	}
	cout << f_name[f_name.size()-1] << "}\n";
	
	while(true)
	{
		
		cout << "\nEnter the number of the file you wish to open, or enter -1 to quit: ";
		cin >> usr_input;
		
		// exit condition
		if (usr_input == -1)
		{
			break;
		}
		
		else if (find(f_name.begin(), f_name.end(), usr_input) != f_name.end())
		{
			// pass selected file path
			s1 = StackParse::NLSV2Stack("input/" + (string)FILEPREFIX + to_string(usr_input) + ".txt");
			
			/*** do sorting work here ***/
			
			// uncomment when sorting algorithm is done
			//cout << "Sort result: " << StackParse::Stack2CSV(s2) << "\n";
		}
		
		// invalid condition
		else
		{
			cout << "File specified is unknown. Please try again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
	
	return 0;
}
