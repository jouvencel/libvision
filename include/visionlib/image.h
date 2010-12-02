#ifndef VISIONLIB_IMAGE_H
#define VISIONLIB_IMAGE_H

#include <stdlib.h>
#include <visionlib/imageref.h>

#include <iostream>

template < typename Pix > class Image
{

public:

  Image ( ImageRef imgref ) ;
  Image ( int width, int height);
  ~Image ();

  unsigned int get_width ()
  {
    return width;
  }
  unsigned int get_height ()
  {
    return height;
  }
  ImageRef get_size ()
  {
    return ImageRef (width, height);
  }

  Pix* get_raw_data()
  {
   return data ;
  }

  Pix& operator[] ( ImageRef coord )
  {
        return data[coord.x + coord.y * width] ;
  }

  Pix* scale(unsigned int scale_factor) ;


private:

  int width;
  int height;
  int num_pixels;	// width * height
  Pix *data;


};



template<typename Pix> 
Image<Pix>::Image (int w, int h)
{
  width = w;
  height = h;
  num_pixels = w * h;
  data = (Pix *) malloc ( num_pixels * sizeof (Pix) );
  if (data == NULL)
    throw "malloc error" ;

}

template<typename Pix>
Image<Pix>::Image( ImageRef ir ) {
	 width = ir.x;
	 height = ir.y;
	 num_pixels = ir.x * ir.y;
	 data = (Pix *) malloc ( num_pixels * sizeof (Pix) );
	 if (data == NULL)
		throw "malloc error" ;
}

template < typename Pix >
Image<Pix>::~Image ()
{
  free (data);
}

template< typename Pix >							
Pix* Image<Pix>::scale(unsigned int scale_factor) {
    if(width % scale_factor != 0 || height % scale_factor != 0) { return 0; }
	Pix* buff ;
    buff = new Pix[num_pixels / (scale_factor*scale_factor) * sizeof(Pix)];
	for (int i=0; i<width; i+=scale_factor ) {
	for (int j=0; j<height; j+=scale_factor ) {
		int acc =0 ;
		for (int k=0; k<scale_factor; k++ ) { 
		for (int l=0; l<scale_factor; l++ ) {
			acc += (int) data[i+k+(j+l)*width] ;
        }
        }	

		acc /= (scale_factor*scale_factor) ;

		buff[i/scale_factor+width/scale_factor * j/scale_factor] = (Pix) acc ;
	}
    }

	return buff ;
}
#endif
