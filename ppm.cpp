
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

  // class Image declaration:
 Image new_image;


  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------
  
  
  new_image.ppm_read_from_file("gargouille.ppm");
  


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read (actually 
  //it's no longer here car we've made a copy constructor) and write it into
  // "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
 
  Image new_desaturated_image = Image(new_image);

  // Desaturate image_desaturated
  new_desaturated_image.ppm_desaturate();

  // Write the desaturated image into "gargouille_BW.ppm"

  new_desaturated_image.ppm_write_to_file("gargouille_BW.ppm");
  


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  Image new_small_image = Image(new_image);

  // Shrink image_small size 2-fold
  new_small_image.ppm_shrink(2);

  // Write the desaturated image into "gargouille_small.ppm"
  
 
  new_small_image.ppm_write_to_file( "gargouille_small.ppm");
  

  return 0;
}






