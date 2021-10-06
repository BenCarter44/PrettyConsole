#include "styles.h"

Style::Style()
{
	reset = true;
	textColor = StyleAttribute();
	textWeight = StyleAttribute();
	backgroundColor = StyleAttribute();
}

char* Style::getASCII()
{
	char framer[] = "\033[";
	int frameLen = 2;
	char* out;
	if (reset)
	{
		out = new char[frameLen + 1];

	}
	for (int x = 0; x < frameLen; x++)
	{
		if (x < 3)
		{
			out[x] = framer[x];
		}

		

	}

}