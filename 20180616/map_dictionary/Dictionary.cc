 ///
 /// @file    Dictionary.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 20:30:39
 ///
 
#include "Dictionary.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istringstream;

void Dictionary::read(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string line;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			processWord(word);
		}
	}
	ifs.close();
	//std::sort(_dictionary.begin(),_dictionary.end());
}

void Dictionary::store(const string & filename)
{
	ofstream ofs(filename);
	if(!ofs)
	{
		cout << "ofstream open error!" << endl;
		return;
	}

	for(auto & record : _dictionary)
	{
		ofs << record.first << " occurs " << record.second << ((record.second > 1)?" times" : " time") << endl;
	}
	ofs.close();
}

void Dictionary::processWord(const string & word)
{
	for(auto & ch : word)
	{
		if(!isalpha(ch))
			return;
	}
	++_dictionary[word];
}
