#include <string>
#include <iostream>
#include "styles.h"

using namespace std;

void Style::init()
{
	reset = true;
	textColor.init();
	//	cout << "APPLE!\n";
	// 
	textWeight.init();
	//	cout << "apple2!\n";
	backgroundColor.init();
	//cout << "apple3!\n";
	isBlink.init();
	//cout << "apple6!\n";
	border.init();
}

Style::Style()
{
	reset = true;

	
	textColor.init();
//	cout << "APPLE!\n";
// 
	textWeight.init();
//	cout << "apple2!\n";
	backgroundColor.init();
	//cout << "apple3!\n";
	isBlink.init();
	//cout << "apple6!\n";
	border.init();
	//cout << "HERE!\n";
	int dat[16][3] =
	{

		{1,1,1},
		{187, 0, 0},
		{0, 187, 0},
		{187, 187, 0},
		{0, 0, 187},
		{187, 0, 187},
		{0, 187, 187},
		{187, 187, 187},
		{85, 85, 85},
		{255, 85, 85},
		{85, 255, 85},
		{255, 255, 85},
		{85, 85, 255},
		{255, 85, 255},
		{85, 255, 255},
		{255, 255, 255}
	};
	 // putty constants
	for (int i = 0; i < 16; i++)
	{
		defaultColors[i].init(dat[i], 3);
	}
	
}
void Style::init(const Style& cp)
{
	reset = cp.reset;
	if (cp.textColor.isSet())
	{
		textColor.init(cp.textColor.getValue());
	}
	if (cp.textWeight.isSet())
	{
		textWeight.init(cp.textWeight.getValue());
	}
	if (cp.backgroundColor.isSet())
	{
		backgroundColor.init(cp.backgroundColor.getValueArr(), 3);
	}
	if (cp.isBlink.isSet())
	{
		isBlink.init(cp.isBlink.getValue());
	}
	if (cp.border.isSet())
	{
		border.init(cp.border.getValue());
	}
	

}
Style::Style(const Style& cp)
{
	init(cp);
}
string Style::getASCII()
{
	string start = "\\033[";
	if (reset)
	{
		start += "0;";
	}
	
	if (textWeight.isSet()) // bold, italic, or underline, or both
	{
		int val = textWeight.getValue();
		if (val % 2 == 0) // if even, it is bold
		{
			start += "1;";
		}
		else
		{
			start += "22;";
		}
		if (val % 7 == 0) // italic
		{
			start += "3;";
		}
		else
		{
			start += "23;";
		}
		if (val % 3 == 0) // underline
		{
			start += "4;";
		}
		else
		{
			start += "24;";
		}
	}
	if (isBlink.isSet())
	{
		if (isBlink.getValue() == 1)
		{
			start += "5;";
		}
		else if (isBlink.getValue() == 2)
		{
			start += "6;";
		}
		else if (isBlink.getValue() == 0)
		{
			start += "25;";
		}

	}
	if (border.isSet())
	{
		if (border.getValue() == 1)
		{
			start += "51;";
		}
		else if (border.getValue() == 2)
		{
			start += "52;";
		}
		else
		{
			start += "54;";
		}
	}
	if (textColor.isSet())
	{
		int r = textColor.getValueArr()[0];
		int g = textColor.getValueArr()[1];
		int b = textColor.getValueArr()[2];
		start += "38;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + ";";
	}
	if (backgroundColor.isSet())
	{
		int r = backgroundColor.getValueArr()[0];
		int g = backgroundColor.getValueArr()[1];
		int b = backgroundColor.getValueArr()[2];
		start += "48;2;" + to_string(r) + ";" + to_string(g) + ";" + to_string(b) + ";";
	}
	start = start.substr(0, start.length() - 1) + "m";
	//cout << start << '\n';
	return start;

}
void Style::setTextColor(int r, int g, int b)
{
	reset = false;
	int dat[] = { r,g,b };
	textColor.setArr(dat, 3);
}

void Style::setTextColor(int set)
{
	reset = false;
	if (set > -1 && set < 16)
	{
		textColor = defaultColors[set];
	}
	
}
void Style::setBackgroundColor(int r, int g, int b)
{
	reset = false;
	int dat[] = { r,g,b };
	backgroundColor.setArr(dat, 3);
}
void Style::setBackgroundColor(int set)
{
	reset = false;
	if (set > -1 && set < 16)
	{
		backgroundColor = defaultColors[set];
	}

}
void Style::turnOnBlink()
{
	reset = false;
	isBlink.setValue(1);
}
void Style::turnOffBlink()
{
	reset = false;
	isBlink.setValue(0);
}
void Style::turnOnFastBlink()
{
	reset = false;
	isBlink.setValue(2);
}
void Style::setBorderBox()
{
	reset = false;
	border.setValue(1);
}
void Style::setBorderCircle()
{
	reset = false;
	border.setValue(2);
}
void Style::noBorder()
{
	reset = false;
	border.setValue(0);
}
bool Style::isEqual(Style& cp)
{
	return cp.getASCII() == getASCII();

}