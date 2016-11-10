# include <map.H>

#include <iostream>
# define POS pair<size_t,size_t>

template <size_t R = 4, size_t C = 4> 
class move_bucket
{

private:

	MOVE actual_move;
	map<R,C> actual_map;
	long utility  = 0;
	move_bucket<R,C> * children;

public:
	
	move_bucket() : actual_move(), actual_map(), children(nullptr) 
	{
		/*empty*/
	}

	move_bucket(const map<R,C> & new_map, const MOVE & new_move,
				move_bucket<R,C> *children_)
	{
		actual_move = new_move;
		actual_map = new_map;
		children = children_;
	}

	~move_bucket(){/*empty*/}

	void set_bucket(const map<R,C> & new_map, const MOVE & new_move,
					move_bucket<R,C> *children_)
	{
		actual_move = new_move;
		actual_map = new_map;
		children = children_;
		return;
	}

	const move_bucket & operator = (const move_bucket & bucket)
	{
		set_bucket(bucket.actual_map,bucket.actual_move,bucket.children);

	}

	MOVE & get_move() 
	{
		return actual_move;
	}

	map<R,C> & get_map()
	{
		return actual_map;
	}

	void set_move(const MOVE &move_)
	{
		actual_move = move_;
		return;
	}

	void set_map(const map<R,C> &map_)
	{
		actual_map = map_;
		return;
	}

	long get_utility()
	{
		return utility;
	}

	void set_utility(const long & utility_)
	{
		utility = utility_;
		return;
	}

	move_bucket<R,C> *& get_children()
	{
		return children;
	}

	void reset()
	{
		actual_map.reset();
		get<0>(get<0>(actual_move)) = 0;
		get<1>(get<0>(actual_move)) = 0;
		get<0>(get<1>(actual_move)) = 0;
		get<1>(get<1>(actual_move)) = 0;
		children = nullptr;
	}

};

template <size_t R = 4, size_t C = 4, size_t lvl = 3> 
class dotandbox_tree
{

private:

	move_bucket<R,C> * root;
	size_t a_moves;

public:

	dotandbox_tree() : a_moves(2 * (C - 1) * C), root(nullptr){/*empty*/}

	dotandbox_tree(const map<R,C> & new_map, const MOVE & new_move)
	{
		root = new move_bucket<R,C>(new_map,new_move,nullptr);
		a_moves = 2 * (C - 1) * C;
		return;
	}

	~dotandbox_tree(){/*empty*/}

	void reset(move_bucket<R,C> *root_,size_t a_moves_)
	{
		if (root_->get_children() == nullptr)
			return;

		for (size_t i = 0; i < a_moves_; ++i)
		{
			reset(&root_->get_children()[i],a_moves_ - 1);
			delete [] root_->get_children()[i].get_children();
		}
	
		return;
	}

	void reset_tree()
	{
		reset(root,a_moves);
		root->reset();
		return;
	}

	void set(const map<R,C> & new_map, const MOVE & new_move)
	{
		root->set_bucket(new_map,new_move,nullptr);
		a_moves -= 1;
		return;
	}

	move_bucket<R,C> *& get_root()
	{
		return root;
	}

	move_bucket<R,C> * gen_children(const map<R,C> & new_map, unsigned short 
									player, size_t a_moves_)
	{
		move_bucket<R,C> * children_ = new move_bucket<R,C>[a_moves_];
		size_t pos = 0;
		MOVE mv;
		POS pos_aux;
		get<0>(pos_aux) = 0;
		get<1>(pos_aux) = 0;

		for (size_t i = 0; i < R; ++i)
		{	
			for (size_t j = 1; j < C; ++j)
			{
				
				if (i != 0)
				{
					get<0>(get<0>(mv)) = get<0>(pos_aux);
					get<1>(get<0>(mv)) = get<1>(pos_aux);
					get<0>(get<1>(mv)) = i - 1;
					get<1>(get<1>(mv)) = j - 1;

					if(new_map.try_move(mv))
					{ 
						children_[pos].set_bucket(new_map,mv,nullptr); 
						children_[pos].get_map().play(mv,player);
						pos ++;
					}
				}					

				get<0>(get<0>(mv)) = get<0>(pos_aux);
				get<1>(get<0>(mv)) = get<1>(pos_aux);
				get<0>(pos_aux) = get<0>(get<1>(mv)) = i;
				get<1>(pos_aux) = get<1>(get<1>(mv)) = j;

				if(new_map.try_move(mv))
				{	
					children_[pos].set_bucket(new_map,mv,nullptr); 
					children_[pos].get_map().play(mv,player);
					pos ++;
				}
			}

			if (i != 0)
			{
				get<0>(get<0>(mv)) = get<0>(pos_aux);
				get<1>(get<0>(mv)) = get<1>(pos_aux);
				get<0>(get<1>(mv)) = i - 1; 
				get<1>(get<1>(mv)) = get<1>(pos_aux);
				
				if(new_map.try_move(mv))
				{
					children_[pos].set_bucket(new_map,mv,nullptr); 
					children_[pos].get_map().play(mv,player);
					pos ++;
				}
			}					

			get<0>(pos_aux) = i + 1;
			get<1>(pos_aux) = 0;
		}

		return children_;	
	}

	void make_tree(move_bucket<R,C> *root_,const map<R,C> & new_map, 
				   size_t cur_lvl, size_t a_moves_)
	{
		
		if (cur_lvl >= lvl or a_moves_ == 0)	
			return;

		if (cur_lvl % 2 == 0)
			root_->get_children() = gen_children(new_map,1,a_moves_);
		else
			root_->get_children() = gen_children(new_map,2,a_moves_);

	    for (size_t i = 0; i < a_moves_; i++)
			make_tree(&root_->get_children()[i],
			root_->get_children()[i].get_map(),cur_lvl + 1,a_moves_ - 1);

		return;
	}

	void make_decision_tree(const map<R,C> & new_map, const MOVE & new_move)
	{
		set(new_map,new_move);
		make_tree(root,new_map,0,a_moves);

		return;
	}
};