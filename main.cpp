#include <iostream>
#include "priorityqueue.h"

using namespace std;

int main()
{

  for (int i = 5000; i <= 100000; i = i+5000)
  {
    vector<int> basevector = {};
    for (int j = 1; j <= i; j++)
    {
      basevector.push_back(j);
    }
    random_shuffle(basevector.begin(), basevector.end());
    cout << endl << endl;
    cout << "Standard Sort" << endl;
    PQ_standard queue1;
    for (auto iterate1 = basevector.begin(); iterate1 != basevector.end(); iterate1++)
    {
      queue1.insert(*iterate1);
    }
    queue1.pq_sort();
    queue1.print();
    cout << endl;
  }
}
