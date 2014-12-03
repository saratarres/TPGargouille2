class Image{

//============================================================================
//                                Structures
//============================================================================

private:
  int width;
  int height;
  unsigned char * data;

public:

//============================================================================
//                                Getters
//============================================================================	

int get_Width(void) const {
	return width;
}

int get_Height(void) const{
	return height;
}

unsigned char* get_Data(void) const {
	return data;
}

//============================================================================
//                         Constructors & Destructors
//============================================================================

Image(void){
	width = 0;
	height = 0;
	data =  new unsigned char[1];
}

//Set a copy constructor to write de new modified image without modifing the original one:
//We set original_img as a constant cause we don't want it to be modified by error
Image(const Image& original_img);

~Image(void){
	delete [] data;
}

//============================================================================
//                           Function declarations
//============================================================================
// Write the image contained in <data> (of size <width> * <height>)
// into plain RGB ppm file <file>
void ppm_write_to_file(char * namefile);

// Read the image contained in plain RGB ppm file <file>
// into <data> and set <width> and <height> accordingly
// Warning: data is malloc_ed, don't forget to free it
void ppm_read_from_file(char * namefile);

// Desaturate (transform to B&W) <image> (of size <width> * <height>)
void ppm_desaturate();

// Shrink image (of original size <width> * <height>) by factor <factor>
// <width> and <height> are updated accordingly
void ppm_shrink(int factor);

};