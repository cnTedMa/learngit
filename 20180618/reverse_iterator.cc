 ///
 /// @file    reverse_iterator.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-18 19:47:35
 ///
 
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::list;
using std::copy;
using std::back_insert_iterator;

void test0(void)
{
	vector<int> numbers{1,2,3,4,5,6};
	vector<int>::reverse_iterator rit = numbers.rbegin();
	for(; rit != numbers.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;
}

void test1(void)
{
	vector<int> numbers{1,2,3};
	list<int> liNumbers;
	//std::back_insert_iterator内部使用push_back添加元素，只能操作vector,deque,list三个容器
	copy(numbers.begin(),numbers.end(),std::back_inserter<list<int> >(liNumbers));
	copy(liNumbers.begin(),liNumbers.end(),std::ostream_iterator<int>(cout," "));
	cout << endl;
	//std::front_insert_iterator内部使用push_front添加元素，只能操作deque,list,forward_list三个容器
	copy(numbers.begin(),numbers.end(),std::front_insert_iterator<list<int> >(liNumbers));
	copy(liNumbers.begin(),liNumbers.end(),std::ostream_iterator<int>(cout," "));
	cout << endl;
	//insert__iterator内部使用的是insert方法，操作的容器很多
	set<int> setNumbers;
	auto sit = setNumbers.begin();
	copy(numbers.begin(),numbers.end(),std::insert_iterator<set<int> >(setNumbers,sit));
	copy(setNumbers.begin(),setNumbers.end(),std::ostream_iterator<int>(cout," "));
	cout << endl;
}

int main(void)
{
	test0();
	cout << "------------------------" << endl;
	test1();
	return 0;
}
