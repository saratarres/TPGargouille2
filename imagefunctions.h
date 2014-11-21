//============================================================================
//                                Structures
//============================================================================

typedef struct{
  int width;
  int height;
  unsigned char * data;

}image;

//============================================================================
//                           Function declarations
//============================================================================
// Write the image contained in <data> (of size <width> * <height>)
// into plain RGB ppm file <file>
void ppm_write_to_file(int width, int height, unsigned char* data, char * namefile);

// Read the image contained in plain RGB ppm file <file>
// into <data> and set <width> and <height> accordingly
// Warning: data is malloc_ed, don't forget to free it
void ppm_read_from_file(int *width, int *height, unsigned char** data, char * namefile);

// Desaturate (transform to B&W) <image> (of size <width> * <height>)
void ppm_desaturate(unsigned char* image, int width, int height);

// Shrink image (of original size <width> * <height>) by factor <factor>
// <width> and <height> are updated accordingly
void ppm_shrink(unsigned char** image, int *width, int *height, int factor);