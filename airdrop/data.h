# ifndef DATA_H
# define DATA_H
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
class data
{
	private:
		int m = M;
		double a[M] = {0};
		static int p;
	public:
		data () = default;
		~data () = default;
		int get_m () const { return m; }
		const double * get_a () { return a; }
		static int get_p () { return p; }
		static void set_p (int q){ p = q; }
		// Copy constructor
		data (const data &x) = default;
		// Assignement operator
		data& operator= (const data&) = default;
		// Comparison operators
		int operator< (const data& x) const
		{ return m < x.m; }
		int operator> (const data& x) const
		{ return m > x.m; }
		// Print data in a line (not more than p): m a[0] a[1] ... a[m-1]
		void print (FILE * fp = stdout);
		// Read data from the line: m a[0] a[1] ... a[m-1]
		int read (FILE * fp = stdin);
		// Init data by formulae with number s
		void init (int s);
		void swap(data& x);
};
# endif // data