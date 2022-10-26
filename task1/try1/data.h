# ifndef data_H
# define data_H

# include <stdio.h>

#ifndef M
#   error "M must be defined"
#endif

class data
{
    private:
    int m = M;
    double a[M] = {0};
    static int p;
    public:
    data () = default;
    ~data () = default;
    int get_n () const { return m; }
    const double * get_a () { return a; }
    static int get_p () { return p; }
    static void set_p (int q) { p = q; }
// Copy constructor
    data (const data &x) = default;
    // Assignement operator
    data& operator= (const data&) = default;
// Comparison operators
    int operator< (const data& x) const { return m < x.m; }
    int operator> (const data& x) const { return m > x.m; }
// Print data in a line (not more than p): m a[0] a[1] ... a[m-1]
    void print (FILE * fp = stdout);
// Read data from the line: m a[0] a[1] ... a[m-1]
    int read (FILE *fp = stdin);
// Init data by formulae with number s
    void init (int s, int n, int i);
// Print an array of data type objects
};

# endif // data