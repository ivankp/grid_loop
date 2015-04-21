#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
  const int  row = atoi(argv[1]),  col = atoi(argv[2]);
  const int nrow = 6,             ncol = 7;
  
  printf("************************\n");
  for (int k=0; k<3; ++k) {
    const int row_min = row - k,
              row_max = row + k,
              col_min = col - k,
              col_max = col + k;

    int i = row_min;

    if (0<=i) {
      for (int j=max(col_min,0); j<=min(col_max,ncol-1); ++j) {
        //if (0<=j && j<ncol)
          printf("a(%d,%d) ",i,j);
      }
      ++i;
    } else i=0;

    for (; i<min(row_max,nrow); ++i) {
      if (col_min>=0)   printf("b(%d,%d) ",i,col_min);
      if (col_max<ncol) printf("c(%d,%d) ",i,col_max);
    }

    if (i<nrow && i<=row_max)
      for (int j=max(col_min,0); j<=min(col_max,ncol-1); ++j)
        printf("d(%d,%d) ",i,j);

    printf("\n");
  }
  
  printf("************************\n");
  
/*  for (int i=0; i<nrow; ++i) {
    for (int j=0; j<ncol; ++j) {
      if (abs(row-i)>=3 || abs(col-j)>=3)
        printf("(%d,%d) ",i,j);
    }
  }
  printf("\n************************\n");
*/

  return 0;
}
