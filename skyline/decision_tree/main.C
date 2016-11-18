# include <d_tree_node.H>

int main()
{
	
	map<2,2> map_;
	MOVE mv;

	dotandbox_tree<2,2,3> * d_t = new dotandbox_tree<2,2,3>(map_,mv);

	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 0;
	get<1>(get<1>(mv)) = 1;

	map_.play(mv,2);


	d_t->make_decision_tree(map_,mv,2);

	for (size_t i = 0; i < 3 ; ++i)
	{
		cout << "---utility: " <<d_t->get_root()->get_children()[i].get_utility() << endl;
	}

	d_t->reset_tree();

	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 1;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 1;

	map_.play(mv,1);


	d_t->make_decision_tree(map_,mv,1);
	
	for (size_t i = 0; i < 2 ; ++i)
	{
		cout << "utility: " <<d_t->get_root()->get_children()[i].get_utility() << endl;
	}

	d_t->reset_tree();


	get<0>(get<0>(mv)) = 1;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 1;

	map_.play(mv,2);

	d_t->make_decision_tree(map_,mv,2);

	mv = d_t->get_next_move();
	cout << "(" << get<0>(get<0>(mv)) << "," << get<1>(get<0>(mv)) << ") - (" << get<0>(get<1>(mv)) << "," << get<1>(get<1>(mv)) << ")" << endl;
	/*cout << "\n";
	d_t.get_root()->get_map().print_map_terminal();
	cout << "\n\n";

	auto lvl = d_t.get_root()->get_children();

	int counter_child = 1;

	cout << "LVL3" << "\n\n";

	for (int i = 0; i < 3; ++i)
	{
		cout << "CHILD [" << counter_child << "] " << "\n";

		lvl[i].get_map().print_map_terminal();
		
		counter_child ++;
	}*/

	/*d_t.reset_tree();

	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 0;

	map_.play(mv,1);

	d_t.make_decision_tree(map_,mv);*/

	//cout << (d_t.get_root()->get_children() == nullptr);

	/*d_t.make_decision_tree(map_,mv);

	d_t.reset_tree();*/


	/*cout << "\n";
	d_t.get_root()->get_map().print_map_terminal();
	cout << "\n\n";

	auto lvl = d_t.get_root()->get_children();

	int counter_child = 1;

	cout << "LVL3" << "\n\n";

	for (int i = 0; i < 10; ++i)
	{
		cout << "CHILD [" << counter_child << "] " << "\n";

		lvl[i].get_map().print_map_terminal();
		
		counter_child ++;
	}*/

return 0;
}