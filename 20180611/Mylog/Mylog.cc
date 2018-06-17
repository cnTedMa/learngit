 ///
 /// @file    Mylog.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 20:57:23
 ///
 
#include "Mylog.h"

#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
using std::cout;
using namespace wd;

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getInstance()
{
	if(_pInstance == NULL)
	{
		_pInstance = new Mylog();	
	}
	return _pInstance;
}

void Mylog::destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}

void Mylog::warn(const char * msg)
{
	_root.warn(msg);
}

void Mylog::info(const char * msg)
{
	_root.info(msg);
}

void Mylog::error(const char * msg)
{
	_root.error(msg);
}

void Mylog::debug(const char * msg)
{
	_root.debug(msg);
}

Mylog::Mylog()
:_root(Category::getRoot().getInstance("root"))
{
	PatternLayout * pthLyout1 = new PatternLayout();
	pthLyout1->setConversionPattern("%d [%p] %m%n");
	PatternLayout * pthLyout2 = new PatternLayout();
	pthLyout2->setConversionPattern("%d [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender",&cout);
	ostreamAppender->setLayout(pthLyout1);

	FileAppender * fileAppender = new FileAppender("fileAppender","wangdao.txt");
	fileAppender->setLayout(pthLyout2);

	_root.addAppender(ostreamAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
	Category::shutdown();
}
