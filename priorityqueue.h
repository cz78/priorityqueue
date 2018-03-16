
class Priority_queue_base {
public:
    virtual ~Priority_queue_base() { }
    virtual bool empty() const = 0;
    virtual void insert(int x) = 0;
    virtual int pop_min() = 0;
    virtual void pq_sort() = 0;
};

class PQ_standard : public Priority_queue_base {
private:
    vector<int> vec;
    unsigned long long int count = 0;
public:
    // A structure that measure the numbers of comparison made
    class compare
    {
      private:
        compare * self;
      public:
        unsigned long long int counter = 0;
        compare()
        {
          self = this;
        }
        ~compare()
        {}
        bool operator() (int x, int y)
        {
          self->counter++;
          return x < y;
        }
    };
    //Constructor
    PQ_standard()
    {}
    //Destructors
    ~PQ_standard()
    {}
    // int &operator[](int i)
    // {
    //    return vec.at(i);
    // }
    //Check if queue is empty
    bool empty() const
    {
      return vec.empty();
    }
    //Insert a value on to a queue
    void insert(int x)
    {
      vec.push_back(x);
    }
    //Find and pop min value in queue
    int pop_min()
    {
      //Return on empty queue
      if (vec.empty()) {
        cmpt::error("empty queue");
      }
      //Initialize variables
      auto minelement = vec.front();
      auto minlocation = vec.begin();
      //Iterate and find the location of the minimum value
      //in queue
      for (auto iterate = vec.begin(); iterate != vec.end(); iterate++)
      {
        if (minelement > *iterate)
        {
          minelement = *iterate;
          minlocation = iterate;
        }
        count++;
      }
      //Erase the element
      int popped = *minlocation;
      vec.erase(minlocation);
      //vec.shrink_to_fit();
      return popped;
    }
    //Sorting queue using standard library
    void pq_sort()
    {
      //Return on empty queue
      if (vec.empty())
      {
        cmpt::error("empty queue");
        return;
      }
      //Call sort function and overloading it with
      //the structure that compute the numbers of comparison made
      compare counting;
      sort(vec.begin(), vec.end(), counting);
      //Another way is to use landa function
      //sort(vec.begin(), vec.end(), [&count](int x, int y)){ return x < y};
      count = counting.counter;
    }
    void print() const
    {
      for (auto iterate = vec.begin(); iterate != vec.end(); iterate++)
      {
        cout << *iterate << " ";
      }
      cout << endl;
    }
    int comparecount()
    {
      return count;
    }
};
