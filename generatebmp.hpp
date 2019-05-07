#include <Magick++.h>
using namespace Magick;
#include <iostream>
using namespace std;
#include <vector>
// #include "color.hpp"
ColorMap generateBMP(Image img)
{
	int rows = img.rows();
	int columns = img.columns();
	ColorMap pixelArray;
	for (int y = 0; y < rows; y++)
	{
		Row color;
		for (int x = 0; x < columns; x++)
		{
			ColorRGB rgb(img.pixelColor(x, y));

			ImgColor pixel = {rgb.red() * 255, rgb.blue() * 255, rgb.green() * 255};
			color.push_back(pixel);
		}
		pixelArray.push_back(color);
	}
	cout << pixelArray.size() << "\t" << pixelArray[0].size() << endl;
	
	return pixelArray;
}
