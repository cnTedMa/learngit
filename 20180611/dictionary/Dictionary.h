 ///
 /// @file    Dictionary.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 20:20:14
 ///

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

struct Record
{
	Record(const string & word, int freq)
	:_word(word)
	,_freq(freq)
	{}

	string _word;
	int _freq;
};

inline
bool operator < (const Record &lhs, const Record & rhs)
{
	return lhs._word < rhs._word;
}

class Dictionary
{
public:
	Dictionary()
	{
		_dictionary.reserve(20000);
	}

	void read(const string & filename);

	void store(const string & filename);

private:
	void processWord(const string &word);

private:
	vector<Record> _dictionary;
};

#endif
