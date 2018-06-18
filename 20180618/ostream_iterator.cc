 ///
 /// @file    ostream_iterator.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-18 19:41:04
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main(void)
{
	vector<int> numbers{1,2,3,4,5,6};
	ostream_iterator<int> osi(cout, " ");

	std::copy(numbers.begin(), numbers.end(), osi);
	cout << endl;
	return 0;
}
