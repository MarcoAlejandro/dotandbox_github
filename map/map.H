# ifndef MAP_H
# define MAP_H

# include <dot.H>
# include <utility>
# include <tuple>
# include <iostream>
/**
 *@file map.H
 *
 *@brief implementation on C++ of map for game dot and boxes, map 
	 has score of two players and a matrix that saves dots.
	 Logic of game is implemented  here, with this first version
	 users can play one aganist each others.
*
*@author CodeMakers.
*@version 1.0.
*@date 11/3/2016
*/

/**
 *@brief macros to have a better code readability.
   PLAYER1 = represents first player in the game.
   PLAYER2 = represents first player in the game.
   DOT1 = represents first dot into a move.
   DOT2 = represents second dot into a move.
*/
# define PLAYER1 1
# define PLAYER2 2
# define DOT1 boxes[get<0>(get<0>(cur_move))][get<1>(get<0>(cur_move))]
# define DOT2 boxes[get<0>(get<1>(cur_move))][get<1>(get<1>(cur_move))]
# define MOVE tuple<pair<size_t,size_t>,pair<size_t,size_t> >

using namespace std;

/**
 *@brief map class
 *
 *map class is a template. 
 *@param R is the number of rows of matrix.
 *@param C is the number of columns of matrix.
 */
template<size_t R = 4, size_t C = 4> class map
{

private:

	typedef tuple<pair<size_t,size_t>,pair<size_t,size_t> > move;
	size_t p1_score, p2_score;
	dot<R,C>* boxes[R][C];

public:

	/**
	 *@brief constructor of class map, sets entire map by giving memory 
		to every single dot into the map and seting scores with 0.
	*/
	map() : p1_score(0), p2_score(0)
	{
		for (size_t i = 0; i < R ; ++i)
			for (size_t j = 0; j < C; ++j)
				boxes[i][j] = new dot<R,C>(pair<size_t,size_t>(i,j));
	}

	/**
	 *@brief destructor of class map, unsets entire map by deleting memory 
		of every single dot into the map.
	*/
	~map()
	{
		for (size_t i = 0; i < R ; ++i)
			for (size_t j = 0; j < C; ++j)
				delete boxes[i][j];
	}

	/**
	 *@brief gives player one score.
	 *@return player one score.
	*/
	size_t get_p1_score()
	{
		return p1_score;
	}

	/**
	 *@brief gives player two score.
	 *@return player two score.
	*/
	size_t get_p2_score()
	{
		return p2_score;
	}

	/**
	 *@brief tells if map was completly full by checking if 
	  "p1_score + p2_score" is equal to maximiun number of boxes.
	 *@return bool telling if map is full.
	*/
	bool is_full()
	{
		return p1_score + p2_score == (R - 1)*(C - 1);
	}

	/**
	 *@brief allows player to make a move.
	   if move was correct then
	   function sets necessary flags to represent move on the map.
	   function evalutes if both dots are in range by checking their
	   positions, therefore if dots are in range function sets the move. 
	 *
	 *@return bool telling if move could be set or not.
	*/
	bool play_(dot<R,C>* dot_1,dot<R,C>* dot_2)
	{
		if (dot_1->is_full())
			return false;

		if (dot_2->is_full())
			return false;

		if (*dot_1 == *dot_2)
			return false;

		//dot_2 is left side
		if (get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 0 and 
			get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 1)
		{
			if (dot_1->is_ul_corner() or dot_1->is_l_border() or dot_1->has_left())
				return false;

			dot_1->mark_left();
			dot_2->mark_right();
			return true;
		}

		//dot_2 is right side
		if (get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 0 and 
			get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == -1)
		{
			if (dot_1->is_ur_corner() or dot_1->is_r_border() or dot_1->has_right())
				return false;

			dot_1->mark_right();
			dot_2->mark_left();
			return true;
		}

		//dot_2 is down side
		if ( get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == -1 and
			 get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 0)
		{
			if (dot_1->is_dl_corner() or dot_1->is_dr_corner() or 
				dot_1->is_d_border() or dot_1->has_down())
				return false;

			dot_1->mark_down();
			dot_2->mark_up();
			return true;
		}

		//dot_2 is up side
		if ( get<0>(dot_1->get_pos()) - get<0>(dot_2->get_pos()) == 1 and
			 get<1>(dot_1->get_pos()) - get<1>(dot_2->get_pos()) == 0)
		{
			if (dot_1->is_ul_corner() or dot_1->is_ur_corner() or 
				dot_1->is_u_border() or dot_1->has_up())
				return false;

			dot_1->mark_up();
			dot_2->mark_down();
			return true;
		}
		else
			return false;
		//dot_2 is off side;
	}

	/**
	 *@brief gives point to player.
	   if player enclose a box function gives point to him.
	   function check if dot where move were done is a corner, border or
	   a simple dot, therefore function has to make necessary considerations. 
	 *
	 *@return bool telling if player gets point.
	*/
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

	/**
	 *@brief makes sure move is into range and also works as interface of 
	 	function play_, first evaluates if move can be done and then gives point
	 	to player by calling function "check_box". 
	 *
	 *@return bool telling if move could be set or not.
	*/
	bool play(move cur_move, unsigned short player)
	{

		if(player != PLAYER1 and player != PLAYER2 )
			throw out_of_range("player out of range");
			
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