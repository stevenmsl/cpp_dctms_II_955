#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol955;
using namespace std;

/*takeaways
  - main difference between this and question 944 is that here
    we only require the word to be lexicographic order between
    words not their individual columns
  - we still scan it first by col and then by row. But once
    we make sure everything is in strict increasing order
    among words after scanning a given column what happen
    afterward doesn't affect the order of words any more

    - Input: ["xc","yb","za"]
    - after we scanned the first col we have
      A[0] < A[1] < A[2]

   - break the tie
     - input: ["xc","xb","za"]
     - after we scan the first col
       - A[0] == A[1] < A[2]
       - the second col has to be deleted to maintain the order
    - input: ["xa","xb","zc"]
     - in this case A[0] == A[1] < A[2]
     - the second col will break the tie and make A[0] < A[1] < A[2]
*/
int Solution::minDeletions(vector<string> &A)
{
  int rows = A.size(), cols = A[0].size();
  auto result = 0;

  /*this is the crucial part
    - record if A[i] < A[i+1] up to the last scan
    - initialize to false - so we can remove
       the first col if we detect any rows
       that are out of order right from the
       get-go
    - if increasing[i] is false that means
      A[i] == A[i+1], there is a tie.
      - it doesn't mean A[i] < A[i+1] as
        we always remove the col that
        causes the words to be out
        of order
  */
  auto increasing = vector<bool>(rows - 1, false);

  for (auto c = 0; c < cols; c++)
  {
    int r;
    for (r = 0; r < rows - 1; r++)
    {
      /* A[r] and A[r+1] are the same
         - and we detect that things
           are out of order
         - remove this col
      */
      if (!increasing[r] && A[r][c] > A[r + 1][c])
      {
        result++;
        break;
      }
    }
    /* something out of order has been detected
       as you can't finish the loop
       - this col will be removed and won't
         participate in breaking the tie
    */
    if (r < rows - 1)
      continue;

    /* all good - see if we can break some ties if needed */
    for (r = 0; r < rows - 1; r++)
      increasing[r] = increasing[r] || A[r][c] < A[r + 1][c];
  }
  return result;
}