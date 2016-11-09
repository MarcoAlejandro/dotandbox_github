# include <map.H>
# include <tpl_tree_node.H>
#include <iostream>
# define POS pair<size_t,size_t>

bool are_equal_moves(MOVE m1, MOVE m2)
{
	if (get<0>(m1) == get<0>(m2) and get<1>(m1) == get<1>(m2))
		return true;
	if (get<0>(m1) == get<1>(m2) and get<1>(m1) == get<0>(m2))
		return true;

	return false;
}

template <size_t R = 4, size_t C = 4> 
class move_bucket
{

private:

	MOVE actual_move;
	map<R,C> actual_map;
	long utility  = 0;

public:
	
	move_bucket() : actual_move(), actual_map() 
	{
		/*empty*/
	}

	move_bucket(const map<R,C> & new_map, const MOVE & new_move)
	{
		actual_move = new_move;
		actual_map = new_map;
	}

	~move_bucket(){/*empty*/}

	void set_bucket(const map<R,C> & new_map, const MOVE & new_move)
	{
		actual_move = new_move;
		actual_map = new_map;
		return;
	}

	const move_bucket & operator = (const move_bucket & bucket)
	{
		set_bucket(bucket.actual_map,bucket.actual_move);

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
	}

	void reset()
	{
		actual_map.reset();
		get<0>(get<0>(actual_move)) = 0;
		get<1>(get<0>(actual_move)) = 0;
		get<0>(get<1>(actual_move)) = 0;
		get<1>(get<1>(actual_move)) = 0;
	}
};

template <size_t R = 4, size_t C = 4, size_t lvl = 3> 
class decision_node : public Tree_Node<move_bucket<R,C> >
{

public:

	decision_node()
	{
		/*empty*/
	}

	decision_node(const map<R,C> & new_map, const MOVE & new_move)
	{
		this->get_data().set_bucket(new_map,new_move);
	}

	~decision_node()
	{
		
		delete_tree(this);

	}

	void delete_tree(decision_node * root)
	{
		/*if (not is_leftmost_child())
	    SIBLING_LIST(root)->del();*/

	    SIBLING_LIST(root)->del();

	  for (decision_node * p = (decision_node*) root->get_right_child(); p != nullptr; /* nada */)
	    {
	      decision_node * to_delete = p;      // respaldar subárbol a borrar p
	      p = (decision_node*) p->get_left_sibling(); // Avanzar p a hermano izquierdo
	      delete_tree(to_delete);   // eliminar recursivamente árbol
	    }

	  if (root->is_leftmost()) // ¿sacar lista hijos?
	    CHILD_LIST(root)->del(); 

		if (root != this)
			  delete root;
	}

	void set(const map<R,C> & new_map, const MOVE & new_move)
	{
		this->get_data().set_bucket(new_map,new_move);
		return;
	}

	void gen_children(decision_node * root,const map<R,C> & new_map, unsigned short player)
	{
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
						root->insert_leftmost_child(new decision_node<R,C,lvl>(new_map,mv));
						root->get_left_child()->get_data().get_map().play(mv,player);
					}
				}					

				get<0>(get<0>(mv)) = get<0>(pos_aux);
				get<1>(get<0>(mv)) = get<1>(pos_aux);
				get<0>(pos_aux) = get<0>(get<1>(mv)) = i;
				get<1>(pos_aux) = get<1>(get<1>(mv)) = j;

				if(new_map.try_move(mv))
				{
					root->insert_leftmost_child(new decision_node<R,C,lvl>(new_map,mv));
					root->get_left_child()->get_data().get_map().play(mv,player);
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
					root->insert_leftmost_child(new decision_node<R,C,lvl>(new_map,mv));
					root->get_left_child()->get_data().get_map().play(mv,player);
				}
			}					

			get<0>(pos_aux) = i + 1;
			get<1>(pos_aux) = 0;
		}	
	}

	void make_tree(decision_node *root,const map<R,C> & new_map, size_t cur_lvl)
	{
		if (cur_lvl >= lvl)	
			return;

		if (cur_lvl % 2 == 0)
		 	gen_children(root,new_map,1);
		else
			gen_children(root,new_map,2);

	    for (auto itor = root->get_left_child(); itor != nullptr; itor = itor->get_right_sibling())
			make_tree(static_cast<decision_node*>(itor),itor->get_data().get_map(),cur_lvl + 1);

		return;
	}

	void make_decision_tree(const map<R,C> & new_map, const MOVE & new_move)
	{
		this->get_data().set_bucket(new_map,new_move);

		make_tree(this,new_map,0);

		return;
	}

	long get_utility()
	{
		if (this->is_leaf())
			return	this->get_data().get_map().get_p1_score() - this->get_data().get_map().get_p2_score() ;
		else
			return this->get_data().get_utility();
	} 

};