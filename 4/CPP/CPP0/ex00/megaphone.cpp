
#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i][j];
		}
	}
	std::cout << "\n";
	return (0);
}