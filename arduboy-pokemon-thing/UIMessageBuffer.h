#pragma once

template <uint8_t BufferSize >
class UIMessageBuffer
{
private:
	static constexpr uint8_t size = BufferSize;
public:
};

using StandardMessageBuffer = UIMessageBuffer<40>;