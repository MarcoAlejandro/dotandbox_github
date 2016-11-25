# ifndef SKYLINE_H
# define SKYLINE_H

# include <d_tree_node.H>

class skyline
{

public:

	skyline()
	{
		decision_tree = new dotandbox_tree<4,4,4>;
	}

	~skyline()
	{

	}

private:

	dotandbox_tree<4,4,4> *decision_tree;
};

# endif