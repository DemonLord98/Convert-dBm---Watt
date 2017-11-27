#pragma once
class Handler
{
public:
	Handler();

	int ConvertType();
	void GetValue();
	void Converter();
	void PrintOut();
	bool Repeat();
	void Outro();

	~Handler();

private:
	int choice = 0;
	double X = 0, Power = 0;
	std::string response = "";
};

