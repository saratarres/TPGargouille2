
#include "imagefunctions.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{

  // Struct declaration:
  image * gargouille;
  gargouille=(image *)malloc(sizeof(image));
  gargouille->width = 0;
  gargouille->height = 0;
  gargouille->data=NULL;

  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
  
  
  char * namefile="gargouille.ppm";
  ppm_read_from_file(&(gargouille->width), &(gargouille->height), &(gargouille->data), namefile);
  


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw
  int width_bw  = gargouille->width;
  int height_bw = gargouille->height;
  unsigned char* image_bw = (unsigned char*) malloc(3 *(gargouille->width) *(gargouille->height) * sizeof(*image_bw));
  memcpy(image_bw, (gargouille->data), 3 *(gargouille->width) *(gargouille->height) * sizeof(*image_bw));

  // Desaturate image_bw
  ppm_desaturate(image_bw, gargouille->width, (gargouille->height));

  // Write the desaturated image into "gargouille_BW.ppm"
  char * BW_image = "gargouille_BW.ppm";

  ppm_write_to_file(gargouille->width, (gargouille->height), image_bw, BW_image);
  

  // Free the desaturated image
  free(image_bw);


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  int width_small  = gargouille->width;
  int height_small = (gargouille->height);
  unsigned char* image_small = (unsigned char*) malloc(3 * width_small * height_small * sizeof(*image_small));
  memcpy(image_small, (gargouille->data), 3 * width_small * height_small * sizeof(*image_small));

  // Shrink image_small size 2-fold
  ppm_shrink(&image_small, &width_small, &height_small, 2);

  // Write the desaturated image into "gargouille_small.ppm"
  
  char * small_image="gargouille_small.ppm";
  ppm_write_to_file(width_small, height_small, image_small, small_image);
  

  // Free the not yet freed images
  free(image_small);
  free(gargouille);

  return 0;
}






