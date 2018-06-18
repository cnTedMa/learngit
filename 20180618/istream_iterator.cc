 ///
 /// @file    istream_iterator.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-18 19:44:05
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::copy;

int main(void)
{
	vector<int> numbers;
	istream_iterator<int> isi(std::cin);
	copy(isi, istream_iterator<int>(), std::back_inserter(numbers));//需要使用插入迭代器
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout << ",,,,," << endl;
	return 0;
}
