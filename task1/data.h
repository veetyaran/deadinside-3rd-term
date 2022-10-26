# ifndef data_H
# define data_H

# include <stdio.h>
# include "smileyface.h"

#ifndef M
#   error "M must be defined"
#endif

class data
{
    private:
        int m = M;
        double a[M] = {};
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
        void init (int s);
};

void data::print(FILE* fp) //print data
{
    int length = p < m ? p : m; 
    fprintf(fp, "%d", m);
    for(int i = 0; i < length; i++)
    {
        fprintf(fp, " %lf ", a[i]);
    }
    fputc('\n', fp);
}

int data::read(FILE* fp) //-2 read error, 0 success
{
    double trash;
    if(fscanf(fp, "%d", &m) != 1) return static_cast<int>(smileyface::readnt);
    for(int i = 0; i < (m < M ? m : M); i++)
    {
        if(fscanf(fp, "%lf", &a[i]) != 1) return static_cast<int>(smileyface::readnt);
    }
    for(int i = 0; i < ((m > M ? m : M) - (m < M ? m : M)); i++)
    {
        if(fscanf(fp, "%lf", &trash) != 1) return static_cast<int>(smileyface::readnt);
    }
    return static_cast<int>(smileyface::nice);
}

void data::init(int s)
{
    m = s;
}

# endif // data