#include "main.h"

void clearStack(std::stack<int>&);

int main()
{
	using namespace std;
	
	
	regex file_name_ptrn = regex("in([0-9]+)\.txt");
	
	string usr_file_path;
	int usr_file_number;
	
	// to hold a collection of all possible input file name numbers
	vector<int> f_name;
	smatch match;
	
	// stack to hold input
	stack<int> s1, s2, s3;
	
	// start engagement
	cout << "Please enter path to input files:" << endl;
	while(true)
	{
		
		getline(cin, usr_file_path);
		
		if (!fs::exists(usr_file_path))
		{
			cout << "\nGiven path does not exist. Please try again:" << endl;
		}
		
		else
		{
			
			for (const auto & entry : fs::directory_iterator(usr_file_path)) {
	        	//cout << entry.path().filename() << endl;
	        	
	        	string curr_file_name = entry.path().filename().string();
				smatch match;
				
				if (regex_search(curr_file_name, match, file_name_ptrn))
				{
					f_name.push_back(stoi(match[1]));
				}
			}
			
			if (f_name.empty())
			{
				cout << "\nInput files could not be discovered at that location. Please try again:" << endl;
			}
		
			else
			{
				break;
			}
			
		}
	
		
	}
		 
	cout << "\nFiles discovered:\n{";
	for(size_t i = 0; i < f_name.size()-1; ++i)
	{
		cout << f_name[i]<< ", ";
	}
	cout << f_name[f_name.size()-1] << '}' << endl;
	
	while(true)
	{
		
		cout << "\nEnter the number of the file you wish to open, or enter -1 to quit: ";
		cin >> usr_file_number;
		
		// exit condition
		if (usr_file_number == -1)
		{
			break;
		}
		
		else if (find(f_name.begin(), f_name.end(), usr_file_number) != f_name.end())
		{
			// clear previous input/output/buffer, if any
			clearStack(s1);
			clearStack(s2);
			clearStack(s3);
			
			// pass selected file path
			s1 = StackParse::NLSV2Stack(usr_file_path, (string)FILEPREFIX + to_string(usr_file_number) + '.' + (string)FILETYPE);
			
			while (s1.size() > 0)
			{
				while(!s2.empty() && s1.top() > s2.top())
				{
					s3.push(s2.top());
					s2.pop();
				}
				
				// push top of s1 to s2
				s2.push(s1.top());
				s1.pop();
				
				// replace what was pushed to s3 back to s2
				while(s3.size() > 0)
				{
					s2.push(s3.top());
					s3.pop();
				}
			}
			
			cout << "Sort result: " << StackParse::Stack2CSV(s2) << endl;
		}
		
		// invalid condition
		else
		{
			cout << "File specified is unknown. Please try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
	
	return 0;
}

void clearStack(std::stack<int> &s) {
	while (!s.empty())
	{
		s.pop();
	}
}