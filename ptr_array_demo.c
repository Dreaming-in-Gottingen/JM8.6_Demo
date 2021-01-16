#include <stdio.h>
#include <stdlib.h>

#define byte char

int get_mem2D(byte ***array2D, int rows, int columns)
{
  int i;

  if((*array2D = (byte**)calloc(rows, sizeof(byte*))) == NULL) {
    //no_mem_exit("get_mem2D: array2D");
    puts("no mem!");
  }

  if(((*array2D)[0] = (byte*)calloc(columns*rows, sizeof(byte))) == NULL) {
    //no_mem_exit("get_mem2D: array2D");
    puts("no mem!");
  }

  for(i=1; i<rows; i++)
    (*array2D)[i] = (*array2D)[i-1] + columns;

  return rows*columns;
}

int get_mem3D(byte ****array3D, int frames, int rows, int columns)
{
  int j;

  if(((*array3D) = (byte***)calloc(frames, sizeof(byte**))) == NULL) {
    //no_mem_exit("get_mem3D: array3D");
    puts("no mem!");
  }

  for(j=0; j<frames; j++)
    get_mem2D( (*array3D)+j, rows, columns );

  return frames*rows*columns;
}

//int get_mem4Dint(int *****array4D, int idx, int frames, int rows, int columns )
int get_mem4D(byte *****array4D, int idx, int frames, int rows, int columns )
{
  int j;

  if(((*array4D) = (byte****)calloc(idx,sizeof(int**))) == NULL) {
    //no_mem_exit("get_mem4Dint: array4D");
    puts("no mem!");
  }

  for(j=0; j<idx; j++)
    //get_mem3Dint( (*array4D)+j, frames, rows, columns ) ;
    get_mem3D( (*array4D)+j, frames, rows, columns ) ;

  return idx*frames*rows*columns*sizeof(byte);
}

int main()
{
    int width = 320;
    int height = 240;

    puts("-----------------------------------2D-------------------------------------------");
    byte **array2D;
    get_mem2D(&array2D, height, width);
    printf("&array2D=%p, &array2D[0]=%p, &array3D[1]=%p\n", &array2D, &array2D[0], &array2D[1]);
    printf("array2D=%p, array2D[0]=%p, array2D[1]=%p\n", array2D, array2D[0], array2D[1]);
    printf("array2D+1=%p\n", array2D+1);

    puts("-----------------------------------3D-------------------------------------------");
    byte ***array3D;
    int frms = 3;
    get_mem3D(&array3D, frms, height, width);
    printf("&array3D=%p, &array3D[0]=%p, &array3D[1]=%p, &array3D[2]=%p\n", &array3D, &array3D[0], &array3D[1], &array3D[2]);
    printf("array3D=%p, array3D[0]=%p, array3D[1]=%p, array3D[2]=%p\n", array3D, array3D[0], array3D[1], array3D[2]);
    printf("array3D[0][0]=%p, array3D[0][1]=%p, array3D[0][2]=%p, array3D[0][3]\n", array3D[0][0], array3D[0][1], array3D[0][2], array3D[0][3]);
    printf("array3D[1][0]=%p, array3D[1][1]=%p, array3D[1][2]=%p, array3D[1][3]\n", array3D[1][0], array3D[1][1], array3D[1][2], array3D[1][3]);
    printf("array3D[2][0]=%p, array3D[2][1]=%p, array3D[2][2]=%p, array3D[2][3]\n", array3D[2][0], array3D[2][1], array3D[2][2], array3D[2][3]);

    puts("-----------------------------------4D-------------------------------------------");
    byte ****array4D;
    int idx = 2;
    frms = 3;
    get_mem4D(&array4D, idx, frms, height, width);
    printf("&array4D=%p, &array4D[0]=%p, &array4D[1]=%p\n", &array4D, &array4D[0], &array4D[1]);
    printf("array4D=%p, array4D[0]=%p, array4D[1]=%p\n", array4D, array4D[0], array4D[1]);
    printf("array4D[0][0]=%p, array4D[0][1]=%p, array4D[0][2]=%p\n", array4D[0][0], array4D[0][1], array4D[0][2]);
    printf("array4D[1][0]=%p, array4D[1][1]=%p, array4D[1][2]=%p\n", array4D[1][0], array4D[1][1], array4D[1][2]);

    return 0;
}
