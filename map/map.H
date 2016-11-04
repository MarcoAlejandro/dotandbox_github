# ifndef MAP_H
# define MAP_H
/**

@file map.H

@brief implementation on C++ of map for game dot and boxes, map has score of two players
and a 2D vector of dots.

@author CODEMAKERS

@date 11/3/2016

*/

# include <dot.H>
# include <utility>
# include <tuple>
# include <iostream>

# define PLAYER1 1
# define PLAYER2 2
# define DOT1 boxes[get<0>(get<0>(cur_move))][get<1>(get<0>(cur_move))]
# define DOT2 boxes[get<0>(get<1>(cur_move))][get<1>(get<1>(cur_move))]
# define MOVE tuple<pair<size_t,size_t>,pair<size_t,size_t> >

using namespace std;

template<size_t R = 4, size_t C = 4> class map
{

private:

	typedef tuple<pair<size_t,size_t>,pair<size_t,size_t> > move;
	size_t p1_score, p2_score;
	dot<R,C>* boxes[R][C];

public:

	/**
		@brief constructor of class map.
	*/
	map() : p1_score(0), p2_score(0)
	{
		for (size_t i = 0; i < R ; ++i)
			for (size_t j = 0; j < C; ++j)
				boxes[i][j] = new dot<R,C>(pair<size_t,size_t>(i,j));
	}

	~map()
	{
		for (size_t i = 0; i < R ; ++i)
			for (size_t j = 0; j < C; ++j)
				delete boxes[i][j];
	}

	/**
		@brief to see player one score.
		@return player one score.
	*/
	size_t get_p1_score()
	{
		return p1_score;
	}

	/**
		@brief to see player two score.
		@return player two score.
	*/
	size_t get_p2_score()
	{
		return p2_score;
	}

	/**
		@brief If "p1_score + p2_score" is equal to "9" every single
		box is set.
		@return bool telling if map is full.
	*/
	bool is_full()
	{
		return p1_score + p2_score == (R - 1)*(C - 1);
	}

	unsigned short play_(dot<R,C>* dot_1,dot<R,C>* dot_2)
	{
		if (dot_1->is_full())
			return 0;

		if (dot_2->is_full())
			return 0;

		if (*dot_1 == *dot_2)
			return 0;

		//dot_2 is left side
		if (get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 0 and 
			get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 1)
		{
			if (dot_1->is_ul_corner() or dot_1->is_l_border() or dot_1->has_left())
				return 0;

			dot_1->mark_left();
			dot_2->mark_right();
			return 1;
		}

		//dot_2 is right side
		if (get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 0 and 
			get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == -1)
		{
			if (dot_1->is_ur_corner() or dot_1->is_r_border() or dot_1->has_right())
				return 0;

			dot_1->mark_right();
			dot_2->mark_left();
			return 2;
		}

		//dot_2 is down side
		if ( get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == -1 and
			 get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 0)
		{
			if (dot_1->is_dl_corner() or dot_1->is_dr_corner() or 
				dot_1->is_d_border() or dot_1->has_down())
				return 0;

			dot_1->mark_down();
			dot_2->mark_up();
			return 3;
		}

		//dot_2 is up side
		if ( get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 1 and
			 get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 0)
		{
			if (dot_1->is_ul_corner() or dot_1->is_ur_corner() or 
				dot_1->is_u_border() or dot_1->has_up())
				return 0;

			dot_1->mark_up();
			dot_2->mark_down();
			return 4;
		}
		else
			return 0;
		//dot_2 is off side;
	}

	bool check_box(dot<R,C>* dot_1, unsigned short player)
	{

		if (dot_1->is_ul_corner())
		{

			if(not dot_1->has_right() or not dot_1->has_down())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if (dot_1->is_ur_corner())
		{
			if(not dot_1->has_left() or not dot_1->has_down())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if (dot_1->is_dr_corner())
		{

			if(not dot_1->has_left() or not dot_1->has_up())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}
		
		if (dot_1->is_dl_corner())
		{
			if(not dot_1->has_right() or not dot_1->has_up())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if(dot_1->is_u_border())
		{
			if(not dot_1->has_right() or not dot_1->has_left())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if(dot_1->is_d_border())
		{
			if(not dot_1->has_right() or not dot_1->has_left())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if(dot_1->is_l_border())
		{
			if(not dot_1->has_up() or not dot_1->has_down())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_left())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}

		if(dot_1->is_r_border())
		{
			if(not dot_1->has_up() or not dot_1->has_down())
				return false;

			if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_down() and
				boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_up() and
				boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_right())
			{
				switch(player)
				{
					case PLAYER1:

						p1_score ++;
						break;
					case PLAYER2:

						p2_score ++;
						break;
				}

				return true;
			}

			return false;
		}


		if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_down() and
			boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) - 1]->has_right())
		{
			switch(player)
			{
				case PLAYER1:

					p1_score ++;
					break;
				case PLAYER2:

					p2_score ++;
					break;
			}

			return true;
		}

		if (boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_down() and
			boxes[get<0>(dot_1->get_pos()) - 1][get<1>(dot_1->get_pos()) + 1]->has_left())
		{
			switch(player)
			{
				case PLAYER1:

					p1_score ++;
					break;
				case PLAYER2:

					p2_score ++;
					break;
			}

			return true;
		}

		if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_up() and
			boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) + 1]->has_left())
		{
			switch(player)
			{
				case PLAYER1:

					p1_score ++;
					break;
				case PLAYER2:

					p2_score ++;
					break;
			}

			return true;
		}

		if (boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_up() and
			boxes[get<0>(dot_1->get_pos()) + 1][get<1>(dot_1->get_pos()) - 1]->has_right())
		{
			switch(player)
			{
				case PLAYER1:

					p1_score ++;
					break;
				case PLAYER2:

					p2_score ++;
					break;
			}

			return true;
		}

		return false;
	}

	bool play(move cur_move, unsigned short player)
	{
		if (  get<0>(get<0>(cur_move)) >= R or get<0>(get<1>(cur_move)) >= C or 
		 	  get<1>(get<0>(cur_move)) >= R or get<1>(get<1>(cur_move)) >= C   ) 
			throw out_of_range("move out of range");

		if (play_(DOT1,DOT2) and not is_full())
		{
			check_box(DOT1,player);
			return true;
		}
		else
			return false;
	}

};

#endif 