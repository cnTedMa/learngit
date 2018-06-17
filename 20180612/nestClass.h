 ///
 /// @file    nestClass.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-12 22:46:03
 ///

#ifndef __LINE_H__
#define __LINE_H__

//设计模式：PIMPL
//1.实现信息隐藏
//2.减小编译依赖，可以用最小的代价平滑的升级库文件
//3.接口与实现进行解耦

class Line
{
public:
	Line(int,int,int,int);
	~Line();
	void printLine() const;
private:
	class LineImpl;
private:
	LineImpl *_pimpl;
};

#endif
