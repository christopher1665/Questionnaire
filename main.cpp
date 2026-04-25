#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    vector<string> stringList;
    vector<string> stringInput;
    string List, Input;

    ifstream myfile("Questions.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, List))
        {
            stringList.push_back(List);
        }
        myfile.close();
    }
    else 
    {
        cerr << "Unable to open Questions.txt" << endl;
        return 1;
    }

    for (size_t i = 0; i < stringList.size(); i++)
    {
        cout << "Question " << (i + 1) << ": " << stringList[i] << "?" << endl;
        
        if (getline(cin, Input)) 
        {
            stringInput.push_back(Input);
        }
    }

    cout << "\n--- Summary of Responses ---" << endl;
    for (size_t i = 0; i < stringInput.size(); i++)
    {
        cout << "Response for question " << (i + 1) << ": " << stringInput[i] << endl;
    }
    return 0;
}
