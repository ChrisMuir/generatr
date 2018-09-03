#' Initialize an empty generator object
#'
#' @param gen_type char string, indicating the data type of the generator
#'  object. Must be one of "integer", "numeric", "character", or "logical".
#'
#' @return object of class \code{generator}
#' @export
#'
#' @examples
#' gen <- gen_init(gen_type = "integer")
gen_init_empty <- function(gen_type = c("integer", "numeric", "character",
                                        "logical")) {
  gen_type <- match.arg(gen_type)
  type_in <- gen_type_switch[[gen_type]]
  structure(C_gen_init_empty(type_in),
            class = c(gen_type, "generator", "externalptr"))
}

#' Add an item to a generator object
#'
#' @param gen object of class \code{generator}
#' @param elem scalar item, of type integer, numeric, character, or logical.
#'
#' @return object of class \code{generator}
#' @export
#'
#' @examples
#' gen <- gen_init(gen_type = "integer")
#' gen <- gen_add_element(gen, 5L)
gen_add_element <- function(gen, elem) {
  stopifnot(inherits(gen, "generator"))
  UseMethod("gen_add_element")
}

#' @export
gen_add_element.integer <- function(gen, elem) {
  stopifnot(is.integer(elem))
  C_add_element(gen, elem)
}

#' @export
gen_add_element.numeric <- function(gen, elem) {
  stopifnot(is.numeric(elem))
  C_add_element(gen, elem)
}

#' @export
gen_add_element.character <- function(gen, elem) {
  stopifnot(is.character(elem))
  C_add_element(gen, elem)
}

#' @export
gen_add_element.logical <- function(gen, elem) {
  stopifnot(is.logical(elem))
  C_add_element(gen, elem)
}

#' @export
gen_add_element.default <- function(gen, elem) {
  stop("arg 'gen' must be a generator object with class integer, numeric,
       character, or logical")
}

#' Initialize a generator object with input vector
#'
#' @param x vector, of type integer, numeric, character, or logical.
#'
#' @return object of class \code{generator}
#' @export
#'
#' @examples
#' gen <- gen_init_with_vector(1L:10L)
#'
#' @useDynLib generatr
#' @importFrom Rcpp sourceCpp
gen_init_with_vector <- function(x) {
  stopifnot(is.integer(x) || is.numeric(x) || is.character(x) || is.logical(x))
  structure(C_gen_init_with_vector(x),
            class = c(class(x), "generator", "externalptr"))
}

#' Get next value of a generator object
#'
#' @param gen object of class \code{generator}
#'
#' @return The "next" value of a generator object. Will be a scalar value with
#'  type identical to that of the input generator.
#' @export
#'
#' @examples
#' gen <- gen_init(1L:10L)
#' gen_next(gen)
gen_next <- function(gen) {
  stopifnot(inherits(gen, "generator"))
  UseMethod("gen_next")
}

#' @export
gen_next.default <- function(gen) {
  return("fail")
}

#' @export
gen_next.integer <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_next(gen, type_in)
}

#' @export
gen_next.numeric <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_next(gen, type_in)
}

#' @export
gen_next.character <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_next(gen, type_in)
}

#' @export
gen_next.logical <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_next(gen, type_in)
}


#' Get current value of a generator object
#'
#' @param gen object of class \code{generator}
#'
#' @return The "current" value of a generator object. Will be a scalar value
#'  with type identical to that of the input generator.
#' @export
#'
#' @examples
#' gen <- gen_init(1L:10L)
#' gen_get_current(gen)
gen_current <- function(gen) {
  stopifnot(inherits(gen, "generator"))
  UseMethod("gen_current")
}

#' @export
gen_current.default <- function(gen) {
  return("fail")
}

#' @export
gen_current.integer <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_current(gen, type_in)
}

#' @export
gen_current.numeric <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_current(gen, type_in)
}

#' @export
gen_current.character <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_current(gen, type_in)
}

#' @export
gen_current.logical <- function(gen) {
  type_in <- gen_type_switch[[class(gen)[1]]]
  C_gen_current(gen, type_in)
}

# Named list for applying a switch to input args in function gen_init_empty().
gen_type_switch <- list("integer" = 1L, "numeric" = 1.0, "character" = "a",
                        "logical" = TRUE)
