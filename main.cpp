#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol955;

/*
Input: ["ca","bb","ac"]
Output: 1
Explanation:
After deleting the first column, A = ["a", "b", "c"].
Now A is in lexicographic order (ie. A[0] <= A[1] <= A[2]).
We require at least 1 deletion since initially A was not in lexicographic order, so the answer is 1.
*/
tuple<vector<string>, int>
testFixture1()
{
  auto A = vector<string>{"ca", "bb", "ac"};
  return make_tuple(A, 1);
}

/*
Input: ["xc","yb","za"]
Output: 0
Explanation:
A is already in lexicographic order, so we don't need to delete anything.
Note that the rows of A are not necessarily in lexicographic order:
ie. it is NOT necessarily true that (A[0][0] <= A[0][1] <= ...)
*/
tuple<vector<string>, int>
testFixture2()
{
  auto A = vector<string>{"xc", "yb", "za"};
  return make_tuple(A, 0);
}
/*
Input: ["zyx","wvu","tsr"]
Output: 3
Explanation:
We have to delete every column.
*/
tuple<vector<string>, int>
testFixture3()
{
  auto A = vector<string>{"zyx", "wvu", "tsr"};
  return make_tuple(A, 3);
}
void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}
void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  Solution sol;
  cout << "Expect to see " << get<1>(f)
       << ": " << sol.minDeletions(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}