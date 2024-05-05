void writePGM(unsigned char **mat, int nrows, int ncols);
void writePPM(unsigned char **mat[3], int nrows, int ncols);
char **mymatalloc(int nrows, int ncols, int typesize);

typedef struct  {
   int nrows, ncols;
   unsigned char **mat;
} GRAYMAP;

typedef struct  {
   int nrows, ncols;
   unsigned char **mat[3];
} PIXMAP;
