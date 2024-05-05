

void matXvect(double** m, int nrows, int ncols, double* v, double* res);
void matXmat(double** m1, double** m2, double** mres, int nrows, int ncols, int dim);
void matprint(double** m, int nrows, int ncols);
double **matalloc(int nrows, int ncols);
double **matrand(int nrows, int ncols);

