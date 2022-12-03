#include <string>
#include <iostream>
#include "styles.h"


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
	reset = cp.reset;
	if (cp.textColor.isArrOK())
	{
		textColor.init(cp.textColor.getValueArr(),3);
	}
	if (cp.textWeight.isSet())
	{
		textWeight.init(cp.textWeight.getValue());
	}
	if (cp.backgroundColor.isArrOK())
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
MyString Style::getASCII() const
{
	MyString start = "\033[";
	if (reset)
	{
		start = start + "0;";
	}
	
	if (textWeight.isSet()) // bold, italic, or underline, or both
	{
		int val = textWeight.getValue();
		if (val % 2 == 0) // if even, it is bold
		{
			start = start + "1;";
		}
		else
		{
			start = start + "22;";
		}
		if (val % 7 == 0) // italic
		{
			start = start + "3;";
		}
		else
		{
			start = start + "23;";
		}
		if (val % 3 == 0) // underline
		{
			start = start + "4;";
		}
		else
		{
			start = start + "24;";
		}
	}
	if (isBlink.isSet())
	{
		if (isBlink.getValue() == 1)
		{
			start = start + "5;";
		}
		else if (isBlink.getValue() == 2)
		{
			start = start + "6;";
		}
		else if (isBlink.getValue() == 0)
		{
			start = start + "25;";
		}

	}
	if (border.isSet())
	{
		if (border.getValue() == 1)
		{
			start = start + "51;";
		}
		else if (border.getValue() == 2)
		{
			start = start + "52;";
		}
		else
		{
			start = start + "54;";
		}
	}
	if (textColor.isArrOK())
	{
		
		int r = textColor.getValueArr()[0];
		int g = textColor.getValueArr()[1];
		int b = textColor.getValueArr()[2];
		/*cout << r << " " << g << " " << b << '\n';*/
		start = start + "38;2;" + std::to_string(r).c_str() + ";" + std::to_string(g).c_str() + ";" + std::to_string(b).c_str() + ";";
	}
	if (backgroundColor.isArrOK())
	{
		int r = backgroundColor.getValueArr()[0];
		int g = backgroundColor.getValueArr()[1];
		int b = backgroundColor.getValueArr()[2];
		start = start + "48;2;" + std::to_string(r).c_str() + ";" + std::to_string(g).c_str() + ";" + std::to_string(b).c_str() + ";";
	}
	start = start.substring(0, start.length() - 1) + "m";
	//cout << start << '\n';
	return start;

}
void Style::setTextColor(int r, int g, int b)
{
	reset = false;
	int dat[] = { r,g,b };
	textColor.init(dat, 3);
}

void Style::setTextColor(int set)
{
	reset = false;
	if (set > -1 && set < 16)
	{
		/*for (int x = 0; x < 3; x++)
		{
			cout << defaultColors[set].getValueArr()[x] << endl;
		}*/
		textColor.init(defaultColors[set],3);
	}
	
}
void Style::setBackgroundColor(int r, int g, int b)
{
	reset = false;
	int dat[] = { r,g,b };
	backgroundColor.init(dat, 3);
}
void Style::setBackgroundColor(int set)
{
	//cout << set;
	reset = false;
	if (set > -1 && set < 16)
	{
		backgroundColor.init(defaultColors[set],3);
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
bool Style::isEqual(const Style& cp)
{
	return cp.getASCII() == getASCII();

}
void Style::mergeStyles(const Style& cp)
{
	if (!cp.reset)
	{
		if (cp.textColor.isArrOK())
		{
			textColor.init(cp.textColor.getValueArr(), 3);
		}
		if (cp.textWeight.isSet())
		{
			textWeight.init(cp.textWeight.getValue());
		}
		if (cp.backgroundColor.isArrOK())
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
	

}