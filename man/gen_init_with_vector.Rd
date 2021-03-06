% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/generatr.R
\name{gen_init_with_vector}
\alias{gen_init_with_vector}
\title{Initialize a generator object with input vector}
\usage{
gen_init_with_vector(x)
}
\arguments{
\item{x}{vector, of type integer, numeric, character, or logical.}
}
\value{
object of class \code{generator}
}
\description{
Initialize a generator object with input vector
}
\examples{
gen <- gen_init_with_vector(1L:10L)

}
