# Pseudo Random Number Gernerator (PRNG)

This repo implements a very basic version of a [Linear Congruential Generator](https://en.wikipedia.org/wiki/Linear_congruential_generator);
the first project for my CI067 programming class; and then make some testing to show how bad the default values are.

There are 4 programs here:

1. Histogram for default values (histograma-1)
2. Histogram for better values (histograma-2)
3. Period of the default gererator (periodo-1)
4. Periodo for the generator with better values (periodo-2)


Please note that for any normal use, better parameters should be set for the renerator, such as A = 1103515245, C = 12345 and M = 2147483648.
Even then, this should **not** be used in any remotely serious application that needs random numbers.

## Compiling

To generate all of the programs listed above, simply run `make`.
You can also run make for each of the individual programs with its name.
Last, there is run `make compress` to generate a .tar.gz ready to send for my professor :) (But remember: plagiarism is bad).

## Dependencies

* gcc to compile the code.
* make to run the targets.
* tar to generate tarball

