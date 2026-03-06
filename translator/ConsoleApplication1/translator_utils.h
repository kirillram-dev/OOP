#include <clocale>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#include <windows.h>
#include <locale>

typedef std::multimap<std::string, std::string> Dictionary;

void AddWordToDictionary(const std::string& word, const std::string& translationWord, Dictionary& dictionary, bool& isDictionaryChange);
std::vector<std::string> FindWornInDictionary(const std::string& word, Dictionary& dictionary);
void AddNewWord(const std::string& word, Dictionary& dictionary, bool& isDictionaryChange);
void HandleNewWord(const std::string& word, Dictionary& dictionary, bool& isDictionaryChange);
void SaveDicitonaryToFile(std::ofstream& output, const Dictionary& dictionary);
void CompleteTranslsation(std::ofstream& output, const Dictionary& dictionary);
void ReadDictonairyFromFile(std::ifstream& input, Dictionary& dictionary);
void Translation(Dictionary& dictionary, bool& isDictionaryChange);
bool CheckArgument(const int argumentCount);
std::string ToLowerCase(std::string str);


