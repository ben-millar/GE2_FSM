#ifndef INPUT_EVENT_H
#define INPUT_EVENT_H

enum class InputID
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	JUMP,
	EXIT
};

enum class InputType
{
	NONE,
	PRESSED,
	RELEASED
};

struct InputEvent
{
	InputID ID;
	InputType type;

	/// <summary>
	/// Default c'tor
	/// </summary>
	InputEvent() :
		ID{InputID::NONE},
		type(InputType::NONE) {}

	/// <summary>
	/// Default d'tor
	/// </summary>
	~InputEvent() = default;

	/// <summary>
	/// @brief Overloaded c'tor
	/// </summary>
	/// <param name="t_type">Type of event</param>
	InputEvent(InputID t_ID, InputType t_type) :
		ID{ t_ID },
		type{ t_type }
	{};
};

#endif // !INPUT_EVENT_H