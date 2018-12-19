#pragma once

template <uint8_t BufferSize >
class UIMessageBuffer
{
private:
	static constexpr uint8_t size = BufferSize;
	char buffer[size];
	uint8_t position = 0;
public:
	void clear()
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
	char * string() const
	{
		return buffer;
	}
	bool isEmpty() const
	{
		return (position == 0);
	}
	
	uint8_t capacity() const
	{
		return size;
	}
	uint8_t length() const
	{
		return position;
	}
	char getChar(uint8_t index) const
	{
		return buffer[index];
	}
	
	char operator[](const uint8_t index) const
	{
		return getChar(index);
	}
};

using StandardMessageBuffer = UIMessageBuffer<40>;