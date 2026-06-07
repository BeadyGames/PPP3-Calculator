#include <iostream>

int main()
{
	double val = 0;
	double val2 = 0;
	char op = ' ';
	std::cout << "Enter an expression (e.g., 3 + 4): ";

	std::cin >> val; // Read initial value

	while (std::cin >> op)
	{
		switch (op)
		{
		case '+':
			std::cin >> val2;
			val += val2;
			break;
		case '-':
			std::cin >> val2;
			val -= val2;
			break;
		case '*':
			std::cin >> val2;
			val *= val2;
			break;
		case '/':
			std::cin >> val2;
			if (val2 != 0)
				val /= val2;
			else
				std::cout << "Error: Division by zero!" << '\n';
			break;
		case '=':
			std::cout << "Result: " << val << '\n';
			val = 0; // Reset for the next expression
			std::cout << "Enter an expression (e.g., 3 + 4): ";
			std::cin >> val; // Read initial value for the next expression
			break;
		}
	}
}