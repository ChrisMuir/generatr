
<!-- README.md is generated from README.Rmd. Please edit that file -->
generatr
========

This package is an attempt at an implementation of a "Pythonesque" generator data type and methods. It didn't work out 100% ... there's no magic `yield` method :( ... but I figured I'd share it anyways, incase anyone might find it useful.

See [here](https://wiki.python.org/moin/Generators) for more information on Python generators.

Installation
------------

Install from github with:

``` r
# install.packages("devtools")
devtools::install_github("ChrisMuir/generatr")
```

Example Usage
-------------

``` r
library(generatr)
```

Initialize a new `generator` object with an R vector

``` r
gen <- gen_init_with_vector(c(1L, 5L, 20L, 45L))
```

Check the class of the object `gen`

``` r
class(gen)
#> [1] "integer"     "generator"   "externalptr"
```

Use `gen_next()` to get the next value from a `generator` object, similar to Python's `__next__()`

``` r
for (i in 1:4) {
  print(gen_next(gen))
}
#> [1] 1
#> [1] 5
#> [1] 20
#> [1] 45
```

Use `gen_current()` to get the current value from a `generator` object

``` r
gen_current(gen)
#> [1] 45
```

Once all values have been exhausted, `gen_next()` will throw a `StopIteration` error

``` r
gen_next(gen)
#> Error in C_gen_next(gen, type_in): StopIteration
```

We can also initialize a new `generator` object as an empty object

``` r
gen <- gen_init_empty(gen_type = "integer")
```

Again, check the class of object `gen`

``` r
class(gen)
#> [1] "integer"     "generator"   "externalptr"
```

New items can be added one by one

``` r
for (i in c(1L, 5L, 20L, 45L)) {
  gen_add_element(gen, i)
}
```

Once we're finished adding items, `gen_next()` and `gen_current()` work just like they did in the previous example

``` r
for (i in 1:4) {
  print(gen_next(gen))
}
#> [1] 1
#> [1] 5
#> [1] 20
#> [1] 45
```

Currently, the only data type supported are `integer`, `numeric`, `character`, and `logical`

``` r
gen <- gen_init_with_vector(c("cats", "dogs", "ducks", "frogs", "owls"))
for (i in 1:5) {
  print(gen_next(gen))
}
#> [1] "cats"
#> [1] "dogs"
#> [1] "ducks"
#> [1] "frogs"
#> [1] "owls"
```

One useful side effect is that `generator` object sizes are constant and very small. This is due to all data being passed through to C++ functions, and the actual `generator` R object is just a pointer to the input data.

``` r
library(pryr)
library(stringi)

x <- 1L:10000000L
pryr::object_size(x)
#> 40 MB

gen <- gen_init_with_vector(x)
pryr::object_size(gen)
#> 64 B

x <- stringi::stri_rand_strings(400000, 8)
pryr::object_size(x)
#> 28.8 MB

gen <- gen_init_with_vector(x)
pryr::object_size(gen)
#> 64 B
```
