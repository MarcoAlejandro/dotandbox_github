# include <map.H>
# include <tuple>
# include <iostream>

using namespace std;

int main()
{
	map<3,3> map_;

	MOVE mv;
	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 1;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 1;

	if(map_.play(mv,1))
		cout << "valid move" << "\n";
	else
		cout << "invalid move" << "\n";

	get<0>(get<0>(mv)) = 1;
	get<1>(get<0>(mv)) = 1;

	get<0>(get<1>(mv)) = 1;
	get<1>(get<1>(mv)) = 0;

	if(map_.play(mv,1))
		cout << "valid move" << "\n";
	else
		cout << "invalid move" << "\n";

	get<0>(get<0>(mv)) = 1;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 0;
	get<1>(get<1>(mv)) = 0;

	if(map_.play(mv,1))
		cout << "valid move" << "\n";
	else
		cout << "invalid move" << "\n";



	get<0>(get<0>(mv)) = 0;
	get<1>(get<0>(mv)) = 0;

	get<0>(get<1>(mv)) = 0;
	get<1>(get<1>(mv)) = 1;

	if(map_.play(mv,1))
		cout << "valid move" << "\n";
	else
		cout << "invalid move" << "\n";



	cout << "score player 1: " << map_.get_p1_score() << "\n";



}