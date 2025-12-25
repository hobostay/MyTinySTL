#ifndef MYTINYSTL_ITERATOR_TEST_H_
#define MYTINYSTL_ITERATOR_TEST_H_

#include "test.h"
#include "../MyTinySTL/iterator.h"
#include "../MyTinySTL/stream_iterator.h"

namespace mystl
{
namespace test
{
namespace iterator_test
{

void stream_iterator_test()
{
  std::cout << "[===============================================================]\n";
  std::cout << "[------------- Run iterator test : stream_iterator--------------]\n";
  std::cout << "[-------------------------- API test ---------------------------]\n";

  static_assert(mystl::is_exactly_input_iterator<mystl::istream_iterator<int>>::value,
                "istream_iterator must have input_iterator_tag)");

  std::istringstream is("1 2 3");
  mystl::istream_iterator<int> first{is}, last;
  std::cout << mystl::distance(first, last) << '\n';

  std::istringstream istream("1 2 3 4 5 6");
  mystl::istream_iterator<int> beg{istream}, end;
  for (; beg != end; ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << '\n';

  // ostream_iterator test
  std::cout << "\n[------------------ ostream_iterator test --------------------]\n";
  std::vector<int> v1{1, 2, 3, 4, 5};
  std::cout << "Output with delimiter: ";
  mystl::ostream_iterator<int> out_iter1(std::cout, " ");
  mystl::copy(v1.begin(), v1.end(), out_iter1);
  std::cout << '\n';

  std::cout << "Output without delimiter: ";
  mystl::ostream_iterator<int> out_iter2(std::cout);
  mystl::copy(v1.begin(), v1.end(), out_iter2);
  std::cout << '\n';

  std::vector<std::string> v2{"Hello", "World", "MyTinySTL"};
  std::cout << "String output with delimiter: ";
  mystl::ostream_iterator<std::string> out_iter3(std::cout, ", ");
  mystl::copy(v2.begin(), v2.end(), out_iter3);
  std::cout << '\n';

  PASSED;
}

} // namespace stream_iterator_test
} // namespace test
} // namespace mystl
#endif // !MYTINYSTL_STREAM_ITERATOR_TEST_H_

