#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int mod(int i, int n) {
  return ( (i%=n) < 0 ? i+n : i );
}

int main(int argc, char **argv) {
  const int  row = atoi(argv[1]),  col = atoi(argv[2]);
  const int nrow = 5,             ncol = 7;
  const int nk = (nrow>>1);
  
  printf("************************\n");
  for (int k=0; k<=nk; ++k) {
    const int row_min = row - k,
              row_max = row + k,
              col_min = col - k,
              col_max = col + k;

    int i = row_min;

    for (int j=max(col_min,0); j<=min(col_max,ncol-1); ++j)
      printf("a(%d,%d) ",mod(i,nrow),j);

    for (++i; i<row_max; ++i) {
      if (col_min>=0)   printf("b(%d,%d) ",mod(i,nrow),col_min);
      if (col_max<ncol) printf("c(%d,%d) ",mod(i,nrow),col_max);
    }
    
    if (k>0)
      for (int j=max(col_min,0); j<=min(col_max,ncol-1); ++j)
        printf("d(%d,%d) ",mod(i,nrow),j);

    printf("\n");
  }
  
  printf("........................\n");
  
  // left loop
  for (int j=0; j<col-nk; ++j) {
    for (int i=0; i<nrow; ++i) {
      printf("(%d,%d) ",i,j);
    }
    printf("\n");
  }
      
  printf("........................\n");

  // right loop
  for (int j=col+nk+1; j<ncol; ++j) {
    for (int i=0; i<nrow; ++i) {
      printf("(%d,%d) ",i,j);
    }
    printf("\n");
  }
  
  printf("************************\n");

  return 0;
}
