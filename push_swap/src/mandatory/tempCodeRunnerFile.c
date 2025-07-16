int	main(int argc, char **argv)
// {
// 	t_stack	*stack;
// 	int		i;

// 	stack = NULL;
// 	if (argc < 2)
// 	{
// 		printf("Usage: %s <numbers>\n", argv[0]);
// 		return (1);
// 	}
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!is_number(argv[i]))
// 		{
// 			printf("Error: Argument '%s' is not a valid number\n", argv[i]);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	stack = fill_stack(&argv[1]);
// 	sort(&stack);
// 	// print_stack(stack);
// 	free_stack(stack);
// 	return (0);
// }