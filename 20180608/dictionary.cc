 ///
 /// @file    dictionary.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 21:34:23
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

struct wordCount{
	string word;
	int cnt;
}wordCount;

class dictionary
{
public:
	void read(const string & filename)
	{
		ifstream ifs(filename);
		if(!ifs)
		{
			cout << "file open error!" << endl;
			return;
		}
		string word;
		while(ifs>>word)
		{
			//cout << word << " " ;
			if(word[0] >= '0' && word[0] <= '9')
				continue;
			struct wordCount tmp;
			tmp.word=word;
			tmp.cnt=1;
			//cout << tmp.word << " " << tmp.cnt << endl;
			int flag=0;
			for(auto & w:_wordlist)
			{
				if(w.word==tmp.word)
				{
					flag=1;
					++w.cnt;
				}
			}
			if(flag==0)
			{
				_wordlist.push_back(tmp);
			}
		}
	}

	void print()
	{
		for(auto & w:_wordlist)
		{
			cout << w.word << " " << w.cnt << endl;
		}
	}
	
	void store(const string &filename)
	{
		ofstream ofs(filename);
		for(auto & w:_wordlist)
		{
			ofs << w.word << " " << w.cnt << endl;
		}
	}

private:
	vector<struct wordCount> _wordlist;
};

int main()
{
	dictionary d;
	time_t begin,end;
	begin = time(NULL);
	d.read("The_Holy_Bible.txt");
	//d.print();
	d.store("dictionary.txt");
	end = time(NULL);
	cout << "use time: " << end-begin << "s" << endl;
	return 0;
}
