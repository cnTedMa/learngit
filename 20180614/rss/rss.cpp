///
/// @file    rss.cpp
/// @author  Ted(18634365225@163.com)
/// @date    2018-06-15 22:16:53
///

#include "tinyxml2.h"

#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>
using namespace tinyxml2;
using namespace std;
struct RssItem
{
	string title;
	string link;
	string description;
	string content;
};

class RssReader
{
	public:
		RssReader();

		void parseRss();
		void dump();
	private:
		vector<RssItem> _rss;
};

RssReader::RssReader()
{
	cout << "RssReader()" << endl;
}

void RssReader::parseRss()
{
	DIR *dir;
	dir = opendir("rss源");
	if(NULL == dir)
	{
		perror("opendir");
		return;
	}
	struct dirent *p;
	while((p = readdir(dir)))
	{
		if(!strcmp(p->d_name,".") || !strcmp(p->d_name,".."))
		{
			continue;
		}
		cout << "filename:" << p->d_name << endl;
		//cout << "still alive" << endl;
		XMLDocument doc;
		//cout << "still alive" << endl;
		string path = "rss源/";
		path += p->d_name;
		cout << path << endl;
		doc.LoadFile(path.c_str());
		//cout << "still alive" << endl;
		XMLElement * root = doc.RootElement();
		//cout << "still alive" << endl;
		//cout << root->FirstAttribute()->Name() << endl;
		if(strcmp(root->FirstAttribute()->Name(),"version")==0)
		{
			//cout << "I'm if" << endl;
			XMLElement * channel = root->FirstChildElement("channel");
			//cout << "still alive" << endl;
			XMLElement * item = channel->FirstChildElement("item");
			//cout << "still alive" << endl;
			while(item)
			{
				RssItem rssitem;
				XMLElement *itemChild = item->FirstChildElement("title");
				//cout << "title alive" << endl;
				if(itemChild->GetText() == NULL)
				{
					goto next;
				}
				rssitem.title = itemChild->GetText();
				itemChild = item->FirstChildElement("link");
				//cout << "link alive" << endl;
				rssitem.link = itemChild->GetText();
				itemChild = item->FirstChildElement("description");
				//cout << "description alive" << endl;
				if(itemChild != NULL)
				{
					string content = itemChild->GetText();
					regex pattern("<[^>]+>");
					content = regex_replace(content,pattern,"");
					regex pattern2("&nbsp");
					rssitem.description = regex_replace(content,pattern2,"");
				}
				//cout << "if alive" << endl;
				itemChild = item->FirstChildElement("content");
				//cout << "content alive" << endl;
				if(itemChild != NULL)
				{
					string content = itemChild->GetText();
					regex pattern("<[^>]+>");
					content = regex_replace(content,pattern,"");
					regex pattern2("&nbsp");
					rssitem.content = regex_replace(content,pattern2,"");
				}
				_rss.push_back(rssitem);
next:
				item = item->NextSiblingElement("item");
			}
		}
		else{
			//cout << "I'm here" << endl;
			XMLElement * entry = root->FirstChildElement("entry");
			//cout << "I'm here" << endl;
			while(entry)
			{
				RssItem rssitem;
				XMLElement *entryChild = entry->FirstChildElement("title");
				if(entryChild->GetText() == NULL)
				{
					goto next1;
				}
				rssitem.title = entryChild->GetText();
				entryChild = entry->FirstChildElement("id");
				rssitem.link = entryChild->GetText();
				entryChild = entry->FirstChildElement("description");
				if(entryChild != NULL)
				{
					string content = entryChild->GetText();
					regex pattern("<[^>]+>");
					content = regex_replace(content,pattern,"");
					regex pattern2("&nbsp");
					rssitem.description = regex_replace(content,pattern2,"");
				}
				entryChild = entry->FirstChildElement("content");
				if(entryChild != NULL)
				{
					string content = entryChild->GetText();
					regex pattern("<[^>]+>");
					content = regex_replace(content,pattern,"");
					regex pattern2("&nbsp");
					rssitem.content = regex_replace(content,pattern2,"");
				}
				_rss.push_back(rssitem);
next1:
				entry = entry->NextSiblingElement("entry");
			}
		}
	}
}

void RssReader::dump()
{
	ofstream ofs("pagelib.dat");
	int i = 1;
	for(auto ele:_rss)
	{
		ofs << "<doc>\n";
		ofs << "\t<docid>" << i++ << "</docid>\n";
		ofs << "\t<title>" << ele.title << "</title>\n";
		ofs << "\t<link>" << ele.link << "</link>\n";
		ofs << "\t<description>" << ele.description << "</description>\n";
		ofs << "\t<content>" << ele.content << "</content>\n";
		ofs << "</doc>\n";
	}
}

int main()
{
	RssReader rr;
	rr.parseRss();
	rr.dump();
}
