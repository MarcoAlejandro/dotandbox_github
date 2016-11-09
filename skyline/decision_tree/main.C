# include <d_tree_node.H>

int main()
{
	map<3,3> map_;

	MOVE mv;

	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 1;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 1;

	map_.play(mv,1);

	get<0>(get<0>(mv)) = 1;
	get<1>(get<0>(mv)) = 1;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 0;

	map_.play(mv,1);

	get<0>(get<0>(mv)) = 1;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 0;
	get<1>(get<1>(mv)) = 0;

	map_.play(mv,1);

	map_.print_map_terminal();

	
	decision_node<3,3,3> d_t(map_,mv);

	d_t.make_decision_tree(map_,mv);

	int counter_child = 1;

	cout << "LVL1" << "\n\n";

	for (auto I = d_t.get_left_child(); I != nullptr; I = I->get_right_sibling())
	{
		cout << "CHILD [" << counter_child << "] " << "\n";

		I->get_data().get_map().print_map_terminal();
		
		counter_child ++;
	}

	cout << d_t.get_right_child()->get_data().get_map().get_p1_score() << "\n";


	counter_child = 1;

	/*counter_child = 1;
	cout << "LVL2" << "\n\n";

	for (auto I = d_t.get_left_child()->get_right_sibling()->get_left_child(); I != nullptr; I = I->get_right_sibling())
	{
		cout << "CHILD [" << counter_child << "] " << "\n";

		I->get_data().get_map().print_map_terminal();
		
		counter_child ++;
	}*/

return 0;
}