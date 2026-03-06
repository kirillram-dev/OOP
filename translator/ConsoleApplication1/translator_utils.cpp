#include "translator_utils.h"

void AddWordToDictionary(const std::string& word, const std::string& translationWord, Dictionary& dictionary, bool& isDictionaryChange)
{
	dictionary.insert({ word, translationWord });
	dictionary.insert({ translationWord, word });
	isDictionaryChange = true;
}

std::vector<std::string> FindWornInDictionary(const std::string& word, Dictionary& dictionary)
{
	auto translations = dictionary.equal_range(word);
	std::vector<std::string> values;

	for (auto it = translations.first; it != translations.second; ++it)
	{
		values.push_back(it->second);
	}

	return values;
}

void AddNewWord(const std::string& word, Dictionary& dictionary, bool& isDictionaryChange)
{
	std::cout << "Unknown word \"" << word << "\". Введите перевод или пустую строку для отказа." << std::endl;
	std::cout << ">";
	std::string translation;
	getline(std::cin, translation);
	if (!translation.empty())
	{
		AddWordToDictionary(ToLowerCase(word), ToLowerCase(translation), dictionary, isDictionaryChange);
		std::cout << "Word \"" + word + "\" сохранено в словаре как \"" + translation + "\"." << std::endl;
	}
	else
	{
		std::cout << "Word \"" + word + "\" проигнорировано." << std::endl;
	}
}

void HandleNewWord(const std::string& word, Dictionary& dictionary, bool& isDictionaryChange)
{
	auto foundWords = FindWornInDictionary(word, dictionary);
	if (foundWords.empty())
	{
		AddNewWord(word, dictionary, isDictionaryChange);
	}
	else
	{
		for (size_t i = 0; i < foundWords.size(); i++)
		{
			std::cout << foundWords[i] << " ";
		}
		std::cout << std::endl;
	}
}

void SaveDicitonaryToFile(std::ofstream& output, const Dictionary& dictionary)
{
	for (const auto& pair : dictionary)
	{
		output << pair.first << std::endl
			   << pair.second << std::endl;
	}
}

void CompleteTranslsation(std::ofstream& output, const Dictionary& dictionary)
{
	char ch;
	std::cout << "В словарь были внесены изменения. Введиет Y или y для сохранения перед выходом." << std::endl;
	std::cout << ">";
	std::cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		SaveDicitonaryToFile(output, dictionary);
		std::cout << "Изменения сохранены. Досвидания!" << std::endl;
	}
	else
	{
		std::cout << "Изменения не сохранены. Досвидания!" << std::endl;
	}
}

void ReadDictonairyFromFile(std::ifstream& input, Dictionary& dictionary)
{
	std::string word, translationWord;
	while (getline(input, word))
	{
		if (getline(input, translationWord))
		{
			auto foundWords = FindWornInDictionary(word, dictionary);
			bool dictionaryChange = false;
			if (foundWords.empty())
			{
				AddWordToDictionary(word, translationWord, dictionary, dictionaryChange);
			}
		}
	}
}

void Translation(Dictionary& dictionary, bool& isDictionaryChange)
{
	std::string inputString;
	while (inputString != "...")
	{
		std::cout << ">";
		getline(std::cin, inputString);
		if (inputString != "...")
		{
			HandleNewWord(ToLowerCase(inputString), dictionary, isDictionaryChange);
		}
	}
}

bool CheckArgument(const int argumentCount)
{
	if (argumentCount > 2)
	{
		std::cerr << "invalid params. Use this:" << std::endl;
		std::cerr << "translator [<input dictionary>]" << std::endl;
		return false;
	}
	return true;
}

std::string ToLowerCase(std::string str)
{
	std::locale loc;
	for (auto& ch : str)
	{
		ch = tolower(ch, loc);
	}
	return str;
}