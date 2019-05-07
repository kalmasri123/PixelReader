#include <Magick++.h>
#include <iostream>
#include "color.hpp"
#include "generatebmp.hpp"
#include <vector>
#include <string.h>
// #include "linkedlist.hpp"
// #include "pixelbst.hpp"

#include <stdlib.h>
#include "pixelbst.hpp"
using namespace Magick;
using namespace std;
//Third Party Libraries being Used: Magick++/ImageMagick
int main(int argc, char **argv)
{
	try
	{
		InitializeMagick(*argv);
		if (!argv[1])
		{
			cout << "Please Enter a File Path" << endl;
			return 1;
		}
		Image img(argv[1]);
		cout << img.columns();
		ColorMap pixelMap = generateBMP(img);
		getRowFreqs(pixelMap);
	}
	catch (Magick::Exception &error)
	{
		cerr << "Caught Magick++ exception: " << error.what() << endl;
	}
	return 0;
}
