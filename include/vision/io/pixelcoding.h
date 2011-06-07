#ifndef VL_COLOR_H
#define VL_COLOR_H


#define MONO    -1
#define RGB	-2

namespace vision {

template< typename Pix, int ColorCoding >
double pixel2mono ( Pix value ) ;

template< typename Pix, int ColorCoding >
Pix mono2pixel ( double value ) ;

template< typename Pix, int ColorCoding >
void pixel2rgb ( Pix value, double &red, double &green, double &blue ) ;

template< typename Pix, int ColorCoding >
Pix rgb2pixel ( double red, double green, double blue ) ;

}

#endif
