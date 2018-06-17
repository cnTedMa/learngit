 ///
 /// @file    txt_search.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-17 12:14:01
 ///
 
#ifndef __TXT_SEARCH_H__
#define __TXT_SEARCH_H__


#include <vector>
#include <set>
#include <map>
#include <string>
using std::vector;
using std::set;
using std::map;
using std::string;

class txtSearch
{
public:
	txtSearch()
	{
		_lines.reserve(20000);
	}

	~txtSearch()
	{}

	void readFile(const string filename);
	void query(const string & word);

private:
	void processWord(const string &word,int line_no);

private:
	vector<string> _lines;
	map<string,set<int>> _word2Line;
	map<string,int> _dict;
};
#endif
