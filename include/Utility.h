template <class T>
static T range(T input, T min, T max)
{
	return input > max ? max : input < min ? min : input;
}
