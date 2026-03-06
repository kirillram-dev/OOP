#include <iostream>
#include "translator_utils.h"

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (!CheckArgument(argc))
	{
		return 1;
	}

	std::string fileName;
	Dictionary dictionary;

	if (argc == 2)
	{
		fileName = argv[1];
		std::ifstream input(fileName);
		if (input.is_open())
		{
			ReadDictonairyFromFile(input, dictionary);
			input.close();
		}
	}
	else
	{
		fileName = "Dictionary.txt";
	}

	bool isDictionaryChange = false;
	Translation(dictionary, isDictionaryChange);

	if (isDictionaryChange)
	{
		std::ofstream output(fileName);
		CompleteTranslsation(output, dictionary);
	}

	return 0;
}
