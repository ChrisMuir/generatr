% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/generatr.R
\name{gen_add_element}
\alias{gen_add_element}
\title{Add an item to a generator object}
\usage{
gen_add_element(gen, elem)
}
\arguments{
\item{gen}{object of class \code{generator}}

\item{elem}{scalar item, of type integer, numeric, character, or logical.}
}
\value{
object of class \code{generator}
}
\description{
Add an item to a generator object
}
\examples{
gen <- gen_init(gen_type = "integer")
gen <- gen_add_element(gen, 5L)
}
