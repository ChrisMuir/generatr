#include <Rcpp.h>
using namespace Rcpp;


#ifndef __GENERATR_H__
#define __GENERATR_H__


// Integer generator class
template<typename T>
class generatr {
  public:
    void init_with_vector(std::vector<T> input);
    void increment(void);
    T next(void);
    T get_curr(void);

    void init_empty(void);
    void add_element(T elem);

    void init_iterators(void);
    void assert_untouched(void);

  private:
    typename std::vector<T> init_input;
    typename std::vector<T>::iterator curr;
    typename std::vector<T>::iterator end;
    bool been_called;
};


#endif /* __GENERATR_H__ */
