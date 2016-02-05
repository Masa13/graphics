#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int file = open("kool_image.ppm", O_CREAT | O_WRONLY, 0777);
  int xres = 500;
  int yres = 500;
  int max_color = 255;

  char* buffer = malloc(256*sizeof(char));
  sprintf(buffer,"P3 %i %i %i", xres, yres, max_color);
  write( file, buffer, sizeof(buffer));

  int x,y, red, green, blue;
  green = 0;

  for(x = 0; x < xres; x++){
    for(y= 0; y < yres; y++){
      red = x % max_color;
      blue = y % max_color;
      
      sprintf (buffer, " %d %d %d ", red, green, blue);
      printf("%s\n", buffer);
      write (file, buffer, sizeof(buffer));
    }
  }
  return 0;
}
