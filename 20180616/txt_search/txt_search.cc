 ///
 /// @file    txt_search.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-17 12:26:34
 ///
 
#include "txt_search.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;

void txtSearch::readFile(const string filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}
	string line;
	_lines.push_back(line);
	int line_no = 1;
	while(getline(ifs,line))
	{
		_lines.push_back(line);
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			processWord(word,line_no);
		}
		++line_no;
	}
	ifs.close();
}

void txtSearch::processWord(const string & word,int line_no)
{
	for(auto & ch : word)
	{
		if(!isalpha(ch))
			return;
	}
	++_dict[word];
	_word2Line[word].insert(line_no);
}

void txtSearch::query(const string & word)
{
	cout << word << " occurs " << _dict[word] << ((_dict[word] > 1)?" times." : " time.") << endl;
	for(auto & line_no : _word2Line[word])
	{
		cout << "(line " << line_no << ") " << _lines[line_no] << endl;
	}
}
