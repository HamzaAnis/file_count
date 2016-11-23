#include<iostream>
#include<fstream>
#include <string>
#include <string.h>

using namespace std;

void
pause_215(bool);
int
main()
{

	ifstream myReadFile;
	char fileName[256];
	do
	{
		cout << "Enter filename: (enter Q or q to quit the program)\n";
		cin >> fileName;
		if (strcmp(fileName, "q"))
		{

			myReadFile.open(fileName);
			if (myReadFile.is_open())
			{
				string buffer;
				int lineCount = 0;
				int wordCount = 0;
				int charCount = 0;

				//outputting file
				while (!myReadFile.eof())
				{
					buffer = "";
					getline(myReadFile, buffer);
					cout << "Line " << lineCount + 1 << ": " << buffer << endl;
					lineCount++;

					//counting words in a line and counting non whitespace character
					//the line is read in buffer string now we are counting the words in the string
					for (int j = 0; j < buffer.length(); j++)
					{
						if (buffer[j] == ' ') //if the space is detected then there is new word
							wordCount++;
						else if (buffer[j] != ' ') //if it is not then it is the non white space charat
							charCount++;
					}
					wordCount++; //this count id for the first word of the new line


				}

				//displaying output
				cout << "The file contains\n";
				cout << charCount << " non-whitespace characters,\n";
				cout << wordCount << " words," << endl;
				cout << lineCount << " lines." << endl;
			}
			else
				cout << "The file does not exist, please try again…\n";
			myReadFile.close();
		}
	} while (strcmp(fileName, "q"));
	pause_215(true);
	return 0;
}

void
pause_215(bool have_newline)
{
	if (have_newline)
	{
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}

