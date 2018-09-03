#include <Rcpp.h>
using namespace Rcpp;

#include "generatr.h"


///////////////////////////////////////////////////////
// Definitions of functions from header file generatr.h
///////////////////////////////////////////////////////

// Initialize a generator object with an input vector.
template<typename T>
void generatr<T>::init_with_vector(std::vector<T> input) {
  generatr::init_input = input;
  generatr::been_called = false;
}


// Increment iterator variable "curr" by one.
template<typename T>
void generatr<T>::increment(void) {
  generatr::curr = generatr::curr + 1;
}


// Increment iterator "curr" by one, then return the value of "curr".
template<typename T>
T generatr<T>::next(void) {
  if(generatr::curr != generatr::end) {
    if(generatr::been_called) {
      generatr::increment();
    } else {
      generatr::been_called = true;
    }

    return generatr::get_curr();
  }

  stop("StopIteration");
}


// Get the current value of variable "curr".
template<typename T>
T generatr<T>::get_curr(void) {
  return *generatr::curr;
}


// Initialize an empty generator object.
template<typename T>
void generatr<T>::init_empty() {
  generatr::been_called = false;
}


// Add an item to a generator object.
template<typename T>
void generatr<T>::add_element(T elem) {
  generatr::init_input.push_back(elem);
}


// Assert that "next" has not yet been called on the input generator object.
// Do so by asserting that variable "been_called" is false.
template<typename T>
void generatr<T>::assert_untouched() {
  if(generatr::been_called) {
    stop("Cannot add items to a generator after 'next' has been called");
  }
}


// Initialize the two iterator variables "curr" and "end".
template<typename T>
void generatr<T>::init_iterators() {
  generatr::curr = generatr::init_input.begin();
  generatr::end = generatr::init_input.end() - 1;
}



/////////////////////
// Exported functions
/////////////////////

// Initialize an empty generator object.
// [[Rcpp::export]]
SEXP C_gen_init_empty(SEXP x) {
  switch(TYPEOF(x)) {
    case INTSXP: {
      generatr<int> *gen = new generatr<int>;
      gen->init_empty();
      XPtr<generatr<int> > ptr(gen, true);
      return ptr;
    }
    case REALSXP: {
      generatr<double> *gen = new generatr<double>;
      gen->init_empty();
      XPtr<generatr<double> > ptr(gen, true);
      return ptr;
    }
    case STRSXP: {
      generatr<std::string> *gen = new generatr<std::string>;
      gen->init_empty();
      XPtr<generatr<std::string> > ptr(gen, true);
      return ptr;
    }
    case LGLSXP: {
      generatr<bool> *gen = new generatr<bool>;
      gen->init_empty();
      XPtr<generatr<bool> > ptr(gen, true);
      return ptr;
    }
    default: {
      stop(
        "arg 'x' must be a scalar value of type int, double, string, or bool"
      );
    }
  }

  return R_NilValue;
}


// Add an item to a generator object.
// [[Rcpp::export]]
void C_add_element(SEXP ptr, SEXP elem) {
  switch(TYPEOF(elem)) {
    case INTSXP: {
      XPtr<generatr<int> > x(ptr);
      x->assert_untouched();
      x->add_element(as<int>(elem));
      x->init_iterators();
      break;
    }
    case REALSXP: {
      XPtr<generatr<double> > x(ptr);
      x->assert_untouched();
      x->add_element(as<double>(elem));
      x->init_iterators();
      break;
    }
    case STRSXP: {
      XPtr<generatr<std::string> > x(ptr);
      x->assert_untouched();
      x->add_element(as<std::string>(elem));
      x->init_iterators();
      break;
    }
    case LGLSXP: {
      XPtr<generatr<bool> > x(ptr);
      x->assert_untouched();
      x->add_element(as<bool>(elem));
      x->init_iterators();
      break;
    }
    default: {
      stop("arg 'elem' must be one of int, double, string, or bool");
    }
  }
}


// Initialize a generator object with an input vector.
// [[Rcpp::export]]
SEXP C_gen_init_with_vector(SEXP x) {
  switch(TYPEOF(x)) {
    case INTSXP: {
      generatr<int> *gen = new generatr<int>;
      gen->init_with_vector(as<std::vector<int> >(x));
      gen->init_iterators();
      XPtr<generatr<int> > ptr(gen, true);
      return ptr;
    }
    case REALSXP: {
      generatr<double> *gen = new generatr<double>;
      gen->init_with_vector(as<std::vector<double> >(x));
      gen->init_iterators();
      XPtr<generatr<double> > ptr(gen, true);
      return ptr;
    }
    case STRSXP: {
      generatr<std::string> *gen = new generatr<std::string>;
      gen->init_with_vector(as<std::vector<std::string> >(x));
      gen->init_iterators();
      XPtr<generatr<std::string> > ptr(gen, true);
      return ptr;
    }
    case LGLSXP: {
      generatr<bool> *gen = new generatr<bool>;
      gen->init_with_vector(as<std::vector<bool> >(x));
      gen->init_iterators();
      XPtr<generatr<bool> > ptr(gen, true);
      return ptr;
    }
    default: {
      stop("arg 'x' must be a vector of type int, double, string, or bool");
    }
  }

  return R_NilValue;
}


// Increment generator object by one, then return the current value.
// [[Rcpp::export]]
SEXP C_gen_next(SEXP ptr, SEXP gen_type) {
  switch(TYPEOF(gen_type)) {
    case INTSXP: {
      XPtr<generatr<int> > x(ptr);
      return wrap(x->next());
    }
    case REALSXP: {
      XPtr<generatr<double> > x(ptr);
      return wrap(x->next());
    }
    case STRSXP: {
      XPtr<generatr<std::string> > x(ptr);
      return wrap(x->next());
    }
    case LGLSXP: {
      XPtr<generatr<bool> > x(ptr);
      return wrap(x->next());
    }
    default: {
      stop(
        "arg 'gen_type' must be a scalar value of type int, double, string, or bool"
      );
    }
  }

  return R_NilValue;
}


// Get the current value of a generator object.
// [[Rcpp::export]]
SEXP C_gen_current(SEXP ptr, SEXP gen_type) {
  switch(TYPEOF(gen_type)) {
    case INTSXP: {
      XPtr<generatr<int> > x(ptr);
      return wrap(x->get_curr());
    }
    case REALSXP: {
      XPtr<generatr<double> > x(ptr);
      return wrap(x->get_curr());
    }
    case STRSXP: {
      XPtr<generatr<std::string> > x(ptr);
      return wrap(x->get_curr());
    }
    case LGLSXP: {
      XPtr<generatr<bool> > x(ptr);
      return wrap(x->get_curr());
    }
    default: {
      stop(
        "arg 'gen_type' must be a scalar value of type int, double, string, or bool"
      );
    }
  }

  return R_NilValue;
}
