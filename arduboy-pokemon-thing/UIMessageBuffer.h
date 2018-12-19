#pragma once

template <uint8_t BufferSize >
class UIMessageBuffer
{
private:
	static constexpr uint8_t size = BufferSize;
	char buffer[size];
	uint8_t position = 0;
public:
	{
		for(uint8_t i = 0; i < size; ++i)
		{
			buffer[i] = '\0';
		}
		position = 0;
	}
	void write(const char letter)
	{
		buffer[position] = letter;
		if(position < size)
			++position;
	}
};

using StandardMessageBuffer = UIMessageBuffer<40>;